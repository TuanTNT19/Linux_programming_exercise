#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>
typedef struct{
    char name[20];
    char tuoi[2];
}infor_t;
char readchar[50];
char str[26];
int main()
{
    infor_t person;
    int fd = open("text.txt",O_RDWR | O_CREAT | O_APPEND,0667);
    if (fd ==-1)
    {
        printf("Can not create file txt\n");
    }
    printf("Nhap name : ");
    gets(person.name);
    printf("Nhap tuoi: ");
    gets(person.tuoi);
    sprintf(str,"%s %s \n",person.name,person.tuoi);
    int w1 = write(fd,str,strlen(str));
    if (w1==-1)
    {
        printf("Can not write name \n");
    }
    //sleep(1);
    lseek(fd,0,SEEK_SET);
    int r = read(fd,readchar,sizeof(readchar));
    printf("%s\n",readchar);
    close(fd);
    return 0;
}