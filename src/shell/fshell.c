#include "fshell.h"

int init_shell(){
	env = (tenv_info*)malloc(sizeof(tenv_info));

	if(!env){
		fprintf(stderr, "Error on initalizing fshell\n");
		return 0;
	}
	
	env->last_pwd = (char*)malloc(BUFF_SIZE * sizeof(char));

	env->user = getenv("USER");
	env->pwd = getenv("PWD");
	env->user_home = getenv("HOME");
	env->hostname = getenv("HOSTNAME");
	
	strcpy(env->last_pwd, env->pwd);

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

	parse_command(cmd);
	while(strcmp(cmd, "exit") != 0){
		print_prompt();

		cmd = read_command();

		if (!cmd){
			fprintf(stderr, "Error on get command\n");
			return 0;
		}

		parse_command(cmd);
	}

	free(env);

	return 1;

}

int parse_command(char *cmd){
	int i, cmd_value = -1;
	char *arg = cmd;

	cmd = strsep(&arg, " \t");

	for (i = 0; i < CMD_COUNT; i++){
		if (strcmp(cmd,cmds[i]) == 0){
			cmd_value = i;
			break;
		}
	}

	switch(cmd_value){
		case ls:
			execute_ls(env);
		break;
		case cd:
			if (!execute_cd(arg, env))
				printf("%s: not exists or not a directory\n", arg);
		break;
		case put:
			printf("Operation not implemented yet\n");
			return 1;
		break;
		case get:
			printf("Operation not implemented yet\n");
			return 1;
		break;
		case exit_:
			return 1;
		break;
		default:
			printf("%s: Invalid command\n", cmd);
			errno = EINVAL;
			return 0;
		break;

	}
}
