cmake_minimum_required(VERSION 3.27)
set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API "aa1f7df0-828a-4fcd-9afc-2dc80491aca7")
set(CMAKE_EXPERIMENTAL_CXX_MODULE_DYNDEP 1)

project(modlib VERSION 0.0.1)

add_library(modlib)
target_compile_features(modlib PUBLIC cxx_std_23)
set_target_properties(modlib PROPERTIES CXX_EXTENSIONS OFF)

add_executable(test)
target_compile_features(test PRIVATE cxx_std_23)
set_target_properties(test PROPERTIES CXX_EXTENSIONS OFF)
target_link_libraries(test PRIVATE modlib)

add_subdirectory(src)

include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

install(
  TARGETS modlib
  EXPORT modlib-targets
  FILE_SET CXX_MODULES
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/modlib
)
install(
  EXPORT modlib-targets
  NAMESPACE modlib::
  CXX_MODULES_DIRECTORY modlib-cxx-modules
  DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/modlib
)

write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/modlib-config-version.cmake
  COMPATIBILITY SameMajorVersion
  ARCH_INDEPENDENT
)

install(FILES
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake/modlib-config.cmake
  ${CMAKE_CURRENT_BINARY_DIR}/modlib-config-version.cmake
  DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/modlib
)
