/*************************************************************************
	> File Name: accept.c
	> Author:YinXin 
	> Mail:yinxin19950816@gmail.com 
	> Created Time: 2015年08月19日 星期三 10时37分24秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>

int client_fd;
int client_len;
struct sockaddr_in   client_addr;
...
client_len = sizeof(struct sockaddr_in);
client_fd  = accept(sock_fd , (struct sockaddr *)&client_addr , &client_len);

if(conn_fd < 0)
{
    perror("accpet");
    exit(1);
}
