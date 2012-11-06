#include "fshell.h"

int init_shell(){
	env = (tenv_info*)malloc(sizeof(tenv_info));

	if(!env){
		fprintf(stderr, "Error on initalizing fshell\n");
		return 0;
	}

	env->user = getenv("USER");
	env->pwd = getenv("PWD");
	env->user_home = getenv("HOME");
	env->hostname = getenv("HOSTNAME");

	fprintf(stdout, "*** fshell initialized at location %s@%s:%s ***\n", env->user,
									     env->hostname,
									     env->pwd);

	return 1;
}

void print_prompt(){
	fprintf(stdout, "<%s@%s:%s>:\n", env->user, env->hostname, env->pwd);
}


char *read_command(){
	char *cmd = (char*)malloc(BUFF_SIZE * sizeof(char));

	/*Sanity check into allocated pointer*/
	if (!cmd){
		fprintf(stderr, "Error on allocate memory, exiting\n");
		exit(ENOMEM);
	}

	cmd = gets(cmd);

	if (!cmd){
		fprintf(stderr, "Could not read a command, skipping this round\n");
		return NULL;
	}

	return cmd;
}

int start_shell(){
	char *cmd;

	/*Priting prompt for the first time*/
	print_prompt();
	
	/*Reading the first command*/
	cmd = read_command();
	if (!cmd){
		fprintf(stderr, "Error on get command\n");
		return 0;
	}

	while(strcmp(cmd, "exit") != 0){
		printf("Read command: %s\n", cmd);
		print_prompt();

		cmd = read_command();

		if (!cmd){
			fprintf(stderr, "Error on get command\n");
			return 0;
		}
	}

	return 1;

}
