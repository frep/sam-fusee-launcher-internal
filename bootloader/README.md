

# Bootloader
The first step to get the your own board up and running after the hardware is done, is to put the bootloader on the chip. So we need the bootloader-file and a programmer.

## bootloader-binary
I have included a working bootloader from the trinket m0 board, made by Adafruit. This bootloader is quite nice, since it's a UF2-bootloader. That means, by quickly pressing two times the reset, the chip will go into a sort of usb-device mode. It shows up on the attached computer as usb-device, and also can be programmed this way. The provided bootloader from the trinket m0 board is compatible with my custom board. To build the bootloader on your own (like I did), you can check out the following repository from adafruit:

[https://github.com/adafruit/uf2-samdx1](https://github.com/adafruit/uf2-samdx1)

Check the requirements and follow the instructions and you'll be able to compile your own uf2-bootloader.

## programmer
There are several methods, I tried to put your bootloader-binary on the chip:

### Raspberry Pi 2/3
There is the possibility to use a raspberry pi as an openocd-programmer. Adafruit made also for this a great tutorial. Check it out to set the raspberry pi up and to correctly wire it to your board:

[https://learn.adafruit.com/programming-microcontrollers-using-openocd-on-raspberry-pi](https://learn.adafruit.com/programming-microcontrollers-using-openocd-on-raspberry-pi)

A working openocd-configuration can be found in the folder...

### m0-based board
Also a m0-based board like the trinket m0 can be used as a bootloader-programmer. Again, Adafruit provides for this a tutorial too:

[https://learn.adafruit.com/programming-an-m0-using-an-arduino](https://learn.adafruit.com/programming-an-m0-using-an-arduino)

In the tutorial a Adafruit Feather M0 Adalogger was used. This is very nice, since the bootloader-binary can be put on the sd-card and programmed from there into the new chip. However, the bootloader-binary can also be included into the sketch, so also a board like the trinket m0, without an sd-card slot can be used. A working sketch can be found under...

### j-link

[https://learn.adafruit.com/compiling-m0-atsamd21-bootloader](https://learn.adafruit.com/compiling-m0-atsamd21-bootloader)