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

#define NUM_THREADS 4		// Defining 4 threads
#define ARR_SIZE 1000000

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


void *Operation(void *t)
{
    size_t t_id;                                    // unsigned long long size_t
    t_id = ((long)t + 1);

    for (int i = ((t_id - 1) * ARR_SIZE/4); i < (t_id * ARR_SIZE/4 ); i++)
    {
        Add_Sum +=  Arr_A[i] + Arr_B[i];

        Sub_Sum +=  Arr_A[i] - Arr_B[i];

        Mul_Sum +=  Arr_A[i] * Arr_B[i];

        Div_Sum += (double)Arr_A[i] / (double)Arr_B[i];
    }
    pthread_exit(Operation);                        // End Of Thread
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
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    // Initialize Array Data for both A and B
    for (int i = 0; i < ARR_SIZE; i++)
    {
        Arr_A[i] = 1;
        Arr_B[i] = 2;
    }

    for (t = 0; t < NUM_THREADS; ++t)                   // Create Threads 
    {
        rc = pthread_create(&thread_ids[t], &attr, Operation, (void *)t); 
    }

    
    for (size_t i = 0; i < NUM_THREADS ; i++)           // Wait For All Threads Done 
    {
         pthread_join(thread_ids[i], NULL);
    }


    printf("Sum summation is: %f\n", Add_Sum);          // Display  Result
    printf("Sub summation is: %f\n", Sub_Sum);
    printf("Mul summation is: %f\n", Mul_Sum);
    printf("Div summation is: %f\n", Div_Sum);
    
    pthread_exit(NULL);
}