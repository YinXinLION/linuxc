/*************************************************************************
	> File Name: socket.c
	> Author:YinXin 
	> Mail:yinxin19950816@gmail.com 
	> Created Time: 2015年08月18日 星期二 22时46分20秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>

int sock_fd;
sock_fd = socket(AF_INET , SOCK_STREAM,0);
if(sock_fd < 0)
{
    perror("socket");
    exit(1);
}
