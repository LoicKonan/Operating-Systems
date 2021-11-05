#include<iostream>
using namespace std;



/**
 * 
 * Defined globally accessible variables:
 * 
 *  - Size of the Array = 1 000 000
 *  - 2 Arrays: Array A & B of size = 1 000 000
 *  - Addition Summation set it to zero
 *  - Substraction Summation set it to zero
 *  - Multiplication Summation set it to zero
 *  - Division Summation set it to zero
 *  
 */
#define ARR_SIZE 1000000
int Arr_A[ARR_SIZE];
int Arr_B[ARR_SIZE];

double Add_Sum = 0;
double Sub_Sum = 0;
double Mul_Sum = 0;
double Div_Sum = 0;

/**
 * Driver.
 * 
 * @return int 
 */

int main()
{
    
    /**
     *  
     *  - Implemeting all the operation in this for loop 
     *  - Addtion
     *  - Substraction
     *  - Multiplication
     *  - Division
     * 
     */
    for (int i = 0; i < ARR_SIZE ; i++)
    {
        Arr_A[i] = 1;
        Arr_B[i] = 2;
        Add_Sum += Arr_A[i] + Arr_B[i];

        Sub_Sum += Arr_A[i] - Arr_B[i];

        Mul_Sum += Arr_A[i] * Arr_B[i];

        Div_Sum += (double)Arr_A[i] / (double)Arr_B[i];
    }

    /**
     *
     * Displaying the result 
     * 
     */
    cout << "\nAddition summation is:       " << Add_Sum;
    cout << "\nSusbtraction  summation is: "  << Sub_Sum;
    cout << "\nMultipliaction summation is: " <<  Mul_Sum;
    cout << "\nDivision summation is:       " << Div_Sum;

}
