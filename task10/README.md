# Task 10

## Problem

Yeah, you conquered the sysfs monster, great job!

Now you know to never want to mess with a kobject again, right?  Trust
me, there are easier ways to create sysfs files, and we will get into
that for a future task, but for now, let's make it a bit more simple
after all of that coding.

For this task, go back to the linux-next tree you used for task 07.
Update it, and then do the following:
  - Create a patch that fixes one coding style problem in any of the
    files in drivers/staging/
  - Make sure the patch is correct by running it through
    scripts/checkpatch.pl
  - Submit the code to the maintainer of the driver/subsystem, finding
    the proper name and mailing lists to send it to by running the tool,
    scripts/get_maintainer.pl on your patch.
  - Send a web link back to me of your patch on the public mailing list
    archive (don't cc: me on the patch, that will only confuse me and
    everyone in the kernel development community.)
  - If you want to mention the Eudyptula Challenge as the reason for
    writing the patch, feel free to do so in the body of the patch, but
    it's not necessary at all.

Hopefully this patch will be accepted into the kernel tree, and all of a
sudden, you are an "official" kernel developer!

Don't worry, there's plenty more tasks coming, but a little breather
every now and again for something simple is always nice to have.



## Results

### File Description

- `0001-staging-vc04-interface-fix-indentation.patch`: A patch containing task-oriented changes.
- `README.md`: This file as readme.



### Environment

This task is conducted on Ubuntu 16.04 LTS with Linux kernel version 4.13.0.



### Procedure

1. Spot the coding style problem in `drivers/staging/vc04_services/interface/vchi/message_drivers/message.h`.

2. Backup the original source, and create a working archive with `cp` named as `linux-4.17-rc3-modf`.

3. `vim linux-4.17-rc3-modf/drivers/staging/vc04_services/interface/vchi/message_drivers/message.h` and change the codings.

4. `diff -uprN -X linux-4.17-rc3-modf/Documentation/dontdiff linux-4.17-rc3 linux-4.17-rc3-modf > 0001-staging-vc04-interface-fix-indentation.patch` to generate a patch.

5. Add the signature in the first line.

   ```
   Signed-off-by: Zhengyang Feng <crukedshfeng@gmail.com>
   ```

6. `perl linux-4.17-rc3/scripts/checkpatch.pl 0001-staging-vc04-interface-fix-indentation.patch` to check the correctness.

7. Submit the patch via email.

### Verification

1. Under source directory, `patch -p1 < ../0001-staging-vc04-interface-fix-indentation.patch`. Notice the output information as `patching file drivers/staging/vc04_services/interface/vchi/message_drivers/message.h`.

## Trivia

- It has been a long time since I worked on task7, so I re-downloaded the source, which is now `linux-4.17-rc3`.
- Using `git format-patch` is a more professional way to create a patch. But it takes too long for me to download the whole linux source tree, so I used bare `diff` to avoid hash conflict in the remote source tree.