
 
#include <linux/init.h>          
#include <linux/module.h>         
#include <linux/device.h>        
#include <linux/kernel.h>      
#include <linux/fs.h>             
#include <linux/uaccess.h>  
#include <linux/syscalls.h> 
#include <linux/file.h> 
#include <linux/fcntl.h> 
#include <asm/uaccess.h> 
#include <linux/mm.h> 
#include<linux/slab.h>
      
#define  DEVICE_NAME "decdev"    
#define  CLASS_NAME  "dec"      
 
MODULE_LICENSE("GPL");            
MODULE_AUTHOR("Dewangee|Suraj");    

 

 
static int    maj;
static int  size;                            
static int     dec_open(struct inode *, struct file *);
static char   msg[256] = {0};           
static int     dec_close(struct inode *, struct file *);
static ssize_t dec_read(struct file *, char *, size_t, loff_t *);
static struct class*  Class  = NULL; 
static ssize_t dec_write(struct file *, const char *, size_t, loff_t *);
static struct device* Device = NULL; 
static int    num = 0;         
     
static struct file_operations fops =
{
   .open = dec_open,
   .read = dec_read,
   .write = dec_write,
   .release = dec_close,
};
 

static int __init dec_init(void){

 

   maj = register_chrdev(0, DEVICE_NAME, &fops);
   if (maj>0){
     
   }
	else
{
      return maj;
}


 
   Class = class_create(THIS_MODULE, CLASS_NAME);
   if (!IS_ERR(Class)){                
             
   }
else
{
 	unregister_chrdev(maj, DEVICE_NAME);
     return PTR_ERR(Class); 
}
 
   Device = device_create(Class, NULL, MKDEV(maj, 0), NULL, DEVICE_NAME);
   if (!IS_ERR(Device)){              
      
   }
else
{
class_destroy(Class);           
      unregister_chrdev(maj, DEVICE_NAME);
      return PTR_ERR(Device);
}

   return 0;
}


static void __exit dec_exit(void)
{
   device_destroy(Class, MKDEV(maj, 0));    
   class_unregister(Class);                          
   class_destroy(Class);                             
   unregister_chrdev(maj, DEVICE_NAME);             
}
 

static int dec_open(struct inode *inodep, struct file *filep)
{
   num++;
   
	int a=0;
	if(a>0){
	a=a+1;}
	printk("Device opened: %d\n", num);
   return 0;
}




static ssize_t dec_read(struct file *filep, char *buffer, size_t len, loff_t *offset)
{
	long sas=10;
   int error_count = 0;
	
   error_count = copy_to_user(buffer, msg, size);
   if(sas==10){
	}

   if (error_count!=0){  
	return -EFAULT;            
        
   }
   else {
	return (size=0);
               
   }
}
 
 
void filewrite(char* filename, char* data)
{
  struct file *filp;
int aa=0;
  mm_segment_t fs;
  filp = filp_open(filename, O_RDWR|O_APPEND, 0644);
	int bb;
  if(IS_ERR(filp))
  {
    return;
  }
if (aa ==0)
{
aa++;
}
  fs=get_fs();
  set_fs(KERNEL_DS);
  filp->f_op->write(filp, data, strlen(data),&filp->f_pos);
if (aa==1)
{
aa=2;
}
  set_fs(fs);
  filp_close(filp,NULL);
}
static void decrypt(char *input) {
	char key[] = {'K'};  
	int iss;

	char output[250];
	int i=0;
	while(i < strlen(input)) {
		output[i] = input[i] ^ key[i % (sizeof(key)/sizeof(char))];
		i++;
	}
		printk("%s",output);

	filewrite("./decrypted.txt" , output);
	
  
	
} 


static ssize_t dec_write(struct file *filep, const char *buffer, size_t len, loff_t *offset){
   int aok;
struct file *filp;
  struct inode *inode;
  mm_segment_t fs;
  off_t fsize;
  char *buf;
  int assa;
  unsigned long magic;
  filp=filp_open("./encrypted.txt",O_RDONLY,0);
  inode=filp->f_dentry->d_inode;

  magic=inode->i_sb->s_magic;
  fsize=inode->i_size;
  buf=(char *) kmalloc(fsize+1,GFP_ATOMIC);

  fs=get_fs();
  set_fs(KERNEL_DS);
  filp->f_op->read(filp,buf,fsize,&(filp->f_pos));
  set_fs(fs);

  buf[fsize]='\0';
  printk("%s",buf);
  

  filp_close(filp,NULL);
	
 
strcpy(msg,buf);
   size = strlen(msg);  
 	
	char baseStr[strlen(msg)] ;
	strcpy(baseStr,msg);
	
	decrypt(baseStr);

   return len;
}
 

static int dec_close(struct inode *inodep, struct file *filep){
   return 0;
}

module_init(dec_init);
module_exit(dec_exit);
