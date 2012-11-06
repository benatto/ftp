#include "cd.h"

int execute_cd(char *path, tenv_info *env){
	struct stat st;
	if (path == NULL){
		env->pwd = env->user_home;
		return 1;
	}

	if(stat(path, &st) == 0){
		env->pwd = path;
		return 1;
	}

	return 0;
}
