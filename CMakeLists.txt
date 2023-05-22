cmake_minimum_required(VERSION 3.20)
project(myactuator_rmd_driver)

option(PYTHON_BINDINGS "PYTHON_BINDINGS" OFF)

if(NOT UNIX)
  message(FATAL_ERROR "Currently this driver only supports Linux operating systems!")
endif()

include(ConfigExtras.cmake)

include_directories(
  include/
)

add_library(myactuator_rmd_driver_obj OBJECT
  src/can/exceptions.cpp
  src/can/frame.cpp
  src/can/interface.cpp
  src/driver.cpp
)
add_library(myactuator_rmd_driver 
  $<TARGET_OBJECTS:myactuator_rmd_driver_obj>
)

set(MYACTUATOR_RMD_DRIVER_LIBRARIES ${Boost_SYSTEM_LIBRARY})
target_link_libraries(myactuator_rmd_driver_obj ${MYACTUATOR_RMD_DRIVER_LIBRARIES})
target_link_libraries(myactuator_rmd_driver ${MYACTUATOR_RMD_DRIVER_LIBRARIES})

if(PYTHON_BINDINGS)
  find_package(Python REQUIRED COMPONENTS Interpreter Development)
  find_package(pybind11 CONFIG REQUIRED)
  pybind11_add_module(pymyactuator_rmd_driver bindings/myactuator_rmd_driver.cpp)
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

