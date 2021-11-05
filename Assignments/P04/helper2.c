#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct data
{
    int *arr;
    int thread_num;
} data;

int arrSize = 10;

void *halfSum(void *p)
{
    data *ptr = (data *)p;
    int n = ptr->thread_num;

    // Declare sum dynamically to return to join:
    int *thread_sum = (int *)calloc(1, sizeof(int));

    for (int i = 0; i < arrSize; i++)
        thread_sum[0] = thread_sum[0] + ptr->arr[i];

    pthread_exit(thread_sum);
}

int main(void)
{
    int *int_arrA = (int *)calloc(arrSize, sizeof(int));
    for (int i = 0; i < arrSize; i++)
        int_arrA[i] = 1;

    int *int_arrB = (int *)calloc(arrSize, sizeof(int));
    for (int i = 0; i < arrSize; i++)
        int_arrB[i] = 2;

    // Declare arguments for both threads:
    data thread_data[4];
    thread_data[0].thread_num = 0;
    thread_data[0].arr = int_arrA;
    thread_data[1].thread_num = 1;
    thread_data[1].arr = int_arrA;

    // Declare thread IDs:
    pthread_t tid[4];

    // Start both threads:
    pthread_create(&tid[0], NULL, halfSum, &thread_data[0]);
    pthread_create(&tid[1], NULL, halfSum, &thread_data[1]);

    // Declare space for sum:
    int *sum0;
    int *sum1;

    // Retrieve sum of threads:
    pthread_join(tid[0], (void **)&sum0);
    pthread_join(tid[1], (void **)&sum1);

    printf("Sum of whole array = %i\n", *sum0 + *sum1);

    return 0;
}