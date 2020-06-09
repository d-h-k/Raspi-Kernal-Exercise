#include <linux/module.h>

MODULE_LICENSE("GPL")
MODULE_AUTHOR("DHKIM")
MODULE_DESCRIPTION("My DD")
MODULE_INFO(KFC,"jmt")

int mod_init(void) 
{
    printk( KERN_INFO "\n");
    printk( KERN_INFO "hi\n");
    printk( KERN_INFO "hi\n");
    printk( KERN_INFO "hi\n");
    printk( KERN_INFO "\n");
    return 0;
}

inf mod_exit(void) 
{
    printk( KERN_INFO "\n");
    printk( KERN_INFO "bye\n");
    printk( KERN_INFO "bye\n");
    printk( KERN_INFO "bye\n");
    printk( KERN_INFO "\n");
    return 0;
}

module_init(mod_init);
module_exit(mod_exit);