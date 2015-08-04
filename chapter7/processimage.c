/*************************************************************************
	> File Name: execve.c
	> Author:YinXin 
	> Mail:yinxin19950816@gmail.com 
	> Created Time: 2015年08月04日 星期二 09时44分46秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<time.h>
#include<unistd.h>
#include<syslog.h>
#include<signal.h>
int main(int argc , char **argv,char **environ)
{
    int i;
    printf("I am a process image!\n");
    printf("My pid = %d , parentpid = %d\n",getpid(),getppid());
    printf("uid = %d ,gid = %d\n",getuid(),getgid());

    for(i=0;i<argc;i++)
    printf("argv[%d]:%s\n",i,argv[i]);
}

