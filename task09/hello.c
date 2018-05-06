#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kobject.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>
#include <linux/errno.h>
#include <linux/uaccess.h>
#include <linux/jiffies.h>
#include <linux/mutex.h>

#define ID_NO "ilovesoftsys"
#define ID_LENGTH 12


#undef VERIFY_OCTAL_PERMISSIONS
#define VERIFY_OCTAL_PERMISSIONS(perms) (perms)

// id

static ssize_t id_show(struct kobject* kobj, struct kobj_attribute* attr, char* buf)
{

        strncpy(buf, ID_NO"!", ID_LENGTH+1);
        return ID_LENGTH+1;
}

static ssize_t id_store(struct kobject* kobj, struct kobj_attribute* attr, const char* buf, size_t size)
{
        // char tmp[id_LEN+1];
        // int res = 0;
        if (size!=ID_LENGTH+1) {
                return -EINVAL;
        }
        if (!strncmp(buf, ID_NO, ID_LENGTH)) {
                return -EINVAL;
        }
        strncpy(ID_NO, buf, size);
        return size;
}

static struct kobj_attribute id_attribute = __ATTR(id, 0666, id_show, id_store);

// foo

static DEFINE_MUTEX(foo_mutex);
char msg[PAGE_SIZE];

static ssize_t foo_show(struct kobject* kobj, struct kobj_attribute* attr, char* buf)
{
        mutex_lock(&foo_mutex);
        strncpy(buf, msg, strlen(msg));
        mutex_unlock(&foo_mutex);
        return strlen(msg);
}

static ssize_t foo_store(struct kobject* kobj, struct kobj_attribute* attr, const char* buf, size_t size)
{
        if (size>PAGE_SIZE) return -EINVAL;
        mutex_lock(&foo_mutex);
        strncpy(msg, buf, size);
        mutex_unlock(&foo_mutex);
        return size;
}


static struct kobj_attribute foo_attribute = __ATTR(foo, 0644, foo_show, foo_store);

// jiffies

static ssize_t jiffies_show(struct kobject* kobj, struct kobj_attribute* attr, char* buf)
{
        return sprintf(buf, "%lu\n", jiffies);
}

static struct kobj_attribute jiffies_attribute = __ATTR(jiffies, 0444, jiffies_show, NULL);

// module

static struct attribute* attrs[] = {
        &id_attribute.attr,
        &foo_attribute.attr,
        &jiffies_attribute.attr,
        NULL,
};

static struct attribute_group hello_group = {
        .attrs = attrs,
};

static struct kobject* hello_kobj;

static int __init hello_init(void)
{
        int res;
        hello_kobj = kobject_create_and_add("SoftSys", kernel_kobj);
        if (!hello_kobj) return -ENOMEM;
        res = sysfs_create_group(hello_kobj, &hello_group);
        if (res) kobject_put(hello_kobj);
        return res;
}

static void __exit hello_exit(void)
{
        kobject_put(hello_kobj);
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("SoftSys");
