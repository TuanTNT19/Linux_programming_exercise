#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>


#define FIFO1 "./f1"
#define FIFO2 "./f2"
int fd1, fd2;

int main()
{
    char buff_r[50];
    char buff_s[50];

    fd1 = open(FIFO1, O_RDONLY);    //FIFO 1 only need to read in this process
    fd2 = open(FIFO2, O_WRONLY);    //FIFO 2 only need to write in this process
    
    while(1)
    {
        printf("Message to process 1: ");
        fgets(buff_s, 50, stdin);
        write(fd2, buff_s, 50);

        printf("Message from process 1: ");
        read(fd1, buff_r, 50);
        printf("%s",buff_r);
    }

    close(fd1);
    close(fd2);

    return 0;
}