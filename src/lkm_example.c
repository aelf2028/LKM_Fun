#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kallsyms.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Author");
MODULE_DESCRIPTION("Description");
MODULE_VERSION("1.0");

static unsigned long *sys_call_table;

static int __init lmk_example_init(void) {
    sys_call_table = (void *)kallsyms_lookup_name("sys_call_table");

    if(sys_call_table == NULL) {
        printk(KERN_ERR "Couldn't find sys_call_table");
        return -1;
    }
    printk(KERN_INFO "sys_call_table found at %lx", sys_call_table);
    return 0;
}

static void __exit lmk_example_exit(void) {
    printk(KERN_INFO "Goodbye world\n");
}

module_init(lmk_example_init);
module_exit(lmk_example_exit);
