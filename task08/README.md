# Task 8

We will come back to the linux-next kernel in a later exercise, so don't
go and delete that directory, you'll want it around.  But enough of
building kernels, let's write more code!

This task is much like the 06 task with the misc device, but this time
we are going to focus on another user/kernel interface, debugfs.  It is
rumored that the creator of debugfs said that there is only one rule for
debugfs use, "There are no rules when using debugfs."  So let's take
them up on that offer and see how to use it.

debugfs should be mounted by your distro in /sys/kernel/debug/, if it
isn't, then you can mount it with the line:
        mount -t debugfs none /sys/kernel/debug/

Make sure it is enabled in your kernel, with the CONFIG_DEBUG_FS option,
you will need it for this task.

The task, in specifics is:

  - Take the kernel module you wrote for task 01, and modify it to be
    create a debugfs subdirectory called "eudyptula".  In that
    directory, create 3 virtual files called "id", "jiffies", and "foo".
  - The file "id" operates just like it did for example 06, use the same
    logic there, the file must be readable and writable by any user.
  - The file "jiffies" is to be read only by any user, and when read,
    should return the current value of the jiffies kernel timer.
  - The file "foo" needs to be writable only by root, but readable by
    anyone.  When writing to it, the value must be stored, up to one
    page of data.  When read, which can be done by any user, the value
    must be returned that is stored it it.  Properly handle the fact
    that someone could be reading from the file while someone else is
    writing to it (oh, a locking hint!)
  - When the module is unloaded, all of the debugfs files are cleaned
    up, and any memory allocated is freed.
  - Provide some "proof" this all works.

Again, you are using your id in the code, so you know what it is by now,
no need to repeat it again




## Result

### File Description

- `hello.c`: Source of a basic module named `hello`.
- `Makefile`: A makefile for building `hello.c`.
- `README.md`: This file as readme.

### Environment

This task is conducted on Ubuntu 16.04 LTS with Linux kernel version 4.13.0. Superuser mode is needed for testing.



### Procedure

1. Write `hello.c` and `Makefile`.

### Verification

1. `mount | grep debugfs` to verify whether `debugfs` is mounted. If yes, skip to step 3.
2. `mount -t debugfs none /sys/kernel/debug` to mount `debugfs`.
3. `make` to compile the module. Note that this step generates lots of new files.
4. `modinfo hello.ko` to display the module info.
5. `insmod hello.ko` to install the module.
6. `lsmod | grep hello` to verify whether the module has been properly installed.
7. `echo ilovesoftsys > /sys/kernel/debug/SoftSys/id` to find normal output, which should be nothing.
8. `echo ihatesoftsys > /sys/kernel/debug/SoftSys/id` to find error information.
9. `cat /sys/kernel/debug/SoftSys/id` to read greetings.
10. `cat /sys/kernel/debug/SoftSys/jiffies` to see current jiffies, the number of ticks occurred since system start-up.
11. `echo ihatesoftsys > /sys/kernel/debug/SoftSys/jiffies` to get a permission denied.
12. `echo I LOVE SOFTSYS > /sys/kernel/debug/SoftSys/foo` to store information.
13. `cat /sys/kernel/debug/SoftSys/foo` to read the information from the last step.
14. `rmmod hello` to remove the module.
15. `lsmod | grep hello` to verify whether the module has been properly removed.

## Trivia

- Documentation about `debugfs` can be found under `Documentation/filesystems/debugfs.txt`.

  ​
