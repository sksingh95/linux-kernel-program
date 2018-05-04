#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/i2c.h>
#include <linux/cdev.h>
//#include <linux/device.h>

#define MPU6050_ADDR	0x68
#define REG_POWER	0x6B
#define REG_GYROX	0x43

struct i2c_board_info info[]={
	.type = "mpu6050",
	.addr = MPU6050_ADDR,
};

static struct i2c_device_id mpu6050_id_table[]={
	{"mpu6050",0},
	{},
};

MODULE_DEVICE_TABLE(i2c, mpu6050_id_table);

static int mpu6050_probe(struct i2c_client *client, const struct i2c_device_id *id){
	int i;
	printk("KERN_INFO "iec driver: Probe function starts...");
	if(!i2c_check_functionality(client->adapter, I2C_FUNC_SMPUX_BYTE_DATA))
		return -EIO;
	else{
		printk("Functionality test passed");
	}
	printk(KERN_INFO "Exiting probe function...");
}

static int mpu6050_remove(struct i2c_client *client){
	printk(KERN_INFO "i2c driver: Rempve function ... exiting...");
}

static struct i2c_driver mpu6050_driver = {
	.driver={
		.name="mpu6050",
		.owner=THIS_MODULE,
	},
	.probe=mpu6050_probe,
	.remove=mpu6050_remove,
	.id_table=mpu6050_id_table
};

static int __init module_entry(void){
	
}

static void __exit module_cleanup(void){
	
}

module_init(module_entry);
module_exit(module_cleanup);
MODULE_DESCRIPTION("mpu6050 driver");