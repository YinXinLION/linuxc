/*************************************************************************
	> File Name: send.c
	> Author:YinXin 
	> Mail:yinxin19950816@gmail.com 
	> Created Time: 2015年08月19日 星期三 22时21分21秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>

#define BUFFERSIZE   1500
char  send_buf[BUFFERSIZE];
...
if(send(conn_fd , send_buf , len ,0) < 0) //len为待发送数据的长度
{
    perror("send");
    exit(1);
}
