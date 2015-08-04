/*************************************************************************
	> File Name: diffork.c
	> Author: 
	> Mail: 
	> Created Time: 2015年08月03日 星期一 10时16分15秒
 ************************************************************************/

#include<stdio.h>    // fork()和vfor()的区别
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int globVar = 5;

int main(void)
{
    pid_t pid;
    int var = 1 , i;

    printf("fork is different with vfork \n");

  //  pid = fork();
    pid = vfork();
    switch(pid)
    {
        case 0:
        i=3;
        while(i-- > 0)
        {
            printf("Child process is running\n");
            globVar++;
            var++;
            sleep(1);
        }
        printf("Child's globVar = %d ,var = %d\n",globVar , var);
        break;

        case -1:
        perror("Process creation is running\n");
        exit(0);

        default:
        i = 5;
        while(i-- > 0)
        {
            printf("Parent process is running\n");
            globVar++;
            var++;
            sleep(1);
        }
        printf("Parent's globVar = %d , var = %d\n", globVar,var);
        exit(0);
    }
}
