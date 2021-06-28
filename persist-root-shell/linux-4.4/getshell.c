/*  
 *  getshell.c - The simplest kernel module to load shell script.
 */
#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_INFO */
#include <linux/kmod.h>
#include <linux/delay.h>

#define DRV_NAME "getshell"
#define DRV_VERSION "2.0"
#define DRV_COPYRIGHT "compiled by 0neday using 4.4.197 kernel, 2021/06/26"
#define DRV_DESCRIPTION "persist root shell realized by kernel module"


MODULE_DESCRIPTION(DRV_DESCRIPTION);
MODULE_AUTHOR(DRV_COPYRIGHT);
MODULE_LICENSE("GPL");

int getshell_init(void)
{
	char * argv[4];
	char * envp[4]; 
	argv[0] = "/bin/sh";
	argv[1] = "-c";
	argv[2] = "/mnt/jffs2/hw/getshell.sh";
	argv[3] = NULL;

	envp[0] = "HOME=/";
	envp[1] = "TERM=linux";
	envp[2] = "PATH=/sbin:/usr/sbin:/bin:/usr/bin";
	envp[3] = NULL;

	call_usermodehelper(argv[0], argv, envp, UMH_NO_WAIT);
	msleep(3000);
	printk(KERN_INFO "getshell script run successfully !.\n");

	/* 
	 * A non 0 return means init_module failed; module can't be loaded. 
	 */
	return 0;
}

static void __exit getshell_exit(void)
{
	printk(KERN_INFO "Goodbye world !.\n");
}
module_init(getshell_init);
module_exit(getshell_exit);
