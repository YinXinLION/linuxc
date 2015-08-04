/*************************************************************************
	> File Name: execve.c
	> Author:YinXin 
	> Mail:yinxin19950816@gmail.com 
	> Created Time: 2015年08月04日 星期二 09时48分19秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<time.h>
#include<unistd.h>
#include<syslog.h>
#include<signal.h>
int main(int argc,char **argv,char **environ)
{
    pid_t pid;
    int stat_val;
    printf("Exec example!\n");
    pid = fork();

    switch(pid)
    {
        case -1:
        perror("Process Creation failed\n");
        exit(1);

        case 0:
        printf("Child Process is running");
        printf("My pid = %d ,parentpid = %d\n",getpid(),getppid());
        printf("uid = %d,gid = %d\n",getuid(),getgid());
        execve("processimage",argv,environ);
        printf("process never gp to here!\n");
        exit(0);

        default:
        printf("Parent Process is running\n");
        break;
    }

    wait(&stat_val);
    exit(0);
}
