/*************************************************************************
	> File Name: get_cwd.c
	> Author: 
	> Mail: 
	> Created Time: 2015年07月29日 星期三 15时49分57秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>

int main(void)
{
    char buf[10000],*p ;
    getcwd(buf,1000);
    printf("%s\n",buf);
    
}
