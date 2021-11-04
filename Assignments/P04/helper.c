#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// Value depend on System core
#define CORE 4

// Maximum matrix size
#define MAX 4

// Maximum threads is equal to total core of system
pthread_t thread[CORE * 2];
int mat_A[MAX], mat_B[MAX], sum[MAX], sub[MAX];

// Addition of a Matrix
void* addition(void* arg)
{
	int i, j;
	int core = (int)arg;

	// Each thread computes 1/4 th of matrix addition
	for (i = core * MAX / 4; i < (core + 1) * MAX / 4; i++) 
    {
		for (j = 0; j < MAX; j++) 
        {
			// Compute Sum Row wise
			sum[i] = mat_A[i] + mat_B[i];
		}

	}

}

// Subtraction of a Matrix
void* subtraction(void* arg)
{
	int i, j;
	int core = (int)arg;

	// Each thread computes 1/4th of matrix subtraction
	for (i = core * MAX / 4; i < (core + 1) * MAX / 4; i++) 
    {
		for (j = 0; j < MAX; j++) 
        {
			// Compute Subtract row wise
			sub[i] = mat_A[i] - mat_B[i];
		}

	}

}

// Driver Code
int main()
{
	int i, j, step = 0;
	// Generating random values in mat_A and mat_B
	for (i = 0; i < MAX; i++) 
    {
		for (j = 0; j < MAX; j++) 
        {
			mat_A[i] = 1;
			mat_B[i] = 2;

		}

	}


	// Displaying mat_A
	printf("\nMatrix A:\n");

	for (i = 0; i < MAX; i++) 
    {
		for (j = 0; j < MAX; j++) 
        {

			printf("%d ", mat_A[i]);
		}

		printf("\n");
	}

	// Displaying mat_B
	printf("\nMatrix B:\n");

	for (i = 0; i < MAX; i++) 
    {
		for (j = 0; j < MAX; j++) 
        {
			printf("%d ", mat_B[i]);
		}

		printf("\n");
	}

	// Creating threads equal
	// to core size and compute matrix row
	for (i = 0; i < CORE; i++) 
    {

		pthread_create(&thread[i], NULL, &addition, (void*)step);
		pthread_create(&thread[i + CORE], NULL, &subtraction, (void*)step);
		step++;
	}

	// Waiting for join threads after compute
	for (i = 0; i < CORE * 2; i++) 
    {
		pthread_join(thread[i], NULL);
	}

	// Display Addition of mat_A and mat_B
	printf("\n Sum of Matrix A and B:\n");

	for (i = 0; i < MAX; i++) 
    {
		for (j = 0; j < MAX; j++) 
        {
			printf("%d ", sum[i]);
		}

		printf("\n");
	}

	// Display Subtraction of mat_A and mat_B
	printf("\n Subtraction of Matrix A and B:\n");

	for (i = 0; i < MAX; i++) 
    {
		for (j = 0; j < MAX; j++) 
        {
			printf("%d ", sub[i]);
		}

		printf("\n");
	}

	return 0;
}
