/*************************************************************************
	> File Name: oncerun.c
	> Author:YinXin 
	> Mail:yinxin19950816@gmail.com 
	> Created Time: 2015年08月08日 星期六 10时30分01秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

pthread_once_t once = PTHREAD_ONCE_INIT;

void run(void)
{
    printf("Fuction run is running in thread %u\n",(unsigned)pthread_self());
}

void *thread1(void *arg)
{
    pthread_t thid = pthread_self();
    printf("Current thread's ID is %u\n",(unsigned)thid);
    pthread_once(&once,run);
    printf("thread1 ends\n");
}

void *thread2(void *arg)
{
    pthread_t thid = pthread_self();
    printf("Current thread's ID is %u\n",(unsigned)thid);
    pthread_once(&once,run);
    printf("thread2 ends\n");
}

int main(void)
{
    pthread_t thid1,thid2;

    pthread_create(&thid1,NULL,thread1,NULL);
    pthread_create(&thid2,NULL,thread2,NULL);
    sleep(3);
    printf("main thread exit!\n");
    exit(0);
}
