list(APPEND CMAKE_MODULE_PATH "${LLVM_CMAKE_DIR}")
include(AddLLVM)  # Corresponds to /home/skhadka/local/lib/cmake/llvm/AddLLVM.cmake

# Note: add_clang_executable failed horribly since AddClang did not work
add_llvm_executable(enum_to_str
  enum_to_str.cc
  )

# NOTE: This fails if i don't put PRIVATE/PUBLIC with an error
target_link_libraries(enum_to_str PRIVATE clangTooling)
