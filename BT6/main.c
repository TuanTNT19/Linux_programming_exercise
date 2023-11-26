#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

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
        while(1);
        printf("End child process\n");
        
    }
    else{
        
       
        printf("I am the parent process \n");
        printf("My PID id %d \n",getpid());
        int status;
        waitpid(child_pid, &status, 0);
        printf("Status : %d\n",status);
          if (WIFEXITED(status)) {
            printf("Child process with PID exited with status %d\n",  WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("Child process was killed by signal with status %d\n",  WTERMSIG(status));
        }
        printf("End of parrent process \n");
    }

    }
    else{
        printf("Fork unsuccessfully\n");
    }
    return 0;
}