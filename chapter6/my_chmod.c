/*************************************************************************
	> File Name: my_chmod.c
	> Author: 
	> Mail: 
	> Created Time: 2015年07月25日 星期六 08时48分51秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>

int main(int argc ,char **argv)
{
    int mode;
    int mode_user;
    int mode_group;
    int mode_other;
    char *path;

    if(argc<3)
    {
        printf("intput little");
        exit(1);
    }
    mode=atoi(argv[1]);
    if(mode<0||mode>777)
    {
        printf("error");
        exit(0);
    }
    mode_user=mode/100;
    mode_group=mode%100/10;
    mode_other=mode%10;

    mode=mode_user*8*8+mode_group*8+mode_other;
    path=argv[2];
    if(chmod(path,mode)==-1)
    {
        perror("F");
        exit(1);
    }
   

}
