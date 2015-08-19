/*************************************************************************
	> File Name: listen.c
	> Author:YinXin 
	> Mail:yinxin19950816@gmail.com 
	> Created Time: 2015年08月19日 星期三 10时13分22秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>

#define LISTEN_NUM 12 //定义连接请求的队列长度
...
if(listen(sock_fd , LISTEN_NUM) < 0)
{
    perror("listen");
    exit(1);
}
