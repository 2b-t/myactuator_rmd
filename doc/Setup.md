# MyActuator RMD set-up

Author: [Tobit Flatscher](https://github.com/2b-t) (May 2023)



## 0. Connecting to CAN
The actuator will require a **24-48V power supply** able to deliver **at least 5A**. I am using a [generic Chinese 48V 10A (480W) S-480-48 power supply from Amazon](https://www.amazon.co.uk/dp/B084KYD2TL). I simply modified a [socket extension lead](https://www.amazon.co.uk/dp/B0839VFYG9) and attached it to the power outlet and connected the actuator through a [XT30 connector](https://www.amazon.co.uk/dp/B07PC1YKVW).

You can communicate with the drive through [**Controller Area Network (CAN bus)**](https://en.wikipedia.org/wiki/CAN_bus), a communciations network standard commonly found in automation. For a more detailed brief introduction refer to [this article](https://www.autopi.io/blog/can-bus-explained/). What should be noted is that every CAN network should be [terminated with a 120 Ohm resistor](https://help.emtronaustralia.com.au/emtune/Newtopic446.html) at each end of the bus.

There are several ways to enable a computer to communicate with other devices over CAN:

- Some **embedded computing boards** such as some of the [Nvidia Jetson boards](https://docs.nvidia.com/jetson/archives/r34.1/DeveloperGuide/text/HR/ControllerAreaNetworkCan.html) already come with integrated CAN controllers. It is sufficient to [install a CAN transceiver](https://medium.com/@ramin.nabati/enabling-can-on-nvidia-jetson-xavier-developer-kit-aaaa3c4d99c9) (that can be had for around 10 USD) and you are ready to go.
- For other small single-board computers such as the Raspberry PI one can find simple **extension shields** such as [this one](https://wiki.seeedstudio.com/2-Channel-CAN-BUS-FD-Shield-for-Raspberry-Pi/). They will set you back between 50-70 USD.
- There are **PCI Express cards** for desktop computers such as the ones [offered by National Instruments](https://www.ni.com/en-gb/shop/hardware/products/can-interface-device.html) but these tend to be quite expensive (in the range of 1000-2000 USD new).
- Finally there are small and cost effective **USB to CAN adapters**, such as the [open-source USB to CAN adapter CANable](https://canable.io/). These may cost between 10 and 200 USD and have the advantage that they can be used with desktop computers, notebooks as well as single-board computers.

### 0.1 CANable USB to CAN adapter

The [CANable USB to CAN adapter](https://canable.io/) is a low-cost open-source USB to CAN adapter. You can buy them either [here](https://openlightlabs.com/) or find cheap Chinese copies on [Aliexpress](https://www.aliexpress.com/item/1005004004816250.html). I bought one of the Chinese copies by Makerbase MKS. The corresponding [documentaton](https://github.com/makerbase-mks/CANable-MKS) as well as [short video discussing the set-up](https://www.youtube.com/watch?v=hAbQGhgenYg) can be found online.

Theoretically these adapters should **work out of the box**: It should be sufficient to connect the actuator to the **CAN port** (with the jumper on in order to activate the terminating resistor) and the board over the **USB** to your computer.
Depending on your set-up you might have to flash the firmware. There are several [different firmwares](https://canable.io/updater/canable1.html) available (I am using Candlelight with my board) that one can choose from. In order to be able to flash a new firmware onto the board depending on the version one will have to move a switch or jumper on the board to a specific position. On my MKS CANable PRO this is done by placing a jumper on the [two pins labelled BOOT](https://ae01.alicdn.com/kf/S8ec7e0e47081412e8a60ab634f1b06b8w.jpg).



## 1. Configuring the actuator

The configuration procedure is discussed in [this video by the company](https://www.youtube.com/watch?v=N-668lRZCoA). Additional downloads can be found on [their webpage](https://www.myactuator.com/dowload). The actuator can be optionally configured over an UART serial port connection that comes with it. The configuration GUI, called [**Assistant 3.0**](https://www.myactuator.com/_files/archives/cab28a_113101870399481d883002e1751fdcbc.rar) is sadly only available for **Windows**. Through it one can configure the actuator addres as well as the baud rate.



## 2. Testing the actuator

Under Linux we can use [SocketCAN](https://www.kernel.org/doc/html/v5.9/networking/can.html) as part of the Linux kernel for communicating with the actuator. Examples written in C displaying its usage, including receive filters, can be found [here](https://github.com/craigpeacock/CAN-Examples). Additionally there are command line tools available for it, the [**SocketCAN command line tools**](https://github.com/linux-can/can-utils), that on Ubuntu can be installed with `sudo apt-get install can-utils`. An introduction to them can be found [here](https://blog.mbedded.ninja/programming/operating-systems/linux/how-to-use-socketcan-with-the-command-line-in-linux/) as well as [here](https://sgframework.readthedocs.io/en/latest/cantutorial.html).

After having connected your actuator through the USB adapter you should be able to see it with

```bash
$ ip link show
```

In my case this outputs a device `can0` of the type `link/can`.

Then continue to **configure the CAN interface** with

```bash
$ sudo ip link set can0 up type can bitrate 500000
```

where the interface name (in our case `can0`) must correspond to the previously outputted one and the baud rate has to correspond to the one configured for your drive through the Assistant 3.0 GUI previously.

Finally you can **send commands** to the corresponding CAN device, specifying its **hexadecimal address** (again configured in the Assistant 3.0, in my case `141`) and the **command**. The following command will send the actuator to the 360 degree position

```bash
$ cansend can0 141#a400f401a08c0000
```

Similarly 

```bash
$ cansend can0 141#a400f40100000000
```

will move the actuator back to 0 degrees.

In case the actuator does not move but it is vibrating it might be that it is already on the corresponding position. If it does not even vibrate, it might be that you send the command to the wrong address. You might want to use [Wireshark](https://www.wireshark.org/) or `candump` to see what the error message was returned. An introductory guide to debugging traffic with Wireshark can be found [here](https://kentindell.github.io/2021/01/02/can2-wireshark/) and a list of corresponding filters is available [here](https://www.wireshark.org/docs/dfref/c/can.html).

Finally we can bring the interface down again with

```bash
$ sudo ip link set can0 down
```

Alternatively to the SocketCAN command line tools you might use a graphic user interfaces such as [cangaroo](https://github.com/normaldotcom/cangaroo). In order to build cangaroo on Linux you might need to build it as well as `canifconfig` located in the corresponding subfolder and copy both to `/usr/bin`. For any issues that you might encounter refer to the [repository's issues](https://github.com/normaldotcom/cangaroo/issues?q=) as well as the [issue of the original repository](https://github.com/HubertD/cangaroo/issues?q=).



## 3. Debugging this driver

For testing purposes SocketCAN also supports [a virtual CAN driver](https://www.kernel.org/doc/Documentation/networking/can.txt). It can be enabled with

```bash
$ sudo modprobe vcan
$ sudo ip link add dev vcan0 type vcan
$ sudo ip link set up vcan0
```

where `vcan0` is the name of the virtual CAN device.

Finally you can test the virtual CAN interface `vcan0` by opening two terminals, one for monitoring the received data

```bash
$ cansniffer vcan0
```

and the other for sending it

```bash
$ cansend vcan0 141#a400f40100000000
```

This feature is used for unit testing of this driver.

This driver is based on the [RMD-X Servo Motor Control Protocol V3.8](https://www.myactuator.com/_files/ugd/cab28a_0d661f6bcbc94a0882ceed465e4039ce.docx). In order to debug it, it might be helpful to get familiar with [CANbus errors](https://www.csselectronics.com/pages/can-bus-errors-intro-tutorial).
