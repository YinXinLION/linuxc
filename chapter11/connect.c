/*************************************************************************
	> File Name: connect.c
	> Author:YinXin 
	> Mail:yinxin19950816@gmail.com 
	> Created Time: 2015年08月18日 星期二 22时33分56秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>

struct sockaddr_in     serv_addr;
memset(&serv_addr,0 ,sizeof(struct sockaddr_in));//将serv_addr的各个字段清0
serv_addr.sin_family = AF_INET;//ipv4 tcp/ip协议
serv_addr.sin_port = htons(80);//htons是字节顺序转换函数
//inet_aton函数将一个字符串转换成一个网络地址，并把该网路地址赋给第二个参数
if(inet_aton("172.17.242.131",&serv_addr.sin_addr) < 0)
{
    perroe("inet_aton");
    exit(1);
}
//使用sock_fd套接字连接到由serv_addr指定的目的地址上
int sock_fd;
sock_fd = socket(AF_INET , SOCK_STREAM , 0);
if(sock_fd < 0)
{
    perror("socket");
    exit(1);
}

if(connect(sock_fd, (struct sockaddr *)&serv_addr, sizeof(struct sockaddr_in)) < 0) //serv_addr强制转换为struct sockaddr类型
{
    perror("connect");
    exit(1);
}



