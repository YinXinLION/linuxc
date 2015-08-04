/*************************************************************************
	> File Name: env.c
	> Author: 
	> Mail: 
	> Created Time: 2015年08月03日 星期一 17时48分59秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

extern char **environ;

int main(int argc ,char *argv[],char **envp)
{
    int i;

    printf("AArgument:\n");
    for(i=0;i < argc ; i++)
    {
        printf("argv[%d] is %s\n",i,argv[i]);
    }

    printf("Environment:\n");

    for(i=0;envp[i] != NULL; i++)
    printf("%s\n",envp[i]);

    return 0;
}
