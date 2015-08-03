/*************************************************************************
	> File Name: my_chmod2.c
	> Author: 
	> Mail: 
	> Created Time: 2015年07月31日 星期五 10时33分10秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>

int i;
int mode=0;
int mode_user;
int mode_group;
int mode_other;

void rst(char *argv,char *path);

int main(int argc , char ** argv)
{
    char *path;
    if(argc<3)
    {
        printf("%s <mode num >||<name+rwx>  <target File>",argv[0]);
        exit(0);
    }
    if((argv[1][1]=='+')||(argv[1][1]=='-'))
        rst(argv[1],argv[2]);
    path = argv[2];
    if(chmod(path,mode)==-1)
    {
        perror("error");
        exit(1);
    }
    

}

void rst(char *argv,char *path)
{
    struct stat buf;
    stat(path,&buf);
    mode_user=buf.st_mode%512/64;
    mode_group=buf.st_mode%64/8;
    mode_other=buf.st_mode%8;
    mode=mode_user*8*8+mode_group*8+mode_other;
    printf("%d %d %d \n",mode_user,mode_group,mode_other);
    if(argv[1]=='-')
    {
        if(argv[0]=='u')
        {        
            switch(argv[2])
            {
                case 'r':
                case 'R': mode_user&=3;
                          break;
                case 'w':
                case 'W':mode_user&=5;
                          break;
                case 'x':
                case 'X':mode_user&=6;
                         break;
            }
        }
        if(argv[0]=='g')
        {
            switch(argv[2])
            {       
                case 'r':
                case 'R': mode_group&=3;
                          break;
                case 'w':
                case 'W':mode_group&=5;
                          break;
                case 'x':
                case 'X':mode_group&=6;
                         break;
            }
        }
        if(argv[0]=='o')
        { 
            switch(argv[2])
            {
                case 'r':
                case 'R': mode_other&=3;
                          break;
                case 'w':
                case 'W':mode_other&=5;
                          break;
                case 'x':
                case 'X':mode_other&=6;
                         break;
        }   }
    }
    if(argv[1]=='+')
    {
             
        if(argv[0]=='u')
        { 
            switch(argv[2])
            {
                case 'r':
                case 'R': mode_user|=4;
                          break;
                case 'w':
                case 'W':mode_user|=2;
                          break;
                case 'x':
                case 'X':mode_user|=1;
                         break;
            }
        }
        if(argv[0]=='g')
        { 
            switch(argv[2])
            {
                case 'r':
                case 'R': mode_group|=4;
                          break;
                case 'w':
                case 'W':mode_group|=2;
                          break;
                case 'x':
                case 'X':mode_group|=1;
                         break;
            }
        }
        if(argv[0]=='o')
        { 
            switch(argv[2])
            {
                case 'r':
                case 'R': mode_other|=4;
                          break;
                case 'w':
                case 'W':mode_other|=2;
                          break;
                case 'x':
                case 'X':mode_other|=1;
                         break;
            }
        }
    }
    mode = mode_user*8*8 + mode_group*8 + mode_other;
}
