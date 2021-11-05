/*
	Name/s: Loic Konan & Byron Dowling
	Class: 5133 Advanced Computer Architecture
	Date: 11/3/2021
	Assignment: Homework #5 Pthreads Programming
	
	Details:
		- Perform the Addition of A + B
        - Perform the Difference of A - B
        - Perform the Product of A * B
        - Perform the Quotient of A / B

*/

#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 4
#define ARR_SIZE 5

void *DoStuff(void *);
pthread_mutex_t mutex1;

int Arr_A[ARR_SIZE];
int Arr_B[ARR_SIZE];

int Arr_Sum[ARR_SIZE];
int Arr_Sub[ARR_SIZE];
int Arr_Mul[ARR_SIZE];
double Arr_Div[ARR_SIZE];

double Add_Sum = 0;
double Sub_Sum = 0;
double Mul_Sum = 0;
double Div_Sum = 0;

// // Calculate
// void *DoStuff(void *dummyPtr)
// {
// 	pthread_mutex_lock(&mutex1);

// 	for (int i = 0; i < ARR_SIZE; i++)
// 	{
// 		Arr_Mul[i] = Arr_A[i] * Arr_B[i];
// 		Mul_Sum += Arr_Mul[i];
// 	}
// 	pthread_mutex_unlock(&mutex1);
// }


void *DoStuff(void *t)
{
    long t_id;
    t_id = ((long)t + 1);

    for (int i = ((t_id - 1) * ARR_SIZE); i < (t_id * ARR_SIZE - 1); i++)
    {
        Arr_Sum[i] = Arr_A[i] + Arr_B[i];
        Add_Sum += Arr_Sum[i];

        Arr_Sub[i] = Arr_A[i] - Arr_B[i];
        Sub_Sum += Arr_Sub[i];

        Arr_Mul[i] = Arr_A[i] * Arr_B[i];
        Mul_Sum += Arr_Mul[i];

        Arr_Div[i] = (double)Arr_A[i] / (double)Arr_B[i]; 
        Div_Sum += Arr_Div[i];
    }

}

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
		pthread_create(&thread_id[i], NULL, DoStuff, NULL);
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

	printf("Mul summation is: %f\n", Mul_Sum);
}
