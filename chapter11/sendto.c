/*************************************************************************
	> File Name: sendto.c
	> Author:YinXin 
	> Mail:yinxin19950816@gmail.com 
	> Created Time: 2015年08月19日 星期三 22时42分16秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h> 

#define  BUFFERSIZE  1500

char  send_buf[BUFFERSIZE];
struct sockaddr_in    dest_addr;

//设置目的地址
memset(&dest_addr , 0 , sizeof(struct sockaddr_in));
dest_addr.sin_family = AF_INET;
dest_addr.sin_port   = htons(DEST_PORT);
//
if(inet_aton("172.17.242.131",&dest_addr.sin_addr) < 0)
{
    perror("inet_aton");
    exit(1);
}

if( sendto (sock_fd, send_buf , len ,0 ,(struct sockaddr *)&dest_addr,sizeof(struct sockaddr_in)) < 0 )
{
    perror("sendto");
    exit(1);
}
