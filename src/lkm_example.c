#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Author");
MODULE_DESCRIPTION("Description");
MODULE_VERSION("1.0");

static int __init lmk_example_init(void) {
    printk(KERN_INFO "Hello world\n");
    return 0;
}

static void __exit lmk_example_exit(void) {
    printk(KERN_INFO "Goodbye world\n");
}

module_init(lmk_example_init);
module_exit(lmk_example_exit);
