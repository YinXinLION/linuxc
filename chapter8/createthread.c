/*************************************************************************
	> File Name: createthread.c
	> Author:YinXin 
	> Mail:yinxin19950816@gmail.com 
	> Created Time: 2015年08月08日 星期六 10时05分25秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int *thread(void *arg)
{
    pthread_t newthid;

    newthid = pthread_self();
    printf("this is a new thread, thread ID = %u\n",(unsigned)newthid);
    return NULL;
}

int main(void)
{
    pthread_t thid;
    printf("main thread , ID is %u\n",(unsigned)pthread_self());//打印主线程ID
    if(pthread_create(&thid,NULL,(void *)thread,NULL) != 0)
    {
        printf("thread creation failed\n");
        exit(1);
    }
    sleep(1);
    exit(0);
}
 
