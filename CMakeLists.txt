cmake_minimum_required(VERSION 3.20)
project(myactuator_rmd VERSION 0.0.1)

option(PYTHON_BINDINGS "Building Python bindings" OFF)
option(BUILD_TESTING "Build unit and integration tests" OFF)
option(SETUP_TEST_IFNAME "Set-up the test VCAN interface automatically" OFF)

if (CMAKE_COMPILER_IS_GNUCC)
  option(ENABLE_COVERAGE "Enable coverage reporting for GCC/Clang" OFF)

  if (ENABLE_COVERAGE)
    message(STATUS "Building with coverage reporting for GCC/Clang.")
    add_compile_options(--coverage -O0)
    link_libraries(--coverage)
  endif()
endif()

if(NOT UNIX)
  message(FATAL_ERROR "Currently this driver only supports Linux!")
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(ament_cmake QUIET)
if(ament_cmake_FOUND)
  message(STATUS "Ament CMake detected.")
endif()

add_library(myactuator_rmd SHARED
  src/can/node.cpp
  src/can/utilities.cpp
  src/protocol/requests.cpp
  src/protocol/responses.cpp
  src/driver.cpp
)
target_include_directories(myactuator_rmd PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)
set(MYACTUATOR_RMD_LIBRARIES "")
target_link_libraries(myactuator_rmd ${MYACTUATOR_RMD_LIBRARIES})
install(
  DIRECTORY include/
  DESTINATION include/
)
install(TARGETS myactuator_rmd
  EXPORT ${PROJECT_NAME}Targets
  RUNTIME DESTINATION bin
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
)

if(PYTHON_BINDINGS)
  find_package(Python REQUIRED COMPONENTS Interpreter Development)
  find_package(pybind11 CONFIG REQUIRED)

  pybind11_add_module(myactuator_rmd_py
    bindings/myactuator_rmd.cpp
  )
  target_link_libraries(myactuator_rmd_py PUBLIC
    myactuator_rmd
  )
  if(ament_cmake_FOUND)
    find_package(ament_cmake_python REQUIRED)
    ament_python_install_package(${PROJECT_NAME})
  endif()
  install(TARGETS myactuator_rmd_py
    DESTINATION ${PYTHON_INSTALL_DIR}/${PROJECT_NAME}
  )
endif()

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
  enable_testing()

  find_package(Boost 1.40.0 QUIET COMPONENTS program_options)
  if (Boost_PROGRAM_OPTIONS_FOUND)
    add_executable(can_node
      test/can_node.cpp
    )
    target_link_libraries(can_node ${Boost_PROGRAM_OPTIONS_LIBRARY} myactuator_rmd)
  endif()

  find_package(GTest REQUIRED)
  add_executable(run_tests
    test/can/utilities_test.cpp
    test/protocol/requests_test.cpp
    test/protocol/responses_test.cpp
    test/mock/actuator_adaptor.cpp
    test/mock/actuator_mock.cpp
    test/mock/driver_actuator_test.cpp
    test/driver_test.cpp
    test/run_tests.cpp
  )
  target_compile_definitions(run_tests PUBLIC NDEBUG)
  set(MYACTUATOR_RMD_TEST_LIBRARIES myactuator_rmd GTest::gmock GTest::gtest pthread)
  target_link_libraries(run_tests ${MYACTUATOR_RMD_TEST_LIBRARIES})
  gtest_discover_tests(run_tests
    TEST_SUFFIX .noArgs
    TEST_LIST noArgsTests
  )
  set_tests_properties(${noArgsTests} PROPERTIES TIMEOUT 10)

  if (SETUP_TEST_IFNAME)
    set(VCAN_IFNAME "vcan_test")
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/CTestCustom.cmake.in ${CMAKE_BINARY_DIR}/CTestCustom.cmake)
  endif()
endif()

if(ament_cmake_FOUND)
  ament_export_targets(${PROJECT_NAME}Targets HAS_LIBRARY_TARGET)
  ament_package()
else()
  include(GNUInstallDirs)
  set(INSTALL_CMAKE_CONFIG_DIR ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME})

  install(EXPORT ${PROJECT_NAME}Targets
    NAMESPACE ${PROJECT_NAME}::
    FILE ${PROJECT_NAME}Targets.cmake
    DESTINATION ${INSTALL_CMAKE_CONFIG_DIR}
  )
  include(CMakePackageConfigHelpers)
  configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/Config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
    INSTALL_DESTINATION ${INSTALL_CMAKE_CONFIG_DIR}
    NO_SET_AND_CHECK_MACRO
    NO_CHECK_REQUIRED_COMPONENTS_MACRO
  )
  write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
  )
  install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
    DESTINATION ${INSTALL_CMAKE_CONFIG_DIR}
  )
endif()
