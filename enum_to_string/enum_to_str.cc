#include "clang/AST/ASTConsumer.h"
#include "clang/AST/Decl.h"
#include "clang/AST/DeclBase.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Frontend/FrontendAction.h"
#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/Tooling/Tooling.h"
#include "llvm/ADT/StringRef.h"
#include <iostream>
#include <memory>

// Need to generate this code (possibly constexpr) for MyEnum and any of its values
// 
// template <MyEnum e>
// constexpr const char* getString()
// {
//     if constexpr(e == MyEnum::Apple)
//     {
//         return "Apple";
//     }
//     else
//     {
//         return "Ball";
//     }
// }  


// Thanks to https://clang.llvm.org/docs/RAVFrontendAction.html
// and http://clang.llvm.org/docs/LibASTMatchersTutorial.html

class FindNamedClassVisitor
    : public clang::RecursiveASTVisitor<FindNamedClassVisitor> {
public:
  explicit FindNamedClassVisitor(clang::ASTContext *context)
      : context_(context) {}

  bool VisitEnumDecl(clang::EnumDecl *Declaration) {
    const auto enum_name = Declaration->getQualifiedNameAsString();
    std::cout << enum_name << std::endl;

    if (enum_name == "TestEnum") {
      for (const auto x : Declaration->enumerators()) {
        // std::cout << x->getQualifiedNameAsString() << std::endl;
        std::cout << x->getName().str() << " --> "
                  << x->getInitVal().toString(10) << std::endl;

        // std::cout << "getName: " << x->getName().str() << std::endl;
      }
    }
  //context_->getTranslationUnitDecl()
    return true;
  }

private:
  clang::ASTContext *context_;
};

class MyASTConsumer : public clang::ASTConsumer {
public:
  explicit MyASTConsumer(clang::ASTContext *Context) : Visitor(Context) {}

  virtual void HandleTranslationUnit(clang::ASTContext &Context) {
    std::cout << "Handle TU " << std::endl;
    Visitor.TraverseDecl(Context.getTranslationUnitDecl());
  }

private:
  FindNamedClassVisitor Visitor;
};

class MyFrontend : public clang::ASTFrontendAction {
public:
  virtual std::unique_ptr<clang::ASTConsumer>
  CreateASTConsumer(clang::CompilerInstance &Compiler, llvm::StringRef InFile) {
    std::cout << "CreateASTConsumer " << InFile.str() << std::endl;
    return std::make_unique<MyASTConsumer>(&Compiler.getASTContext());
  }
};

static llvm::cl::OptionCategory MyToolCategory("visitor options");
static llvm::cl::extrahelp
    CommonHelp(clang::tooling::CommonOptionsParser::HelpMessage);
// static llvm::cl::extrahelp MoreHelp("More help here");

int main(int argc, const char **argv) {
  clang::tooling::CommonOptionsParser OptionsParser(argc, argv, MyToolCategory);
  clang::tooling::ClangTool Tool(OptionsParser.getCompilations(),
                                 OptionsParser.getSourcePathList());
  return Tool.run(clang::tooling::newFrontendActionFactory<MyFrontend>().get());
}