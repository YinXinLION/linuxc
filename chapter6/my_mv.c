/*************************************************************************
	> File Name: my_mv.c
	> Author: 
	> Mail: 
	> Created Time: 2015年07月29日 星期三 14时53分52秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
int main(int  argc, char **argv[])
{
    //检查参数个数的合法性
    if(argc<3)
    {
        printf("my_mv <old file> <new file>");
        exit(0);
    }
    if(rename(argv[1],argv[2]))
    {
        perror("rename");
        exit(1);
    }
    return 0;
}
