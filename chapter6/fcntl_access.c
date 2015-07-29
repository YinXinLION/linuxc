/*************************************************************************
	> File Name: fcntl_access.c
	> Author: 
	> Mail: 
	> Created Time: 2015年07月27日 星期一 16时55分26秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
//自定义的错误处理函数
void my_err(const char *err_string, int line)
{
    fprintf(stderr,"line:%d",line);
    perror(err_string);
    exit(1);
}

int main(void)
{
    int ret;
    int access_mode;
    int fd;

    if((fd=open("test.c",O_CREAT|O_TRUNC|O_RDWR,S_IRWXU))==-1)
    {
        my_err("open",__LINE__);
    }
    //设置文件打开方式
    if((ret=fcntl(fd,F_SETFL,O_APPEND))<0)
    {
        my_err("fcntl",__LINE__);
    }
    //获取文件打开方式
    if((ret=fcntl(fd,F_GETFL,0))<0)
    {
        my_err("fcntl",__LINE__);
    }
    access_mode=ret&O_ACCMODE;
    if(access_mode==O_RDONLY)
    {
        printf("test.c access mode :read only");
    }
    else if(access_mode==O_WRONLY)
    {
        printf("test.c access mode : write only");
    }
    else if(access_mode==O_RDWR)
    {
        printf("test.c access_mode : read + write");
    }

    if(ret & O_APPEND)
       printf(" ,append");
    if(ret & O_NONBLOCK)
       printf(" ,nonblock");
    if(ret & O_SYNC)
       printf(", sync");
    printf("\n");
    return 0;
}
