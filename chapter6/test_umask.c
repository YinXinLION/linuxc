/*************************************************************************
	> File Name: test_umask.c
	> Author: 
	> Mail: 
	> Created Time: 2015年07月29日 星期三 15时31分23秒
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
int main()
{
    umask(0);   //不屏蔽任何权限
    if(creat("test",S_IRWXU|S_IRWXG|S_IRWXO)<0)
    {
        perror("creat");
        exit(0);
    }

    umask(S_IRWXO);
    if(creat("test1",S_IRWXU|S_IRWXG|S_IRWXO)<0)
    {
        perror("creat");
        exit(1);
    }
    return 0;
}
