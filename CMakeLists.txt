cmake_minimum_required(VERSION 3.20)
project(myactuator_rmd_driver)

option(PYTHON_BINDINGS "Building Python bindings" OFF)
option(BUILD_TESTING "Build unit and integration tests" OFF)
option(SETUP_TEST_IFNAME "Set-up the test VCAN interface automatically" OFF)

if(NOT UNIX)
  message(FATAL_ERROR "Currently this driver only supports Linux!")
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(ament_cmake)
if(ament_cmake_FOUND)
  message(STATUS "Ament CMake detected.")
else()
  message(WARNING "Ament CMake not found!")
endif()
include(ConfigExtras.cmake)

include_directories(
  include/
)

add_library(myactuator_rmd_driver_obj OBJECT
  src/can/node.cpp
  src/can/utilities.cpp
  src/messages/requests/set_position_absolute_request.cpp
  src/messages/responses/feedback_response.cpp
  src/messages/responses/shutdown_motor_response.cpp
  src/messages/responses/stop_motor_response.cpp
  src/messages/responses/version_date_response.cpp
  src/driver.cpp
)
add_library(myactuator_rmd_driver 
  $<TARGET_OBJECTS:myactuator_rmd_driver_obj>
)

set(MYACTUATOR_RMD_DRIVER_LIBRARIES ${Boost_SYSTEM_LIBRARY})
target_link_libraries(myactuator_rmd_driver ${MYACTUATOR_RMD_DRIVER_LIBRARIES})

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
    find_package(Boost 1.40.0 REQUIRED COMPONENTS program_options)
    add_executable(can_node
      $<TARGET_OBJECTS:myactuator_rmd_driver_obj>
      test/can_node.cpp
    )
    target_link_libraries(can_node ${Boost_PROGRAM_OPTIONS_LIBRARY} myactuator_rmd_driver)

    set(MYACTUATOR_RMD_DRIVER_TEST_LIBRARIES ${MYACTUATOR_RMD_DRIVER_LIBRARIES} gmock gtest pthread)
    add_library(myactuator_rmd_driver_test_obj OBJECT
      test/can/utilities_test.cpp
      test/messages/requests/set_position_absolute_request_test.cpp
      test/messages/responses/set_position_absolute_response_test.cpp
      test/mock/actuator_adaptor.cpp
      test/mock/actuator_mock.cpp
      test/mock/driver_actuator_test.cpp
      test/driver_test.cpp
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
    target_link_libraries(run_tests ${MYACTUATOR_RMD_DRIVER_TEST_LIBRARIES})
    if (SETUP_TEST_IFNAME)
      set(VCAN_IFNAME "vcan_test")
      configure_file("CTestCustom.cmake.in" ${CMAKE_BINARY_DIR}/CTestCustom.cmake)
    endif()
  else()
    message(WARNING "GoogleTest not found!")
  endif()
endif()

if(ament_cmake_FOUND)
  ament_package(CONFIG_EXTRAS ConfigExtras.cmake)
endif()
