#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main(){
	int cpid = fork();
	int cpid2 = fork();
	if(cpid != 0 && cpid2 != 0){
		int waitPID = 0;
		int status;
		printf("\nParent: I am going to wait for the process with process ID: %d\n", cpid2);
		while(waitPID == 0){
			waitPID = waitpid(cpid2, &status, WNOHANG);
		}
		printf("\nParent: Waited for child, the return value of waitpid():%d\n", waitPID);
		printf("\nParent: The exit code of terminated child: %d\n",WEXITSTATUS(status));
		exit(1);
	}
	else if(cpid == 0 && cpid2 != 0){
	printf("\nChild1: My process ID is: %d, and my exit code is 1\n",
	getpid());
	exit(1);
	}
	else if(cpid != 0 && cpid2 == 0){
		printf("\nChild2: My process ID is: %d, and my exit code is 2\n",getpid());
		exit(2);
	}
	else{
		printf("\nChild3: My process ID is: %d, and my exit code is 3\n",getpid());
		exit(3);
	}
	return 0;
}
