#include <linux/fs.h> 			/* open( ), read( ), write( ), close( ) 커널 함수 */
#include <linux/module.h>

#define MOD_MAJOR 141
#define MOD_NAME "kdh"

MODULE_LICENSE("GPL");

//static int minco_init(void);
//static void minco_exit(void);
//static int minco_open(struct inode *, struct file *);
//static int minco_close(struct inode *, struct file *);

static int minco_open(struct inode *inode, struct file *filp)
{
    printk( KERN_INFO "minco_open\n");
    return 0;
}

static int minco_release(struct inode *inode, struct file *filp)
{
    printk( KERN_INFO "minco_close\n");
    return 0;
}



static struct file_operations minco_fops = {
    .open = minco_open,
    .release = minco_release,
};


static int minco_init(void)
{
	if(register_chrdev(MOD_MAJOR,MOD_NAME, &minco_fops) < 0) {
		printk("INIT FAIL\n");
	}
    printk( KERN_INFO "minco_init\n");
    return 0;
}

static void minco_exit(void)
{
	unregister_chrdev(MOD_MAJOR, MOD_NAME);
	printk( KERN_INFO "minco_exit\n");
}


module_init(minco_init);
module_exit(minco_exit);
//module_open(minco_open);
//module_close(minco_close);


/* 유닉스 입출력 함수들의 처리를 위한 구조체 */
/*
static struct file_operations gpio_fops = {
    .owner = THIS_MODULE,
    .read = gpio_read,
    .write = gpio_write,
    .open = gpio_open,
    .release = gpio_close,
};
*/
