#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

/*
pipe 1 :
      writer : parrent
      reader : child
pipe 2:
       writer : child
       reader : parrent
*/

char buff_r[50];
char buff_s[50];

int main()
{

    int fds1[2];
    int fds2[2];
    pid_t child_pid;

    pipe(fds1);     // create pipe1 identified by fds1
    pipe(fds2);     //create pipe2 identifided by fds2

    child_pid = fork();
    
        if (child_pid >= 0)
        {
            if (child_pid == 0)
            {
               // printf("This is child process\n");

                close(fds1[1]); 
                close(fds2[0]);
                
                while(1){
                printf("Message from parrent : ");
                read(fds1[0], buff_r, 50);
                printf("%s",buff_r);

                printf("\nMessage to parrent : ");
                fgets(buff_s, 50, stdin);
                write(fds2[1], buff_s, 50);

                }
                
                close(fds1[0]);
                close(fds2[1]);

            }
            else{
                //printf("This is parrent process\n");

                close(fds1[0]);
                close(fds2[1]);

                while(1)
                {
                    printf("\nMessage to child : ");
                    fgets(buff_s, 50, stdin);
                    write(fds1[1], buff_s, 50);

                    printf("Message from child : ");
                    read(fds2[0], buff_r, 50);
                    printf("%s",buff_r);

                }

                close(fds1[1]);
                close(fds2[0]);
            }
        }

        else{
            printf("Can not fork\n");
        }

    return 0;
}