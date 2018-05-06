# Task 9

Nice job with debugfs, that is a handy thing to remember when wanting to
print out some debugging information.  Never use /proc/ that is only for
processes, use debugfs instead.

Along with debugfs, sysfs is a common place to put information that
needs to move from the user to the kernel.  So let us focus on sysfs for
this task.

The task this time:

  - Take the code you wrote in task 08, and move it to sysfs.  Put the
    "eudyptula" directory under the /sys/kernel/ location in sysfs.
  - Provide some "proof" this works.

That's it!  Simple, right?  No, you are right, it's more complex, sysfs
is complicated.  I'd recommend reading Documentation/kobject.txt as a
primer on how to use kobjects and sysfs.

Feel free to ask for hints and help with this one if you have questions
by sending in code to review if you get stuck, many people have dropped
out in the challenge at this point in time, so don't feel bad about
asking, we don't want to see you go away just because sysfs is so damn
complicated.

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

1. `make` to compile the module. Note that this step generates lots of new files.
2. `modinfo hello.ko` to display the module info.
3. `insmod hello.ko` to install the module.
4. `lsmod | grep hello` to verify whether the module has been properly installed.
5. `echo ilovesoftsys > /sys/kernel/debug/SoftSys/id` to find normal output, which should be nothing.
6. `echo ihatesoftsys > /sys/kernel/debug/SoftSys/id` to find error information.
7. `cat /sys/kernel/debug/SoftSys/id` to read greetings.
8. `cat /sys/kernel/debug/SoftSys/jiffies` to see current jiffies, the number of ticks occurred since system start-up.
9. `echo ihatesoftsys > /sys/kernel/debug/SoftSys/jiffies` to get a permission denied.
10. `echo I LOVE SOFTSYS > /sys/kernel/debug/SoftSys/foo` to store information.
11. `cat /sys/kernel/debug/SoftSys/foo` to read the information from the last step.
12. `rmmod hello` to remove the module.
13. `lsmod | grep hello` to verify whether the module has been properly removed.

## Trivia

- `sysfs` does not allow files to have permission of `0666`. It calls `VERIFY_OCTAL_PERMISSIONS` to check this. To bypass the checking process, the macro should be redefined.

  ```c
  #undef VERIFY_OCTAL_PERMISSIONS
  #define VERIFY_OCTAL_PERMISSIONS(perms) (perms)
  ```

  ​