cmake_minimum_required(VERSION 3.12.0)
project(demodemo)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_BINARY_DIR}")
include(conan.cmake)
conan_cmake_run(
  CONANFILE conanfile.txt
  BASIC_SETUP
  NO_OUTPUT_DIRS
  CMAKE_TARGETS
  CONFIGURATION_TYPES "Release;Debug;RelWithDebInfo")

get_property(_isMultiConfig GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)
if(_isMultiConfig)
  include(${CMAKE_BINARY_DIR}/conanbuildinfo_multi.cmake)
  set(_FP_TYPE "CONFIG")
else(_isMultiConfig)
  include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
  set(_FP_TYPE "")
endif(_isMultiConfig)


find_package(GTEST ${_FP_TYPE})
if(GTest_FOUND)
  message("XXXX: GTEST FOUND")
else(GTest_FOUND)
  message("YYYY: GTEST NOOOOOOOOOOT FOUND")
endif(GTest_FOUND)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} ${GTest_LIBRARIES})
target_include_directories(${PROJECT_NAME} PRIVATE ${GTest_INCLUDES})

get_target_property(OUT CONAN_PKG::gtest  INTERFACE_LINK_LIBRARIES)
message(STATUS ${OUT})
