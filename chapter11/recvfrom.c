/*************************************************************************
	> File Name: recvfrom.c
	> Author:YinXin 
	> Mail:yinxin19950816@gmail.com 
	> Created Time: 2015年08月19日 星期三 22时59分41秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/socket.h>

#define  BUFFERSIZE   1500

char   recv_buf[BUFFERSIZE];
struct  sockaddr_in  src_addr;
int src_len;

src_len = sizeof(struct sockaddr_in);
if(recvfrom(sock_fd ,recv_buf ,sizeof(recv_buf), 0,(struct sockaddr *)&src_addr,&src_len) < 0)
{
    perror("again_recvfrom");
    exit(1);
}
