#include <stdlib.h>
#include <stdio.h>
#include "shell/fshell.h"

int main(int argc, char **argv){
	char *user;
	char *cmd;

	user = getenv("USER");

	fprintf(stdout, "Hi %s, see the list of active commands bellow:\n", user);
	fprintf(stdout, " +ls\n");
	fprintf(stdout, " +cd\n");
	fprintf(stdout, " +get\n");
	fprintf(stdout, " +put\n");
	fprintf(stdout, " +exit\n");

	init_shell();

	start_shell();	

	return 0;
}

