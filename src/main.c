#include <stdlib.h>
#include <stdio.h>
#include "shell/fshell.h"

int main(int argc, char **argv){
	char *user;
	char *cmd;

	user = getenv("USER");

	fprintf(stdout, "Hi %s! It's ust a little beginning, soon everything will be working. That's all folk!\n", user);

	init_shell();

	start_shell();	

	return 0;
}

