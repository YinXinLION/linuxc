/*************************************************************************
	> File Name: fork.c
	> Author: 
	> Mail: 
	> Created Time: 2015年08月03日 星期一 09时24分06秒
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

int main(void)
{
    pid_t pid;

    printf("Process Creation Study\n");
    pid = fork();
    switch(pid)
    {
        case 0: 
        printf("Child process is running , CurPid is %d , Parent is %d\n",pid , getpid());
        break;

        case -1:
        perror("Process Creation failed\n");
        break;

        default:
        printf("Parent Process is running , ChildPid is %d , ParentPid is %d\n",pid,getpid());
        break;
    }
    exit(0);

}
