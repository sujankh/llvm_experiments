list(APPEND CMAKE_MODULE_PATH "${LLVM_CMAKE_DIR}")
include(AddLLVM)   # For add_llvm_library

add_llvm_library( LLVMHello MODULE
  Hello.cpp

  DEPENDS
  intrinsics_gen
  PLUGIN_TOOL
  opt
  )

  # This is for exe
# Now build our tools
#add_executable(hello Hello.cpp)

# Find the libraries that correspond to the LLVM components
# that we wish to use
# llvm_map_components_to_libnames(llvm_libs support core irreader)

# # Link against LLVM libraries
#target_link_libraries(HelloPass ${llvm_libs})
