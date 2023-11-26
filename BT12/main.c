#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER ;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
pthread_cond_t condt = PTHREAD_COND_INITIALIZER;
pthread_cond_t condk = PTHREAD_COND_INITIALIZER;
pthread_t id1,id2,id3;
typedef struct{
    char name[20];
    char born[10];
    char hown_town[20];
}person;
char str[52];
char readdata[52];
int fd;
int i=0;
int k=0;
int j=0;
static void *func1(void *para)
{
    while(1){
    person *p= (person *)para;
    pthread_mutex_lock(&m);
    printf("i= %d\n",i);
    while(k){
        pthread_cond_wait(&cond,&m);
    }
    printf("Enter name: ");
    gets(p->name);
    printf("Enter born year: ");
    gets(p->born);
    printf("Enter hown town: ");
    gets(p->hown_town);
    i++;
    k=1;
    j=1;
    pthread_cond_signal(&condt);
    pthread_cond_signal(&condk);
    pthread_mutex_unlock(&m);
    }
}
static void *func2(void *para)
{
    while(1){
    pthread_mutex_lock(&m);
       while(!j){
        pthread_cond_wait(&condt,&m);
    }
    person *p= (person *)para;
    sprintf(str,"%s %s %s\n",p->name,p->born,p->hown_town);
    int w=write(fd,str,strlen(str));
    if (w==-1)
    {
        printf("Can not write data\n");
    }
    j=0;
    }
    pthread_mutex_unlock(&m);
}
static void *func3(void *para)
{
    while(1){
      //  printf("Check 0\n");
    pthread_mutex_lock(&m);
    while(!k){
    pthread_cond_wait(&condk,&m);
    }
    person *p= (person *)para;
    sprintf(readdata,"%s %s %s\n",p->name,p->born,p->hown_town);
    printf("%s",readdata);
    k=0;
    int pt=pthread_cond_signal(&cond);
    if (pt==-1)
    {
        printf("Can not send signal\n");
    }
    else{
        printf("Send signal\n");
    }
    pthread_mutex_unlock(&m);
   }

}
int main()
{
    person pe;
    fd = open("text.txt",O_RDWR | O_CREAT | O_APPEND,0667);
    
    if (pthread_create(&id1,NULL,&func1,&pe))
    {
        printf("Create thread1 error\n");
    }
       
    if (pthread_create(&id2,NULL,&func2,&pe))
    {
        printf("Create thread2 error\n");
    }
    if (pthread_create(&id3,NULL,&func3,&pe))
    {
        printf("Create thread3 error\n");
    }

    while(1);
    close(fd);
    return 0;
}