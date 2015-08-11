/*************************************************************************
	> File Name: checkerrno.c
	> Author:YinXin 
	> Mail:yinxin19950816@gmail.com 
	> Created Time: 2015年08月11日 星期二 10时10分02秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

int main(void)
{
    FILE *stream;
    char *filename = "test";

    errno = 0;

    stream = fopen(filename , "r");
    if( stream == NULL ){
        printf("open file %s failed , errno is %d\n",filename,errno);
    }
    else
    printf("open file %s successfully\n",filename);
}
