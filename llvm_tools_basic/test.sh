#!/bin/bash

/home/skhadka/local/bin/clang -O3 -emit-llvm simple.cc -c -o simple.bc
/home/skhadka/local/bin/lli ./simple.bc
