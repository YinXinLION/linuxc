/*************************************************************************
	> File Name: client.c
	> Author:YinXin 
	> Mail:yinxin19950816@gmail.com 
	> Created Time: 2015年09月06日 星期日 19时52分24秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#include<netinet/in.h>
#include<arpa/inet.h>


#define   BUFSIZE 1024
#define   INVALID_USERINFO 'n'
#define   VALID_USERINFO 'y'


void log_in(int socket);
void login_menu(int socket); //登陆菜单
void input_userinfo(int socket,const char *string); //输入用户名和密码
void register_user(int socket); //用户注册
void register_userinfo(int socket ,const char *string);

void chat_menu();



char name[32];
int  flag = 1;
void my_err(const char *err_string ,int line)
{
    fprintf(stderr ,"line:%d " ,line);
    perror("err_string");
    exit(1);
}

int main(int argc ,char **argv)
{
    int i;
    int client_fd;
    int serv_port;
    struct sockaddr_in serv_addr;
    char recv_buf[BUFSIZE];

    //检查参数个数
    if(argc != 5)
    {
        printf("Usage: [-p] [serv_port4507] [-a] [serv_address]\n");
        exit(1);
    }

    //初始化服务器端地址结构
    memset(&serv_addr ,0 ,sizeof(struct sockaddr_in));
    serv_addr.sin_family = AF_INET;
    //从命令行获取服务器端的端口与地址
    for(i = 1 ; i < argc ; i++)
    {
        if(strcmp("-p" ,argv[i]) == 0)
        {
            serv_port = atoi(argv[i+1]);
            if(serv_port < 0 || serv_port > 65535)
            {
                printf("invalid serv_addr.sin_port\n");
                exit(2);
            }
            else{
                serv_addr.sin_port = htons(serv_port);
            }
            continue;
        }
        if(strcmp("-a",argv[i]) == 0){
            if(inet_aton(argv[i+1],&serv_addr.sin_addr) == 0)
            {
                printf("invalid server ip address\n");
                exit(1);
            }
            continue;
        }
    }

    //检测是否少输入了某项
    if(serv_addr.sin_port == 0 || serv_addr.sin_addr.s_addr == 0){
        printf("Usage: [-p] [serv_addr.sin_port] [-a] [serv_address]\n");
        exit(1);
    }
    
    //创建一个TCP套接字
    client_fd = socket(AF_INET ,SOCK_STREAM ,0);
    if(client_fd < 0)
    {
        my_err("socket",__LINE__);
    }

    //向服务器端发送连接请求
    if(connect(client_fd ,(struct sockaddr*)&serv_addr ,sizeof(struct sockaddr_in)) < 0)
    {
        my_err("connect",__LINE__);
    }

    login_menu(client_fd);
    
}

void login_menu(int socket) //登陆菜单
{
    int i;
    char send_[5];
    printf("1.注册\n");
    printf("2.登陆\n");
    scanf("%d",&i);
    fflush(stdin);
    switch(i)
    {
        case 1:
        strcpy(send_ , "1");
        send(socket ,send_ ,strlen(send_) ,0);
        register_user(socket); //用户注册
        break;
        case 2:
        strcpy(send_ ,"2");
        send(socket ,send_ ,strlen(send_) ,0);
        log_in(socket);
        break;
        default:
        exit(1);
    }
    chat_menu(socket);
}

void input_userinfo(int socket,const char *string)  //输入用户名和密码
{
    char input_buf[32];
    char recv_buf[BUFSIZE];
    int  flag_userinfo = INVALID_USERINFO;
    //输入到用户信息正确位置
    do{
        printf("%s:",string);
        scanf("%s",input_buf);
        fflush(stdin);
        if(strlen(input_buf) == 0)
        {
            printf("errno return from get_userinfo");
        }
        
        if(send(socket ,input_buf ,strlen(input_buf) ,0) < 0) //发送数据
        {
            my_err("send",__LINE__);
        }
        
        if(recv(socket ,recv_buf ,sizeof(recv_buf) ,0) < 0)
        {
            printf("data is too long\n");
            exit(1);
        }

        if(recv_buf[0] == VALID_USERINFO )
        {
            flag_userinfo = VALID_USERINFO;
        }
        else
        {
            flag_userinfo = INVALID_USERINFO;
        }
    }while(flag_userinfo == INVALID_USERINFO);

    if((flag++)== 1)
    {
        strcpy(name , input_buf);
    }

}

void log_in(int socket)
{
    input_userinfo(socket,"用户名");
    input_userinfo(socket,"密码");
    printf("登陆成功！");
}

void register_user(int socket) //用户注册
{   
    char  compare[32];
    char  _true[32];
    register_userinfo(socket,"用户名");
    while(1)
    {
        printf("密码:");
        scanf("%s",compare);
        fflush(stdin);
        printf("再次输入密码");
        scanf("%s",_true);
        fflush(stdin);
        if(strcmp(compare , _true) == 0)
        {
            break;
        }
        else
        {
            printf("密码不一致，请重新输入");
        }
    }
    if(send(socket ,_true ,strlen(_true) , 0) < 0 )
    {
        my_err("send",__LINE__);
    }
    else
    {
        printf("注册成功！");
    }

}

void register_userinfo(int socket ,const char *string)
{
    char input_buf[32];
    char recv_buf[BUFSIZE];
    printf("%s:",string);
    scanf("%s",input_buf);
    fflush(stdin);
    if(strlen(input_buf) == 0)
    {
        printf("errno return get_userinfo");
    }

    if(send(socket ,input_buf ,strlen(input_buf), 0) < 0)
    {
        my_err("send",__LINE__);
    }
    strcpy(name , input_buf);
}

void chat_menu(int socket)
{
    int input ,i;
    int number;
    char _num[2];
    char recv_buf[BUFSIZE];
    printf("%s用户\n",name);
    printf("        1.查看在线de人\n");
    printf("        2.添加在线de人\n");
    scanf("%d",&input);
    fflush(stdin);
    if(input == 1)
    {
        strcpy(_num , "1");
        send(socket , _num , strlen(_num) ,0);
        if(recv(socket ,recv_buf ,sizeof(recv_buf) ,0) < 0)
        {
            printf("接收失败");
            perror("recv");
            exit(1);
        }
        number = atoi(recv_buf);
        printf("在线人数:%d",number);
        for(i = 0; i < number ; i++)
        {
            if(recv(socket ,recv_buf ,sizeof(recv_buf), 0) < 0)
            {
            printf("接收失败");
            perror("recv");
            exit(1);
            }
            printf("%d:%s",i ,recv_buf);
        }
        
        
    }

}
