/*************************************************************************
	> File Name: studyuid.c
	> Author:YinXin 
	> Mail:yinxin19950816@gmail.com 
	> Created Time: 2015年08月04日 星期二 20时30分51秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<time.h>
#include<unistd.h>
#include<syslog.h>
#include<signal.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>

extern int errno;

int main()
{
    int    fd;

    printf("uid study: \n");
    printf("Process's  uid = %d,euid = %d\n",getuid(),geteuid());
    setuid(0);
    //strerror 函数获取指定错误码的提示信息
    if((fd = open("test.c",O_RDWR)) == -1)
    {
        printf("Open failure,errno is %d : %s \n",errno,(char *)strerror(errno));
        exit(1);
    }
    else{
        printf("Open successfully!\n");
    }

    close(fd);
    exit(0);

}
