/*************************************************************************
	> File Name: my_recv.h
	> Author:YinXin 
	> Mail:yinxin19950816@gmail.com 
	> Created Time: 2015年08月22日 星期六 19时44分57秒
 ************************************************************************/

#ifndef _MY_RECV_H
#define _MY_RECV_H

    #define  BUFSIZE 1024
    void my_err(const char *err_string ,int line);
    int  my_recv(int conn_fd ,char *data_buf ,int len);
#endif
