cmake_minimum_required(VERSION 3.4.3)
set(CMAKE_C_COMPILER /home/skhadka/local/bin/clang)
set(CMAKE_CXX_COMPILER /home/skhadka/local/bin/clang++)
set(LLVM_DIR /home/skhadka/local/lib/cmake/llvm)
#set(CLANG_CONFIG_LLVM_DIR /home/skhadka/local/lib/cmake/clang)
#set(CMAKE_MODULE_PATH "/home/skhadka/local/lib/cmake/clang;/home/skhadka/local/lib/cmake/llvm")
project(SimpleProject)

# Need the following to make clangTooling work
find_package(Clang REQUIRED CONFIG PATHS "/home/skhadka/local/lib/cmake/clang" NO_DEFAULT_PATH)
find_package(LLVM REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

message(STATUS "Using ClangConfig.cmake in: ${CLANG_CMAKE_DIR}")


# COMPILE WITH:
# cmake -DCMAKE_C_COMPILER=/home/skhadka/local/bin/clang -DCMAKE_CXX_COMPILER=/home/skhadka/local/bin/clang++ -DLLVM_DIR=~/local/lib/cmake/llvm ../

# Set your project compile flags.
# E.g. if using the C++ header files
# you will need to enable C++11 support
# for your compiler.

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

add_subdirectory(Hello)
add_subdirectory(enum_to_string)

# This is for exe
# Now build our tools
#add_executable(hello Hello.cpp)

# Find the libraries that correspond to the LLVM components
# that we wish to use
# llvm_map_components_to_libnames(llvm_libs support core irreader)

# # Link against LLVM libraries
#target_link_libraries(HelloPass ${llvm_libs})
