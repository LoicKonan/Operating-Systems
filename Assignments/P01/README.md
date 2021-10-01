## Program 01 - POSIX Fork

### Loic Konan

### Description

> This program should be able to search for a pair of characters in a file,<br>
> using multiple processes to speed up the answer.<br>
> The user will type a command starting with the letter S, 
> followed by the pair of search characters in the (this) program source code.<br>
> Five children should be generated, each one of them should<br>
> run a lseek to access the correct portion of the file.<br>
> The first child will search the first 1/5 of the file, the second the next 1/5 and so on.<br> 
> We will assume that the pair of searched characters will never happen in the<br>
> boundary of the file sections. Each child will report<br>
> how many time the pair of characters was found in its searched area.<br>
> When detecting a / in the position of a new command, the program should stop running.
>
> - **Hints:** An example of printing command in C language for an integer number x
is
> - printf(“text %d”,x);

### Files

|   #   | File             | Description |
| :---: | ---------------- | ----------- |
|   1   | [main.c](main.c) | Solution    |
