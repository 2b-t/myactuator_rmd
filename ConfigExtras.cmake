# See https://answers.ros.org/question/331089/ament_export_dependenciesboost-not-working/?answer=332460#post-id-332460
find_package(ament_cmake)
if (ament_cmake_FOUND)
message(STATUS "Ament CMake detected.")
else ()
  message(WARNING "Ament CMake not found!")
endif()

find_package(Boost 1.40.0 REQUIRED COMPONENTS system thread)
if (NOT Boost_FOUND)
  message(FATAL_ERROR "Boost libraries not found!")
else()
  message(STATUS "Boost version " ${Boost_VERSION} " detected.")
endif()

