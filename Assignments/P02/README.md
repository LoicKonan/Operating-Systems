## Program 02 - Unix Threads

### Loic Konan

### Description

> You will be working with a threads program. You will need to be creative and may try different approaches
> to test the parallelism between threads. Your mission is to have a global array in your code with 4000
> integers, initialized with values 1 to 4000 in the main program (array[i]=i). You will also create 4 threads
> (identified by tid values 1 to 4). Each one of them will add the values of the array with subscripts in the
> range (tid -1)*1000 to (tid*1000-1) to a global variable TOTAL, one value at a time (do not add them up
> before adding to the TOTAL, i.e., it should be coded as TOTAL = TOTAL + array[i]). You will run the
> code initially without using semaphores and in a second run, with semaphores and report any difference
> in the results.
>
> - **Hints: you may need to use the function pthread_join(),
> - but you may not need conditional variables. gcc
> - compiler should work and create a file a.exe, Executing a.exe>out.txt

### Files

|   #   | File                 | Description |
| :---: | -------------------- | ----------- |
|   1   | [main.asm](main.asm) | Solution    |
