list(APPEND CMAKE_MODULE_PATH "${LLVM_CMAKE_DIR}")
include(AddLLVM)

# Note: add_clang_executable failed horribly since AddClang did not work
add_llvm_executable(visitor
  visitor.cc
  )

# NOTE: This fails if i don't put PRIVATE with a weird error
target_link_libraries(visitor PRIVATE clangTooling)
