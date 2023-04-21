#include "main.h"

void parse_command(char* command, char** arguments) {
	char* token;
	int i = 0;
	token = strtok(command, TOK_DELIM);
	while(token != NULL) {
		arguments[i] = token;
		token = strtok(NULL, TOK_DELIM);
		i++;
	}
	arguments[i] = NULL;
}

