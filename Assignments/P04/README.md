## Program 04 - Shared Memory Programing by using pthreads

### Loic Konan

### Description
>
> You are going to create a **pthreaded array calculator**.
> The calculator must be able to perform the typical traditional arithmetic operations, such as:
>
> - **Addition**
> - **Substraction**
> - **Multiplication**
> - **Division**
>
>   - Arrays A, and B are integer arrays, with **1 million integers each**.
    - All the elements in array A are 1, while all those in B are 2.
>   - The addition function will create array "addition", in which **Addition[0] = a[0] + b[0]**. 
>   - Follow a similar logic for **Substraction, Multiplication and Division**.
>
> Write a threaded program that uses **four (4) threads**:
>
> - Thread 0 will take care of the addition
> - Thread 1 susbtraction
> - Thread 2 multipliaction
> - Thread 3 division

### Files

|   #   | File                               | Description  |
| :---: | ---------------------------------- | ------------ |
|   1   | [main.c](main.c)                   | Solution     |
|   2   | [Calculation.cpp](calculation.cpp) | Calculations |
