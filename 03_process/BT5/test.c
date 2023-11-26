#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
    pid_t child_pid;

    child_pid = fork();
    if (child_pid >=0)
    {
        if (child_pid==0)
    {
        printf("I am the child process \n");
        printf("My PID is : %d , my parent PID is : %d \n",getpid(),getppid());
        sleep(1);
        printf("End child process\n");
    }
    else{
        sleep(1);
        printf("PID of child process is : %d\n",child_pid);
        printf("I am the parent process \n");
        printf("My PID id %d \n",getpid());
        sleep(1);
        printf("End of parrent process \n");
    }

    }
    else{
        printf("Fork unsuccessfully\n");
    }
    return 0;
}