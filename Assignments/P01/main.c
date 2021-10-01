//Mini Project 1
//David Hawkins, Loic Konan, Sarah Gilliland

#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>

int main()

{
	unsigned int pos = 0;
	char character1;
	char character2;
	int instancesForThisChild = 0;
	
	char cmd[4];
	
	scanf("%4c", &cmd);
	
	while(cmd[0] != '/' && cmd[1] != '/' && cmd[2] != '/' && cmd[3] != '/')
	{
		pos = 0;
		int file = open ("input.txt", O_RDONLY);
		
		for(int i = 0; i< 5 && pos < 20; i++)
		{
			instancesForThisChild = 0;
			if(fork()==0){
				for (int j = 0; j < 3; j++)
				{
					lseek(file, pos+j, SEEK_SET);
					read(file, &character1, 1); //first character from file
					lseek(file, pos+j+1, SEEK_SET);
					read(file, &character2, 1); //read second character from file
					
					if ((character1 == cmd[2]) && (character2 == cmd[3]))
					{
						instancesForThisChild++;
					}
				}
			printf("Child %d found %d instances.", i, instancesForThisChild);
			printf("\n\n");
			wait(NULL);
			exit(0);
			
			}
			pos = pos + 4;
		}
		
		printf("\n\n");
		scanf(" %4c", &cmd);
	}
	return 0;
}

