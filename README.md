# jetsonNanoRegisterAccess
Jetson Nano direct hardware register access.

## Introduction
This is a library for accessing peripherals to the ARM A57 core. There are two
methods of doing this.

1. The first method is using the file system method (/sys/class/gpio). This 
   method isn't fast, and not the focus of this repository but, I will link 
   sources to it because it is fairly uncomplicated and could be usefull to
   someone in the future. The following links are regarding this method:
   * [Gpio pin access in C++](https://forums.developer.nvidia.com/t/using-gpio-pins-with-c-on-the-nano/75783)  
   * [Github repo for accessing GPIOs using the file system method](https://github.com/pjueon/JetsonGPIO)
   * [Mod answer about the gpio file system method](https://forums.developer.nvidia.com/t/how-to-use-gpio-in-c-language/75191)
   * [More example code on how to use the file system method](https://www.ics.com/blog/how-control-gpio-hardware-c-or-c)
   * [Setting PWM hardware using file systme method and uboot pinmux](https://forums.developer.nvidia.com/t/nano-pwm-c/122492/9)

2. The second method is via the directly accessing the registers. This method
   is faster because it skips the file system access overhead, but is much
   more involved. This method is the primary focus of this repository. The
   following are links which I deemed useful in this endevor:
   * [Direct register access via C++ post](https://forums.developer.nvidia.com/t/jetson-nano-fast-gpio-c-example-with-direct-register-access/79692/12)
   * [How to configure the device tree stuff](https://www.seeedstudio.com/blog/2020/05/27/configure-pwm-output-on-jetson-nano-m/)
   * [DRA code examples from Valentis on github](https://github.com/valentis/jetson-nano-gpio-example)
   * [DRA code examples from Jwatte on github](https://github.com/jwatte/jetson-gpio-example)
   * [Updated way of modifying the DTB using a python script](https://docs.nvidia.com/jetson/l4t/#page/Tegra%20Linux%20Driver%20Package%20Development%20Guide/hw_setup_jetson_io.html%23wwpID0E0JE0HA)
   * [Jetson nano platform adatpation and bring up guide](https://developer.download.nvidia.com/embedded/L4T/r32-2_Release_v1.0/Tegra_Linux_Driver_Package_Nano_Adaptation_Guide.pdf?LXJYFxZKcq85VeLYsOVlrdF-YdUbKgX4Hd1eBPhpHV7rcpRcEYxJOKZQ7_W7JNexNwllmrjQPagLBLY9tnKUfIPpGl_kmyZOPjFXM130Z05vfURWk0IgtmWsQMn9eBYc6SSKoX-kayx0oyLox0pRAO87LR42ydM7FyjeiAdiOTIv6FV6F9ZMIi7l02GA227X1bFm#page235)
   * [Where is the jetson nano tehcnical reference manual with registers?](https://forums.developer.nvidia.com/t/technical-reference-manual/73593)
   * [Jetson nano platform adaptation and bring uo - pinmux changes and other things](https://docs.nvidia.com/jetson/l4t/index.html#page/Tegra%20Linux%20Driver%20Package%20Development%20Guide/adaptation_and_bringup_nano.html%23wwpID0E0EQ0HA)
 
## Copyright
jetsonNanoRegisterAccess. Copyright (C) Matthew Hardenburgh 2021. All rights reserved. mdhardenburgh@protonmail.com

## Licensing
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.

## Disclamer
As stated in the section titled "licensing" above, this software is provided
without any warranty. In addition, the public interfaces may change without
warning at any time. This means I am not responsible for permentently bricking
your jetson, getting you fired or causing a thermonuclear apocolypse. While I 
have done my best to release a product that is of quality, it falls to be
YOUR reseponsiblity to vet the code's suitability and verify its operation.
