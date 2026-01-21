add_subdirectory(lib)

if(BUILD_TESTS)
  add_executable(test)
  target_sources(test PRIVATE main.cpp)
  target_compile_features(test PRIVATE cxx_std_23)
  target_link_libraries(test PRIVATE modlib)
endif()
