cmake_minimum_required(VERSION 3.4.3)

# Hard code path to your local llvm/clang installation
# Or COMPILE WITH:
# cmake -DCMAKE_C_COMPILER=/home/skhadka/local/bin/clang -DCMAKE_CXX_COMPILER=/home/skhadka/local/bin/clang++ -DLLVM_DIR=~/local/lib/cmake/llvm ../

set(CMAKE_C_COMPILER /home/skhadka/local/bin/clang)
set(CMAKE_CXX_COMPILER /home/skhadka/local/bin/clang++)
set(LLVM_DIR /home/skhadka/local/lib/cmake/llvm)

project(EnumToString)

# Need the following to make clangTooling work
find_package(Clang REQUIRED CONFIG PATHS "/home/skhadka/local/lib/cmake/clang" NO_DEFAULT_PATH)
find_package(LLVM REQUIRED CONFIG)
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")
message(STATUS "Using ClangConfig.cmake in: ${CLANG_CMAKE_DIR}")

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

add_subdirectory(enum_to_string)
