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

void *DoStuff(void *t)
{
    long t_id;
    t_id = ((long)t + 1);

    for (int i = ((t_id - 1) * ARR_SIZE); i < (t_id * ARR_SIZE - 1); i++)
    {
        Add_Sum += Arr_A[i] + Arr_B[i];

        Sub_Sum += Arr_A[i] - Arr_B[i];

        Mul_Sum += Arr_A[i] * Arr_B[i];

        Div_Sum += (double)Arr_A[i] / (double)Arr_B[i];
    }
}

main()
{
    pthread_t thread_ids[NUM_THREADS];

    pthread_attr_t attr;
    int rc;
    long t;
    void *status;

    /* Initialize and set thread detached attribute */
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    // Initialize Array Data for both A and B
    for (int i = 0; i < ARR_SIZE; i++)
    {
        Arr_A[i] = 1;
        Arr_B[i] = 2;
    }

    // print ARRAY
    for (int i = 0; i < ARR_SIZE; i++)
    {
        printf("%d\t", Arr_A[i]);
        printf("%d\t", Arr_B[i]);
        printf("\n");
    }
    
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_create(&thread_ids[i], NULL, DoStuff, NULL);
    }

    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(thread_ids[i], NULL);
    }

    // print ARRAY
    for (int i = 0; i < ARR_SIZE; i++)
    {
        printf("%d\t", Arr_A[i]);
        printf("%d\t", Arr_B[i]);
        printf("\n");
    }
    printf("Sum summation is: %f\n", Add_Sum);
    printf("Sub summation is: %f\n", Sub_Sum);
    printf("Mul summation is: %f\n", Mul_Sum);
    printf("Div summation is: %f\n", Div_Sum);

    pthread_exit(NULL);
}
