/*************************************************************************
	> File Name: wait.c
	> Author:YinXin 
	> Mail:yinxin19950816@gmail.com 
	> Created Time: 2015年08月04日 星期二 10时41分48秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<time.h>
#include<unistd.h>
#include<syslog.h>
#include<signal.h>

int main(void)
{
    pid_t pc,pr;
    pc = fork();

    if(pc < 0)
    printf("error ocurred!\n");
    else if(pc == 0)
    {
        printf("This is child process with pid of %d\n",getpid());
        sleep(10);
    }
    else{
        pr = wait(NULL);
        printf("I catched a child process with pid of %d \n",pr);
    }
    exit(0);
}
