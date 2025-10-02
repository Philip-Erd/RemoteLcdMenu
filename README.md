# RemoteLcdMenu

This Arduino library lets you transmit Character LCD Data over Serial or other Stream interfaces. It is specifically written for [LcdMenu](https://github.com/forntoh/LcdMenu) but can work standalone. It also comes with an emulator, so you can connect your Arduino via Serial with a pc and access the menus from it.

A lot of projects require some configuration that should be changed after they got flashed. Some simple Menus and a few buttons are usually enough and LcdMenu delivers on that. But placing an LCD and buttons in every project is not always possible (size, cost, etc.), so i wanted to channel the display control commands and the button feedback over a serial interface, to be able to have a single device with an LCD and buttons and connect it to the project via serial. This also makes it possible to have an emulated LCD on a PC to configure it directly after programming.

## installation
Clone this git repo or download and extract the zip in your [Arduino libraries folder](https://docs.arduino.cc/software/ide-v1/tutorials/installing-libraries/#manual-installation). 


