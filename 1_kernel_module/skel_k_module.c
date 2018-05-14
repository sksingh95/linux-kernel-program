#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>

static int __init module_entry(void){
	printk(KERN_INFO "skel_k_module --> module inserted successfully.\n");

	return 0;
}

static void __exit module_cleanup(void){
	printk(KERN_INFO "skel_k_module --> module removed successfully.");

}

module_init(module_entry);
module_exit(module_cleanup);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("S.Kr..Singh");
MODULE_DESCRIPTION("Basic Template Module");