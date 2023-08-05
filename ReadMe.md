# MyActuator RMD-X-series CAN driver

Author: [Tobit Flatscher](https://github.com/2b-t) (2023)

[![Tests](https://github.com/2b-t/myactuator_rmd/actions/workflows/run-tests.yml/badge.svg)](https://github.com/2b-t/myactuator_rmd/actions/workflows/run-tests.yml) [![C++17 Standard](https://img.shields.io/badge/Standard-C++17-yellow.svg?style=flat&logo=c%2B%2B)](https://isocpp.org/std/the-standard) [![Python 3](https://img.shields.io/badge/Python-3-yellow.svg?style=flat&logo=python)](https://www.python.org/downloads/) [![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)



## 0. Overview
This repository holds a **CAN driver for the [MyActuator RMD X actuator series](https://www.myactuator.com/rmd-x)** written in modern C++17 using [Linux's SocketCAN](https://docs.kernel.org/networking/can.html). The driver is also exposed to Python through Python bindings generated with [pybind11](https://github.com/pybind/pybind11).



## 1. Installation

This driver requires the **following dependencies** to be installed. For Debian Linux they can be installed through `apt` as follows:

```bash
$ sudo apt-get install -y build-essential cmake
$ sudo apt-get install -y can-utils iproute2 linux-modules-extra-$(uname -r)
```

In case you want to use the Python bindings you will have to additionally install [Python 3](https://www.python.org/downloads/), [pip](https://pypi.org/project/pip/) and [pybind11](https://pybind11.readthedocs.io/en/stable/):

```bash
$ sudo apt-get install -y python3 python3-pip python3-pybind11
```

After having installed its dependencies you will have to install the driver either as a C++ library or Python package as described in the following steps. Both will use CMake to compile the C++ code.



### 1.1 Building the C++ library

For **building the C++ driver** open a new terminal inside this folder and execute the following commands

```bash
$ mkdir build
$ cd build
$ cmake .. -D PYTHON_BINDINGS=on
$ make -j $(nproc)
```

The flag `PYTHON_BINDINGS` (defaults to `off`) builds the Python bindings additionally to the C++ library. In case you are only interested in using the C++ library feel free to leave it off. When building the Python bindings like this they will be compiled to a shared library but not be installed. This means you will either have to install the library manually or you will only be able to import them locally inside the `build` folder. 

### 1.2 Installing Python package

For **building and installing the Python bindings** for this driver open a new terminal inside the main folder and execute the following command:

```bash
$ pip3 install .
```

This will use the `setup.py` to invoke CMake and install the bindings as a C++ library. If you want to remove them again simply invoke `$ pip3 uninstall myactuator_rmd`.



## 2. Using the Python bindings

**Load the library** and continue to create a driver for a particular network interface (here `can0`) and drive (here `1` corresponding to the CAN-address `0x140 + 1 = 0x141`) and control it through the Python API as shown below:

```bash
$ python3
Python 3.10.6 (main, Mar 10 2023, 10:55:28) [GCC 11.3.0] on linux
Type "help", "copyright", "credits" or "license" for more information.
>>> from myactuator_rmd import Driver
>>> driver = Driver("can0", 1)
>>> driver.getVersionDate()
2023020601
>>> driver.sendPositionAbsoluteSetpoint(180.0, 500.0)
>>> driver.shutdownMotor()
```

For more information you might also inspect the contents of the module inside Python 3 with `help(myactuator_rmd)`.



## 3. Automated tests

For testing you will have to install the following additional dependencies

```bash
$ sudo apt-get install -y libboost-all-dev libgmock-dev libgtest-dev
```

The tests can then be build by passing the **additional flag `-D BUILD_TESTING=on`** to CMake. After building the driver with the additional flag you will have to bring the virtual CAN interface up with:

```bash
$ sudo modprobe vcan
$ sudo ip link add dev vcan_test type vcan
$ sudo ip link set up vcan_test
```

Additionally there is a CMake flag `SETUP_TEST_IFNAME` that - if set to `on` - automatically sets up the virtual CAN interface for you but this requires the following command to be run as `sudo`.

Finally you can **launch all the tests** with the following command:

```bash
$ ctest
```
