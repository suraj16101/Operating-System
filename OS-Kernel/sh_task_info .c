#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/sched.h>
#include<linux/syscalls.h>
#include<linux/module.h>
#include<linux/file.h>
#include<linux/fs.h>
#include<linux/fcntl.h>
#include<asm/uaccess.h>
void tostring(char str[] , long num)
{
	

	
	long n = num;
	int len=0;
	int i=0;
	long rem;	

	while (n!=0)
	{
		len++;
		n /= 10;
	}

	while (i<len)
	{
		rem = num%10;
		num = num/10;
		str[len-(i+1)]=rem+'0';
		i++;
	}	
	str[len] = '\0';
	
}
static void write_file(char where[],char data[])
{
	struct file *file;
	loff_t pos =0;
	int fd;
	mm_segment_t old_fs =get_fs();
	set_fs(KERNEL_DS);
	
	fd=sys_open(where,O_WRONLY|O_CREAT,0644);

	if(fd>=0)
	{
		//sys_write(fd,data,strlen(data));
		//sys_write(1,data,strlen(data));
		file = fget(fd);
		if (file){
		vfs_write(file,data,strlen(data),&pos);
		fput(file);
		}
		sys_close(fd);
	}
	else{
	printk("ENOENT 2 No such file or directory");
	//sys_write(1,"ENOENT 2 No such file or directory",strlen("ENOENT 2 No such file or directory"));

	}
	set_fs(old_fs);
}



asmlinkage long sys_sh_task_info(pid_t pid, char *name) {
	
    	
	int flag=0;
        struct task_struct *proces;
    	char data[sizeof(long)*9];
	long hii = sscanf(pid, "%d", &pid);
	char where[1000];
	long hi = strncpy_from_user(where,name,sizeof(where));
    	for_each_process(proces) {
 	if(pid==task_pid_nr(proces)){
	flag=1;
    	printk("Process: %s\n ",proces->comm);
	printk(" PID_Number: %ld\n",(long)task_pid_nr(proces));
	printk("Process State: %ld\n ",(long)proces->state);
	printk("Priority: %ld\n",(long)proces->prio);
	printk(" RT_Priority: %ld\n ",(long)proces->rt_priority);
	printk("Static Priority: %ld\n ",(long)proces->static_prio);
	printk("Normal Priority: %ld\n",(long)proces->normal_prio);

	
	strcat(data,"Process:");
	strcat(data, proces->comm);

	char taskpidnr[sizeof(long)];
	strcat(data,"PID number: ");
	tostring(taskpidnr, (long)task_pid_nr(proces));
	strcat(data, taskpidnr);

	char state[sizeof(long)];
	strcat(data,"Process State: ");
	tostring(state, (long)proces->state);
	strcat(data, state);

	char priority[sizeof(long)];
	strcat(data,"Priority: ");
	tostring(priority, (long)proces->prio);
	strcat(data, priority);

	char rt[sizeof(long)];
	strcat(data,"RT_Priority: ");
	tostring(rt, (long)proces->rt_priority);
	strcat(data, rt);
	
	char staticp[sizeof(long)];
	strcat(data,"Static Priority:");
	tostring(staticp, (long)proces->static_prio);
	strcat(data, staticp);

	char normalp[sizeof(long)];
	strcat(data,"Normal Priority: ");
	tostring(normalp, (long)proces->normal_prio);
	strcat(data, normalp);
	
  
  
   if(proces->parent) {
   
      printk("Parent process: %s", proces->parent->comm);
      printk("PID_Number: %ld",(long)task_pid_nr(proces->parent));

	strcat(data,"Process: ");
	strcat(data, proces->comm);

	char taskpidnr[sizeof(long)];
	strcat(data,"PID number: ");
	tostring(taskpidnr, (long)task_pid_nr(proces));
	strcat(data, taskpidnr);
       
}
   	printk("\n\n");
	 write_file(where,data);

  }


}
if(flag==0){
	printk(" ESRCH 3 No such process ");
	//sys_write(1," ESRCH 3 No such process ",strlen(" ESRCH 3 No such process "));

	}


	

  return 0;
}
