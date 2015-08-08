/*************************************************************************
	> File Name: lock.c
	> Author:YinXin 
	> Mail:yinxin19950816@gmail.com 
	> Created Time: 2015年08月08日 星期六 17时49分34秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h> 

pthread_mutex_t number_mutex;

int             globalnumber = 0;

void write_globalnumber()
{
    pthread_mutex_lock(&number_mutex);
    printf("write\n");
    globalnumber++;
    pthread_mutex_unlock(&number_mutex);
}

int read_globalnumber()
{
    int temp;
    printf("read\n");
    pthread_mutex_lock(&number_mutex);
    temp = globalnumber;
    pthread_mutex_unlock(&number_mutex);
    return temp;
}

void *thread1(int *arg)
{
    int temp;
    write_globalnumber();
    temp = read_globalnumber();
    printf("%d\n",temp);
}




int main(void)
{
    pthread_t thid1;

    printf("running!\n");
    pthread_create(&thid1,NULL,(void *)thread1,NULL);
    pthread_join(thid1,NULL);
}
