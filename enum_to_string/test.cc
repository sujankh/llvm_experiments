// VIEW AST
// /home/skhadka/local/bin/clang -Xclang -ast-dump -fsyntax-only test.cc
// Another way to viz:
// /home/skhadka/local/bin/clang -cc1 -ast-view test.cc

//#MAKE MAP
enum TestEnum {
    APPLE=5,
    BANANA
};

void foo()
{

}

int test()
{
    return -1;
}


class Foo
{

};