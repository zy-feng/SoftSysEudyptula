# Task 11

You made a successful patch to the kernel source tree, that's a great
step!

But, let's not rest, time to get back to code.

Remember that mess of kobject and sysfs code back in task 09?  Let's
move one level up the tree and start to mess with devices and not raw
kobjects.

For this task:
  - Write a patch against any driver that you are currently using on
    your machine.  So first you have to figure out which drivers you are
    using, and where the source code in the kernel tree is for that
    driver.
  - In that driver, add a sysfs file to show up in the /sys/devices/
    tree for the device that is called "id".  As you might expect, this
    file follows the same rules as task 09 as for what you can read and
    write to it.
  - The file is to show up only for devices that are controlled by a
    single driver, not for all devices of a single type (like all USB
    devices.  But all USB maibox LEDs would be acceptable, if you happen
    to have the device that that driver controls.)

Submit both the patch, in proper kernel commit form, and "proof" of it
working properly on your machine.

And as always, please use your id in the subject line.  If you happened
to forget it, as it has been a while since I reminded you of it, it is
"7c1caf2f50d1".




## Results

### File Description

- `0001-id-sysfs-FTDI-Xdriver-serial.patch`: A patch containing task-oriented changes.
- `README.md`: This file as readme.

### Environment

This task is conducted on Ubuntu 16.04 LTS with Linux kernel version 4.13.0.



### Procedure

1. Find source of one of the most common USB drivers in  `drivers/usb/serial/ftdi_sio.c`.

2. Backup the original source, and create a working archive with `cp` named as `linux-4.17-rc3-modf`.

3. `vim linux-4.17-rc3-modf/drivers/usb/serial/ftdi_sio.c` and modify the codings.

4. `diff -uprN -X linux-4.17-rc3-modf/Documentation/dontdiff linux-4.17-rc3 linux-4.17-rc3-modf > 0001-id-sysfs-FTDI-Xdriver-serial.patch` to generate a patch.

5. Add the signature in the first line.

   ```
   Signed-off-by: Zhengyang Feng <crukedshfeng@gmail.com>
   ```

6. `perl linux-4.17-rc3/scripts/checkpatch.pl 0001-id-sysfs-FTDI-Xdriver-serial.patch` to check the correctness.

### Verification

1. Buy a USB device with FTDI X series as the main chip.
2. Under source directory, `patch -p1 < ../0001-id-sysfs-FTDI-Xdriver-serial.patch`c. Notice the output information as `patching file drivers/usb/serial/ftdi_sio.c`.
3. Plug the device in. Find the device by `find /sys/devices/ -name ttyUSB*`. `cd ` to the directory.
4. `echo ilovesoftsys > id` to find normal output, which should be nothing.
5. `echo ihatesoftsys > id` to find error information.
6. `cat id` to read greetings.
