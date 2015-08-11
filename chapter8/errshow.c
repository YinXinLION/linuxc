/*************************************************************************
	> File Name: errshow.c
	> Author:YinXin 
	> Mail:yinxin19950816@gmail.com 
	> Created Time: 2015年08月11日 星期二 10时20分30秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

FILE * open_file(char *filename)
{
    FILE *stream;
    errno = 0;

    stream = fopen(filename , "r");
    if( stream == NULL )
    {
        printf("can not open the file %s.reason: %s\n",filename,strerror(errno));
        exit(1);
    }
    else
    return stream;
}

int main(void)
{
    char *filename = "test";

    open_file(filename);
    return 0;
}
