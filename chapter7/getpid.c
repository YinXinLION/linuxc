/*************************************************************************
	> File Name: getpid.c
	> Author:YinXin 
	> Mail:yinxin19950816@gmail.com 
	> Created Time: 2015年08月04日 星期二 14时54分25秒
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
    pid_t     pid;

    if((pid = fork()) == -1)
    {
        printf("fork error\n");
        exit(1);
    }

    if(pid == 0)
    printf("getpid return %d\n",getpid());

    exit(0);
}
