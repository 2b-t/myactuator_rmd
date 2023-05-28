cmake_minimum_required(VERSION 3.20)
project(myactuator_rmd_driver)

option(BUILD_TESTING "Build unit and integration tests" OFF)
option(PYTHON_BINDINGS "Building Python bindings" OFF)

if(NOT UNIX)
  message(FATAL_ERROR "Currently this driver only supports Linux operating systems!")
endif()

include(ConfigExtras.cmake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(
  include/
)

add_library(myactuator_rmd_driver_obj OBJECT
  src/can/node.cpp
  src/can/output.cpp
  src/driver.cpp
)
add_library(myactuator_rmd_driver 
  $<TARGET_OBJECTS:myactuator_rmd_driver_obj>
)

set(MYACTUATOR_RMD_DRIVER_LIBRARIES ${Boost_SYSTEM_LIBRARY})
target_link_libraries(myactuator_rmd_driver ${MYACTUATOR_RMD_DRIVER_LIBRARIES})

add_executable(driver
  $<TARGET_OBJECTS:myactuator_rmd_driver_obj>
  src/main.cpp
)
target_link_libraries(driver ${Boost_PROGRAM_OPTIONS_LIBRARY} myactuator_rmd_driver)

if(PYTHON_BINDINGS)
  set(CMAKE_CXX_FLAGS " ${CMAKE_CXX_FLAGS_INIT} -fPIC")
  pybind11_add_module(pymyactuator_rmd_driver bindings/myactuator_rmd_driver.cpp)
  target_link_libraries(pymyactuator_rmd_driver PRIVATE myactuator_rmd_driver)
  set_target_properties(pymyactuator_rmd_driver PROPERTIES OUTPUT_NAME myactuator_rmd_driver)
endif()

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
  enable_testing()
  include(GoogleTest)
  if (NOT GTest_FOUND)
    set(MYACTUATOR_RMD_DRIVER_TEST_LIBRARIES ${MYACTUATOR_RMD_DRIVER_LIBRARIES} gmock gtest pthread)

    add_library(myactuator_rmd_driver_test_obj OBJECT
      test/actuator_adaptor.cpp
      test/actuator_mock.cpp
    )
    add_executable(run_tests
      $<TARGET_OBJECTS:myactuator_rmd_driver_obj>
      $<TARGET_OBJECTS:myactuator_rmd_driver_test_obj>
      test/run_tests.cpp
    )

    target_compile_definitions(run_tests PUBLIC NDEBUG)

    gtest_discover_tests(run_tests
      TEST_SUFFIX .noArgs
      TEST_LIST noArgsTests
    )
    set_tests_properties(${noArgsTests} PROPERTIES TIMEOUT 10)

    target_link_libraries(myactuator_rmd_driver_test_obj ${MYACTUATOR_RMD_DRIVER_TEST_LIBRARIES})
    target_link_libraries(run_tests ${MYACTUATOR_RMD_DRIVER_TEST_LIBRARIES})
  else()
    message(WARNING "GoogleTest not found!")
  endif()
endif()

if(ament_cmake_FOUND)
  ament_package(CONFIG_EXTRAS ConfigExtras.cmake)
endif()

