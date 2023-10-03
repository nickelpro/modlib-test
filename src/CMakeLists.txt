add_subdirectory(lib)

if(BUILD_TESTS)
  add_executable(test)
  target_compile_features(test PRIVATE cxx_std_23)
  set_target_properties(test PROPERTIES CXX_EXTENSIONS OFF)
  target_link_libraries(test PRIVATE modlib)
endif()
