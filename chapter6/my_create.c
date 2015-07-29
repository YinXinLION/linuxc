/*************************************************************************
	> File Name: my_create.c
	> Author: 
	> Mail: 
	> Created Time: 2015年07月25日 星期六 15时12分50秒
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>

int main(void)
{
    int fd;
   if((fd=open("2.c",O_CREAT|O_EXCL,S_IRUSR|S_IWUSR))==-1)
    {
   //     if((fd=creat("2.c",S_IRWXU))==-1) {
     //   perror("open");
        printf("opem %s with errno:%d \n",strerror(errno),errno);
        exit(1);
     }
    else{
        printf("create file success\n");
    }
    close(fd);
    return 0;

}
