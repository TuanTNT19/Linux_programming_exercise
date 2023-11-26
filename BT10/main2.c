#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
pthread_t id;

static void *task(void *argv)
{
    for (int i=0;i<1000;i++)
    {
        printf("Checking.....\n");
    }
    pthread_exit(NULL);
}
int main()
{
    clock_t start_time = clock();
    pthread_create(&id,NULL,&task,NULL);
    clock_t  end_time = clock();
    clock_t time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Time_used: %ld",time_used);
    return 0;

}