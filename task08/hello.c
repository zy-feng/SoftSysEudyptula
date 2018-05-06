#include <linux/debugfs.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>
#include <linux/errno.h>
#include <linux/uaccess.h>
#include <linux/jiffies.h>
#include <linux/mutex.h>

#define ID_NO "ilovesoftsys"
#define ID_LENGTH 12

// id

static ssize_t id_read(struct file* fp, char __user* user, size_t size, loff_t* offs)
{
        return simple_read_from_buffer(user,size,offs,ID_NO "!",ID_LENGTH+1);
}

static ssize_t id_write(struct file* fp, const char __user* user, size_t size, loff_t* offs)
{
        char tmp[ID_LENGTH+1];
        int res = 0;
        if (size==ID_LENGTH+1) {
                res = simple_write_to_buffer(tmp, ID_LENGTH, offs, user, size) + 1;
                tmp[ID_LENGTH] = '\0';
        } else res = -EINVAL;
        if (*offs==ID_LENGTH) {
                if (strncmp(tmp, ID_NO, ID_LENGTH)) res = -EINVAL;
        }
        return res;
}

static const struct file_operations id_ops = {
        .owner = THIS_MODULE,
        .read = id_read,
        .write = id_write
};

// foo

static DEFINE_MUTEX(foo_mutex);
char msg[PAGE_SIZE];

static ssize_t foo_read(struct file* fp, char __user* user, size_t size, loff_t* offs)
{
        int res = -EINVAL;
        mutex_lock(&foo_mutex);
        res = simple_read_from_buffer(user,size,offs,msg,strlen(msg));
        mutex_unlock(&foo_mutex);
        return res;
}

static ssize_t foo_write(struct file* fp, const char __user* user, size_t size, loff_t* offs)
{
        ssize_t res;
        mutex_lock(&foo_mutex);
        res = simple_write_to_buffer(msg,PAGE_SIZE,offs,user,size);
        mutex_unlock(&foo_mutex);
        return res;
}

static const struct file_operations foo_ops = {
        .owner = THIS_MODULE,
        .read = foo_read,
        .write = foo_write
};

// module

struct dentry* ret;

static int __init hello_init(void)
{
        ret = debugfs_create_dir("SoftSys", NULL);
        if (!debugfs_create_file("id", 0666, ret, NULL, &id_ops)){
                return -ENODEV;
        }
        if (!debugfs_create_u32("jiffies", 0444, ret, (u32*)&jiffies)){
                return -ENODEV;
        }
        if (!debugfs_create_file("foo", 0644, ret, NULL, &foo_ops)){
                return -ENODEV;
        }
        return 0;
}

static void __exit hello_exit(void)
{
        debugfs_remove_recursive(ret);
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("SoftSys");
