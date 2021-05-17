### HOS-x86 an x86 operating system written from scratch (This applies to sqOS, i just don't want to decredit the guy)

### How to Build?

Currently you need ```NASM```, ```GCC``` and ```QEMU``` to build the image file.

Install the packages using the following commands.

Note: These commands will only work on Ubuntu/Debian based systems.
```
apt-get install nasm
apt-get install gcc
apt-get install qemu
```

To build the image, run the following command or you can download the iso file from [releases](https://github.com/jaychandra6/hos-x86/releases/tag/0.2)
```
sh build.sh or ./build.sh
```

To emulate the os image, run the following command
```
qemu-system-i386 -kernel os.bin
```

To run it using GRUB bootloader,
```
qemu-system-i386 hos-x86.iso
```

Some Features
-------------
* GDT
* IDT
* VGA Driver
* Keyboard Driver
* Timer

There are still plenty of things that needs to be added, which I'll do it in spare time.

Here's how it looks

![img file](https://github.com/jaychandra6/hos-x86/blob/main/os.png)

This project and the kernel is based on this [tutorial](http://www.osdever.net/bkerndev/Docs/title.htm)
