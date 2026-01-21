cmake_minimum_required(VERSION 3.28)
project(modlib VERSION 0.0.2)

add_library(modlib)
target_compile_features(modlib PRIVATE cxx_std_23)
target_compile_definitions(modlib PRIVATE lmao)

add_subdirectory(src)

include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

install(
  TARGETS modlib
  EXPORT modlib-targets
  FILE_SET CXX_MODULES
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/modlib
  FILE_SET HEADERS
)

install(
  PACKAGE_INFO modlib
  EXPORT modlib-targets
  DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/modlib
  CXX_MODULES_DIRECTORY modlib-cxx-modules
)

write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/modlib-config-version.cmake
  COMPATIBILITY SameMajorVersion
  ARCH_INDEPENDENT
)
