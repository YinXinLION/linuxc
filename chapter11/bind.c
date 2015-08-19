/*************************************************************************
	> File Name: bind.c
	> Author:YinXin 
	> Mail:yinxin19950816@gmail.com 
	> Created Time: 2015年08月19日 星期三 10时01分36秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>

struct sockaddr_in    serv_addr;

memset(&serv_addr, 0 ,sizeof(struct sockaddr_in));
serv_addr.sin_family = AF_INET;
serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

if(bind(sock_fd ,(struct sockaddr *)&serv_addr, sizeof(struct sockaddr_in)) <0 )
{
    perror("bind");
    exit(1);
}
