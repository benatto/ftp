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
