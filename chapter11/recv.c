/*************************************************************************
	> File Name: recv.c
	> Author:YinXin 
	> Mail:yinxin19950816@gmail.com 
	> Created Time: 2015年08月19日 星期三 22时27分49秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>

#define  BUFFERSIZE  1500
char     recv_buf[BUFFERSIZE];
...
if(recv(conn_fd , recv_buf , sizeof(recv_buf), 0) < 0)
{
    perror("recv");
    exit(1);
}
