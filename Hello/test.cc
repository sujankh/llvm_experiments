// VIEW AST
// /home/skhadka/local/bin/clang -Xclang -ast-dump -fsyntax-only test.cc
// Another way to viz:
// /home/skhadka/local/bin/clang -cc1 -ast-view test.cc

//#MAKE MAP
#include <bits/stdint-uintn.h>

enum class TestEnum : uint8_t {
    APPLE=5,
    BANANA,
    CAT,
    LYCHEE
};

enum MyEnum{
    A=1,
    B,
    C,
    D
};


//#include "TestEnumString.hh"

void foo()
{
    //assert(TestEnumToString(TestEnum.APPLE) == "APPLE")
}

int test()
{
    return -1;
}


class Foo
{

};