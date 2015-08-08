/*************************************************************************
	> File Name: jointhread.c
	> Author:YinXin 
	> Mail:yinxin19950816@gmail.com 
	> Created Time: 2015年08月08日 星期六 15时55分42秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void assisthread(void *arg)
{
    printf("I am helping to do some jobs\n");
    sleep(3);
    pthread_exit(0);
}

int main(void)
{
    pthread_t assistthid;
    int       status;

    pthread_create(&assistthid ,NULL,(void *)assisthread ,NULL);
    pthread_join(assistthid,(void *)&status);
    printf("assisthread's exit is casued %d\n",status);

    return 0;
}
