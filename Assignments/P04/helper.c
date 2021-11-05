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

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 4 // Defining 4 threads
#define ARR_SIZE 4

int Arr_A[ARR_SIZE];
int Arr_B[ARR_SIZE];

double Add_Sum = 0;
double Sub_Sum = 0;
double Mul_Sum = 0;
double Div_Sum = 0;

void *Operation(void *t)
{
    intptr_t  t_id = (intptr_t)t;        // long long intptr_t

    for (int i = (t_id  * ARR_SIZE) / 4; i < (t_id + 1) * ARR_SIZE / 4; i++)
    {
        Add_Sum += Arr_A[i] + Arr_B[i];

        Sub_Sum += Arr_A[i] - Arr_B[i];

        Mul_Sum += Arr_A[i] * Arr_B[i];

        Div_Sum += (double)Arr_A[i] / (double)Arr_B[i];
    }
    pthread_exit((void *)t); // End Of Thread
}

int main(int argc, char *argv[])
{
    pthread_t thread_ids[NUM_THREADS];

    pthread_attr_t attr;
    int rc;
    long t;
    void *status;

    /* Initialize and set thread detached attribute */
    pthread_attr_init(&attr);

    // Initialize Array Data for both A and B
    for (int i = 0; i < ARR_SIZE; i++)
    {
        Arr_A[i] = 1;
        Arr_B[i] = 2;
    }

    for (t = 0; t < NUM_THREADS; ++t) // Creating four threads, each evaluating its own part
    {
        rc = pthread_create(&thread_ids[t], &attr, Operation, (void *)t);

        if (rc)
        {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    pthread_attr_destroy(&attr);

    for (size_t i = 0; i < NUM_THREADS; i++) // Joining and waiting for all threads to complete
    {
        rc = pthread_join(thread_ids[i], NULL);
        if (rc)
        {
            printf("ERROR; return code from pthread_join() is %d\n", rc);
            exit(-1);
        }
    }

    // printf("\n --- Matrix ---\n\n");
    // printf("\n -- A    B ---\n\n");

    // for(int x = 0; x < ARR_SIZE; x++)
    // {
    //     printf("%5d",Arr_A[x]);
    //     printf("%5d",Arr_B[x]);
    //     printf("\n\n");
    // }

    // Displaying the result matrix
    printf("\nAddition summation is:       %f\n", Add_Sum);
    printf("Susbtraction  summation is: %f\n", Sub_Sum);
    printf("Multipliaction summation is: %f\n", Mul_Sum);
    printf("Division summation is:       %f\n", Div_Sum);
      
    pthread_exit(NULL);
}