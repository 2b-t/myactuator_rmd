# MyActuator RMD X-series CAN driver SDK

Author: [Tobit Flatscher](https://github.com/2b-t) (2023 - 2024)

[![Tests](https://github.com/2b-t/myactuator_rmd/actions/workflows/run-tests.yml/badge.svg)](https://github.com/2b-t/myactuator_rmd/actions/workflows/run-tests.yml) [![codecov](https://codecov.io/gh/2b-t/myactuator_rmd/graph/badge.svg?token=VSDNKL4G4W)](https://codecov.io/gh/2b-t/myactuator_rmd) [![Codacy Badge](https://app.codacy.com/project/badge/Grade/ab6c938baaac477e98c69cdf84d61420)](https://app.codacy.com/gh/2b-t/myactuator_rmd/dashboard?utm_source=gh&utm_medium=referral&utm_content=&utm_campaign=Badge_grade) [![C++17 Standard](https://img.shields.io/badge/Standard-C++17-yellow.svg?style=flat&logo=c%2B%2B)](https://isocpp.org/std/the-standard) [![Python 3](https://img.shields.io/badge/Python-3-yellow.svg?style=flat&logo=python)](https://www.python.org/downloads/) [![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)



## 0. Overview
This repository holds a **CAN driver software development kit** (SDK) for the [**MyActuator RMD X actuator series**](https://www.myactuator.com/rmd-x) written in modern C++17 using [Linux's SocketCAN](https://docs.kernel.org/networking/can.html). The driver SDK is also exposed to Python through Python bindings generated with [pybind11](https://github.com/pybind/pybind11).

For the [`ros2_control` integration](https://control.ros.org/humble/index.html) please refer to [this repository](https://github.com/2b-t/myactuator_rmd_ros).



## 1. Installation

This driver SDK requires the **following dependencies** to be installed. For Debian Linux they can be installed through `apt` as follows:

```bash
$ sudo apt-get install -y build-essential cmake
$ sudo apt-get install -y can-utils iproute2 linux-modules-extra-$(uname -r)
```

In case you want to use the Python bindings you will have to additionally install [Python 3](https://www.python.org/downloads/), [pip](https://pypi.org/project/pip/) and [pybind11](https://pybind11.readthedocs.io/en/stable/):

```bash
$ sudo apt-get install -y python3 python3-pip python3-pybind11 python3-setuptools
```

After having installed its dependencies you will have to install the driver SDK either as a C++ library or Python package as described in the following steps. Both will use CMake to compile the C++ code.



### 1.1 Building the C++ library

For **building the C++ driver SDK** open a new terminal inside this folder and execute the following commands. On older versions of Linux the build might fail with the error message `error: 'const struct can_frame' has no member named 'len'` and you will have to apply the code modification discussed in [issue #5](https://github.com/2b-t/myactuator_rmd/issues/5).

```bash
$ mkdir build
$ cd build
$ cmake .. -D PYTHON_BINDINGS=on
$ make -j $(nproc)
$ sudo make install
```

The flag `PYTHON_BINDINGS` (defaults to `off`) builds the Python bindings additionally to the C++ library. In case you are only interested in using the C++ library feel free to leave it off. When building the Python bindings like this they will be compiled to a shared library but not be installed. This means you will either have to install the library manually or you will only be able to import them locally inside the `build` folder.

For uninstalling the package again you can use [the following command](https://gitlab.kitware.com/cmake/community/-/wikis/FAQ#can-i-do-make-uninstall-with-cmake) `$ xargs rm < install_manifest.txt`.

### 1.2 Installing Python package

For **building and installing the Python bindings** for this SDK open a new terminal inside the main folder and execute the following command:

```bash
$ pip3 install .
```

This will use the `setup.py` to invoke CMake and install the bindings as a C++ library. If you want to remove them again simply invoke `$ pip3 uninstall myactuator-rmd-py`.

### 1.3 Building with ROS 2

For **building and installing this package with ROS 2** open a new terminal on then top-level folder of your Colcon workspace (e.g. `colcon_ws`) and execute the following command:

```bash
$ colcon build --cmake-args -D PYTHON_BINDINGS=on -D BUILD_TESTING=on
```

where the two flags following `--cmake-args` are optional.



## 2. Using the C++ library

In case Ament is installed on your system but you want to install the package with CMake only, please make sure that your ROS 2 workspace was not sourced before running the installation.

In your CMake package you can then find the package and link to it as follows:

```cmake
cmake_minimum_required(VERSION 3.20)
project(your_project)

find_package(myactuator_rmd REQUIRED)

add_executable(your_node
  src/main.cpp
)
target_compile_features(your_node PUBLIC
  cxx_std_17
)
target_link_libraries(your_node PUBLIC
  myactuator_rmd::myactuator_rmd
)
```

A minimal example for the `main.cpp` can be found below:

```c++
#include <cstdlib>
#include <iostream>

#include <myactuator_rmd/myactuator_rmd.hpp>


int main() {
  myactuator_rmd::CanDriver driver {"can0"};
  myactuator_rmd::ActuatorInterface actuator {driver, 1};

  std::cout << actuator.getVersionDate() << std::endl;
  std::cout << actuator.sendPositionAbsoluteSetpoint(180.0, 500.0) << std::endl;
  actuator.shutdownMotor();
  return EXIT_SUCCESS;
}
```



## 3. Using the Python bindings

**Load the library** and continue to create a driver for a particular network interface (here `can0`) and drive (here `1` corresponding to the CAN-address `0x140 + 1 = 0x141`) and control it through the Python API as shown below:

```bash
$ python3
Python 3.10.6 (main, Mar 10 2023, 10:55:28) [GCC 11.3.0] on linux
Type "help", "copyright", "credits" or "license" for more information.
>>> import myactuator_rmd_py as rmd
>>> driver = rmd.CanDriver("can0")
>>> actuator = rmd.ActuatorInterface(driver, 1)
>>> actuator.getVersionDate()
2023020601
>>> actuator.sendPositionAbsoluteSetpoint(180.0, 500.0)
temperature: 19, current: 0.1, shaft speed: 1, shaft angle: 0
>>> actuator.shutdownMotor()
```

In case you installed the package through ROS 2 the shared library will be located inside the `myactuator_rmd` package. Therefore you will need to import it with `import myactuator_rmd.myactuator_rmd_py as rmd`.

For more information you might also inspect the contents of the module inside Python 3 with `help(myactuator_rmd_py)`.



## 4. Automated tests

For testing you will have to install the following additional dependencies

```bash
$ sudo apt-get install -y libboost-all-dev libgmock-dev libgtest-dev
```

The tests can then be build by passing the **additional flag `-D BUILD_TESTING=on`** to CMake. After building the driver SDK with the additional flag you will have to bring the virtual CAN interface up with:

```bash
$ sudo modprobe vcan
$ sudo ip link add dev vcan_test type vcan
$ sudo ip link set up vcan_test
```

Additionally there is a CMake flag `SETUP_TEST_IFNAME` that - if set to `on` - automatically sets up the virtual CAN interface for you but this requires the following command to be run as `sudo`. Finally for coverage reports with GCC you might use the flag `ENABLE_COVERAGE` but this will compile the code without optimizations.

Finally you can **launch all the tests** with the following command:

```bash
$ ctest
```
