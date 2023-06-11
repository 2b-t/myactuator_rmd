# MyActuator RMD-series CAN driver

Author: [Tobit Flatscher](https://github.com/2b-t) (May - June 2023)

[![Tests](https://github.com/2b-t/myactuator_rmd/actions/workflows/run-tests.yml/badge.svg)](https://github.com/2b-t/myactuator_rmd/actions/workflows/run-tests.yml) [![C++17 Standard](https://img.shields.io/badge/Standard-C++17-yellow.svg?style=flat&logo=c%2B%2B)](https://isocpp.org/std/the-standard) [![Python 3](https://img.shields.io/badge/Python-3-yellow.svg?style=flat&logo=python)](https://www.python.org/downloads/) [![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)



## 0. Overview
This repository holds a **CAN driver for the [MyActuator RMD actuator series](https://www.myactuator.com/rmd-x)** written in modern C++17 using [Linux's SocketCAN](https://docs.kernel.org/networking/can.html). The driver is also exposed to Python through Python bindings generated with [pybind11](https://github.com/pybind/pybind11).

This driver is currently work in progress: It supports closed-loop position, velocity and torque control but does not allow to change the PID paramters yet.



## 1. Building

For building this driver open a new terminal inside this folder and execute the following commands

```bash
$ mkdir build
$ cd build
$ cmake .. -D PYTHON_BINDINGS=on
$ make -j $(nproc)
```

The flag `PYTHON_BINDINGS` (defaults to `off`) builds the Python bindings additionally to the C++ library. In case you are only interested in using the C++ library feel free to leave it off.



## 2. Using the Python bindings

For importing the Python bindings open a new terminal inside the `build` folder after having build the driver. Load the library and continue to create a driver for a particular network interface and drive and control it through the Python API.

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



## 3. Automated tests

The tests can be build by passing the additional flag `-D BUILD_TESTING=on` to CMake. After building the driver with the additional flag you will have to bring the virtual CAN interface up with:

```bash
$ sudo modprobe vcan
$ sudo ip link add dev vcan_test type vcan
$ sudo ip link set up vcan_test
```

Additionally there is a flag `SETUP_TEST_IFNAME` that - if set to `on` - automatically sets up the virtual CAN interface for you but this requires the following command to be run as `sudo`.

Finally you can launch the test with the following command:

```bash
$ ctest
```
