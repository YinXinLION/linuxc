#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

//自定义的错误处理函数
void my_err(const char * err_string, int line)
{
    fprintf(stderr, "line:%d", line);
    perror(err_string);
    exit(1);
}

int main(int argc,char **argv)
{
    int fd;
    char buf[32];
    
    if(argc<2)
    {
        printf("unlink <file name>");
    }

    if(unlink(argv[1]) < 0 )
    {
        my_err("unlink", __LINE__);
    }
    else
    printf("remove success\n");
    
    return 0;
}
