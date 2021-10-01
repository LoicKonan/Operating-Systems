## Program 02 - Unix Threads

### Loic Konan

### Description

> Your mission is to have a global array in your code with 4000 integers,<br>
> initialized with values 1 to 4000 in the main program (array[i]=i).<br>
> You will also create 4 threads (identified by tid values 1 to 4).<br>
> Each one of them will add the values of the array with subscripts in the<br>
> range (tid -1)*1000 to (tid*1000-1) to a global variable TOTAL,<br>
> one value at a time (do not add them up before adding to the TOTAL, i.e.,<br>
> it should be coded as TOTAL = TOTAL + array[i]). You will run the<br>
> code initially without using semaphores and in a second run,<br>
> with semaphores and report any difference in the results.<br>
>
> - **Hints: you may need to use the function pthread_join(),
> - but you may not need conditional variables. gcc
> - compiler should work and create a file a.exe, Executing a.exe>out.txt

### Files

|   #   | File                 | Description |
| :---: | -------------------- | ----------- |
|   1   | [main.c](main.c) | Solution    |
