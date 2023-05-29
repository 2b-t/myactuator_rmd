# See https://answers.ros.org/question/331089/ament_export_dependenciesboost-not-working/?answer=332460#post-id-332460

if(PYTHON_BINDINGS)
  find_package(Python REQUIRED COMPONENTS Interpreter Development)
  find_package(pybind11 CONFIG REQUIRED)
endif()
