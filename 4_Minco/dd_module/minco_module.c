#include <linux/fs.h> 			/* open( ), read( ), write( ), close( ) 커널 함수 */
#include <linux/module.h>

MODULE_LICENSE("GPL");

/* 디바이스 파일의 주 번호와 부 번호 */
#define MOD_MAJOR 141
#define MOD_NAME "MINCO"

/* 입출력 함수를 위한 선언 */
static int gpio_open(struct inode *, struct file *);
static ssize_t gpio_read(struct file *, char *, size_t, loff_t *);
static ssize_t gpio_write(struct file *, const char *, size_t, loff_t *);
static int gpio_close(struct inode *, struct file *);


static struct file_operations gpio_fops = {
    .open = gpio_open,
    .release = gpio_close
};


static int minco_init(void)
{
    printk(KERN_INFO "minco_init\n");
    return 0;
}

static void minco_exit(void)
{
    printk(KERN_INFO "minco_exit\n");
    return;
}

static int minco_open(struct inode *inod, struct file *fil)
{
    printk(KERN_INFO "minco_open\n");
    return 0;
}

static int minco_close(struct inode *inod, struct file *fil)
{
    printk(KERN_INFO "minco_close\n");
    return 0;
}





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



//END OF FILE..... ============================================================



/*
static ssize_t gpio_read(struct file *inode, char *buff, size_t len, loff_t *off)
{
    int count;
    strcat(msg, " from Kernel");
    count = copy_to_user(buff, msg, strlen(msg)+1); // 사용자 영역으로 데이터를 보낸다. 
    printk("GPIO Device(%d) read : %s(%d)\n",
            MAJOR(inode->f_path.dentry->d_inode->i_rdev), msg, count);

    return count;
}

static ssize_t gpio_write(struct file *inode, const char *buff, size_t len, loff_t *off)
{
    short count;
    memset(msg, 0, BLOCK_SIZE);
    count = copy_from_user(msg, buff, len); //* 사용자 영역으로부터 데이터를 가져온다. 
    /* 사용자가 보낸 데이터가 0인 경우 LED를 끄고, 0이 아닌 경우 LED를 켠다. 
    (!strcmp(msg, "0"))?GPIO_CLR(GPIO_LED):GPIO_SET(GPIO_LED);
    printk("GPIO Device(%d) write : %s(%d)\n",
            MAJOR(inode->f_path.dentry->d_inode->i_rdev), msg, len);
    return count;
}
*/