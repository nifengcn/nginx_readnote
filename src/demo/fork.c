#include <sys/types.h>  
#include <stdlib.h>  
#include <unistd.h>  
#include <stdio.h>  
  
int main()  
{  
	pid_t pid;  
	int idx = -1;  

	for (int i = 0; i < 4; i++) {  
		pid = fork();  
		if (pid < 0) {
			printf("fork failed\n");
		} else if (pid == 0) {
			printf("this is sub process, pid %d\n", getpid());
			//break;
		} else {
			printf("this is parent process, parent process is %d, sub process is %d\n", getpid(), pid);
		}
	}  

	printf("hello pid: %d\n", getpid());
	exit(0) ;  
} 
