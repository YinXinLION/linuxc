/*************************************************************************
	> File Name: server.c
	> Author:YinXin 
	> Mail:yinxin19950816@gmail.com 
	> Created Time: 2015年09月05日 星期六 20时36分03秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<errno.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<sys/socket.h>

#define SERV_PORT 4507 //服务器端的端口
#define LISTENQ   12   //连接请求队列的最大长度

#define USERNAME     1
#define USERPASSWORD 2

struct userinfo{
    char username[32];
    char password[32];
    struct userinfo *next;
};

struct conn{
    int fd;//套接字
    char name[20];//客户主机名称
}client[LISTENQ];


int find(const char *name ,const int sign);
struct userinfo *creat_node();
void serv_client(int sock_fd);
void log_user(int sock_fd);
void register_user(int sock_fd);





void my_err(const char *err_string ,int line)
{
    fprintf(stderr ,"line:%d ",line);
    perror("err_string");
    exit(1);
}
int find(const char *name ,const int sign)
{
    int i;
    struct userinfo *head ,p;
    struct userinfo *p1 ,*p2;
    FILE *fp;
    fp = fopen("userinfo" ,"rb+");
    head = p2 = creat_node();
    while(2 == fscanf(fp ,"%s %s\n",p.username,p.password))
    {
        p1 = creat_node();
        strcpy(p1 -> username , p.username);
        strcpy(p1 -> password , p.password);
        p2 -> next = p1;
        p2 = p1;
    }
    p2 -> next = NULL;
    fclose(fp);
    p1 = head -> next;
    if(sign == 1)
    {
        if(p1 == NULL)
        {
            return -1;
        }
        for( ; p1 != NULL ; p1 = p1 -> next )
        {
            if(strcmp(p1 -> username , name) == 0)
            {
                for(i = 0; i < LISTENQ ; i++)
                strcmp(client[i].name , name);
                return 1;
            }
        }
        return -1;
    }
    if(sign == 2)
    {
        for( ; p1 != NULL ; p1 = p1 -> next )
        {
            if(strcmp(p1 -> password , name) == 0)
            {
                return 1;
            }
        }
        return -1;
    }
}

struct userinfo *creat_node()
{
    struct userinfo *head;
    head = (struct userinfo*)malloc(sizeof(struct userinfo));
    head -> next = NULL;
    return head;
}

//发送数据
void send_data(int conn_fd ,const char *string)
{
    if(send(conn_fd ,string ,strlen(string) ,0) < 0)
    {
        my_err("send",__LINE__);
    }
}

int main(void)
{
    int server_fd ,client_fd;//套接字
    int optval;//保存待设定的套接字选项的值
    struct sockaddr_in    cli_addr ,serv_addr;
    int i;
    socklen_t   cli_len; //sockaddr_in结构体大小
    FILE *fp;
    pid_t pid;
    //创建一个TCP套接字
    server_fd = socket(AF_INET ,SOCK_STREAM ,0);
    if(server_fd < 0)
    {
        my_err("socket",__LINE__);
    }

    //设置该套接字使之可以重新绑定端口
    optval = 1;
    if(setsockopt(server_fd ,SOL_SOCKET ,SO_REUSEADDR ,(void *)&optval ,sizeof(int)) < 0)
    {
        my_err("socket",__LINE__);
    }

    //初始化服务器地址结构
    memset(&serv_addr ,0 ,sizeof(struct sockaddr_in));
    serv_addr.sin_family      = AF_INET;  //ipv4协议
    serv_addr.sin_port        = htons(SERV_PORT); //端口号
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);//处理所有连接请求

    //将套接字绑定到本地端口
    if(bind(server_fd ,(struct sockaddr*)&serv_addr ,sizeof(struct sockaddr_in)) < 0)
    {
        my_err("bind",__LINE__);
    }

    //将套接字转化为监听套接字
    if(listen(server_fd ,LISTENQ) < 0)
    {
        my_err("listen",__LINE__);
    }

    //初始化队列套接字
    for( i = 0 ; i < LISTENQ ; i++ )
    {
        client[i].fd = -1;
    }

    cli_len = sizeof(struct sockaddr_in);//客户端套接字长度
    while(1)
    {
        for( i = 0; i < LISTENQ ; i++ )
        {
            if(client[i].fd == -1)
            break;
        }
        //通过accept接收客户端的连接请求，并返回连接套接字用于收发数据
        client[i].fd = accept(server_fd ,(struct sockaddr *)&cli_addr ,&cli_len);

        if(client[i].fd < 0)
        {
            my_err("accept",__LINE__);
            exit(1);
        }
        else{
            printf("accept a new client ,IP:%s\n",inet_ntoa(cli_addr.sin_addr));//新客户端连接 ，服务器显示客户端连接的IP
            fp = fopen("sys_log" ,"at+");
            fprintf(fp ,"accept a new client ,IP:%s\n",inet_ntoa(cli_addr.sin_addr));
            fclose(fp);
        }
        //创建子进程，服务客户端
        pid = fork();
        switch(pid)
        {
            case 0:
            serv_client(client[i].fd);
        }
    }
}

void serv_client(int sock_fd)
{
    int     ret;
    char    recv_buf[10];
    int     num;
    if((ret = recv(sock_fd ,recv_buf ,sizeof(recv_buf) ,0)) < 0)
    {
        perror("recv");
        exit(1);
    }
    recv_buf[ret] = '\0'; //将数据结束标志'\n'替换成字符串结束标
    num = atoi(recv_buf);
    switch(num)
    {
    case 1:
        register_user(sock_fd);
        break;
    case 2:
        log_user(sock_fd);
        break;
    }
    send_message(sock_fd);
    

}

void log_user(int sock_fd)
{
    int name_num;
    int ret;
    char recv_buf[128];
    int     flag_recv = USERNAME;
    while(1)
    {
        if((ret = recv(sock_fd ,recv_buf ,sizeof(recv_buf) ,0)) < 0)
        {
            perror("recv");
            exit(1);
        }
        recv_buf[ret] = '\0'; //将数据结束标志'\n'替换成字符串结束标志
        if(flag_recv == USERPASSWORD)
        {
            name_num = find(recv_buf ,2);
            if(name_num == -1)
            {
                send_data(sock_fd ,"n");
            }
            if(name_num == 1)
            {
                send_data(sock_fd ,"y");
                break;
            }
        }
        if(flag_recv == USERNAME)
        {
            name_num = find(recv_buf ,1);
            if(name_num == -1)
            {
                send_data(sock_fd ,"n");
            }
            if(name_num == 1)
            {
                send_data(sock_fd,"y");
                flag_recv = USERPASSWORD;
            }
        }
    }
}

void register_user(int sock_fd)
{
    int  i;
    int  ret;
    char recv_name[32];
    char recv_password[32];
    FILE *fp;
    if((ret = recv(sock_fd ,recv_name ,sizeof(recv_name) ,0)) < 0)
    {
        perror("recv");
        exit(1);
    }
    recv_name[ret] = '\0'; //将数据结束标志'\n'替换成字符串结束标志
    

    if((ret = recv(sock_fd ,recv_password ,sizeof(recv_password) ,0)) < 0)
    {
        perror("recv");
        exit(1);
    }
    recv_password[ret] = '\0';
    fp = fopen("userinfo","at+");
    for(i = 0; i < LISTENQ ; i++)
    {
        if(sock_fd == client[i].fd)
        strcpy(client[i].name , recv_name);
    }
    fprintf(fp,"%s %s\n",recv_name,recv_password);
    fclose(fp);

    for(i = 0; i < LISTENQ ;i++)
    {
        if(client[i].fd == sock_fd)
        strcpy(client[i].name , recv_name);
    }

}

void send_message()
{

    while(1)
    {
    if((ret = recv(sock_fd ,recv_buf ,sizeof(recv_buf) ,0)) < 0)
    {
        perror("recv");
        exit(1);
    } 
    recv_buf[ret] = '\0'; //将数据结束标志'\n'替换成字符串结束标
    num = atoi(recv_buf);
        switch(num)
        {
            case 1:
            send_name(sock_fd);
        }
    }
}

void send_name()
{   
    int i;
    int number = 0;
    char buffer[50];
    for(i = 0; i < LISTENQ ; i++)
    {
        if(client[i].fd != -1)
        number++;
    }
    sprintf(buffer ,"%d" ,number);
    send_data(sock_fd ,buffer);
    for(i = 0; i < LISTENQ ; i++)
    {
        if(client[i].fd != -1 && client[i].fd != sock_fd )
        {
            send_data(sock_fd , client[i].name);
        }
    }

}
