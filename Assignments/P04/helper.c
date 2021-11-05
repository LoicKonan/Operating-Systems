//program.c

#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 4
#define ARR_SIZE 10

void *CalculateSum(void *);
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

int dimensional_array[ARR_SIZE];

int Arr_A[ARR_SIZE];
int Arr_B[ARR_SIZE];

double Mul_Sum = 0;

main()
{
	pthread_t thread_id[NUM_THREADS];

	for (int i = 0; i < ARR_SIZE; i++)
	{
		Arr_A[i] = 1;
		Arr_B[i] = 2;
	}

	for (int i = 0; i < NUM_THREADS; i++)
	{
		pthread_create(&thread_id[i], NULL, CalculateSum, NULL);
	}

	for (int i = 0; i < NUM_THREADS; i++)
	{
		pthread_join(thread_id[i], NULL);
	}

	// print ARRAY
	for (int i = 0; i < ARR_SIZE; i++)
	{
		printf("%d\t", Arr_A[i]);
		printf("%d\t", Arr_B[i]);
		printf("\n");
	}
}
//Calculate
void *CalculateSum(void *dummyPtr)
{
	pthread_mutex_lock(&mutex1);

	for (int i = 0; i < ARR_SIZE; i++)
	{
		Mul_Sum += Arr_A[i] * Arr_B[i];
		printf(" Mul_Sum = %d\n", Mul_Sum);
	}

	pthread_mutex_unlock(&mutex1);
}