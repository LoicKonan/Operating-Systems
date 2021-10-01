#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int TOTAL = 0;
int array[4000];
void *count(void *tid)
{
    int k = (int)tid; //32-bit
    for (int i = (k * 1000); i < (k + 1) * 1000; i++)
    {
        pthread_mutex_lock(&count_mutex);
        TOTAL = TOTAL + array[i];
        pthread_mutex_unlock(&count_mutex);
    }
    pthread_exit(NULL);
}
int main()
{
    pthread_t threads[4];
    int status, i;
    for (int j = 0; j < 4000; j++)
    {
        array[j] = j + 1;
    }
    pthread_mutex_init(&count_mutex, 0);
    for (i = 0; i < 4; i++)
    {
        status = pthread_create(&threads[i], NULL, count, (void *)i);
        if (status != 0)
        {
            printf("Error");
            exit(-1);
        }
    }
    for (i = 0; i < 4; i++)
    {
        pthread_join(threads[i], NULL);
    }
    pthread_mutex_destroy(&count_mutex);
    printf("%d", TOTAL);
}