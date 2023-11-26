#include <stdio.h>
#include <time.h>
void task(){
    for (int i=0;i<1000;i++)
    {
        printf("Checking.....\n");
    }
}
int main()
{
    clock_t start_time = clock();
    task();
    clock_t  end_time = clock();
    clock_t time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Time_used: %ld",time_used);
    return 0;
}