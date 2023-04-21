#include "main.h"

int launch(char** arguments) {
	pid_t pid;
	
	pid = fork();
	if(pid < 0) {
		printf("Error: failed to fork child process\n");
		exit(1);
	} else if(pid == 0) {
		if(execvp(arguments[0], arguments) < 0) {
			printf("./shell: No such file or directory\n");
			exit(1);
		}
	} else {
		wait(NULL);
	}

	return (1);
}
