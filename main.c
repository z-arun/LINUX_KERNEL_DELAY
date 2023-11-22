#include<linux/module.h>
#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/delay.h>
#include<linux/jiffies.h>


MODULE_AUTHOR("Arun S Nair");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple kernel module with delay ");

int __init startFun(void)
{
        int temp;
        printk(KERN_INFO "\nHello world\n");
        pr_info("----- %ld----\n",jiffies);
        ssleep(1);
        pr_info("----- %ld----\n",jiffies);
        msleep(1000);
        pr_info("----- %ld----\n",jiffies);

        //5 sec delay using jiffies for CONFIG_HZ = 250
        // 1 jiffies increment is 1000ms/250 = 4ms 
        // so for 5 sec jiffies should increment  5sec/4ms  = 1250
        // this wont wok properly when jiffies overfloes and reset to 0
        temp = jiffies;
        while(jiffies <= (temp + 1250));
        pr_info("----- %ld-----\n",jiffies);


        udelay(1000);
        mdelay(1000);

        return 0;
}

void __exit endFun(void)
{
        printk(KERN_INFO "\nbye world\n");
}

module_init(startFun);
module_exit(endFun);
