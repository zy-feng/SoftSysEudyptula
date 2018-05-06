/*
helloworld.c
Example module for Eudyptula challenge task 4
*/

#include <linux/module.h>
#include <linux/kernel.h>

int hello_init(void)
{
        printk(KERN_INFO "Hello World!\n");
        return 0;
}

void hello_exit(void)
{
        printk(KERN_INFO "Bye World!\n");
}

module_init(hello_init);
module_exit(hello_exit);
