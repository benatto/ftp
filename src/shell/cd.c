#include "cd.h"

int execute_cd(char *path, tenv_info *env){
	struct stat st;
	if (path == NULL){
		env->last_pwd = env->pwd;
		if(chdir(env->user_home) == 0){
			env->pwd = get_current_dir_name();
			return 1;
		}

		return 0;
	}

	if(stat(path, &st) == 0){
		env->last_pwd = env->pwd;
		if(chdir(path) == 0){
			env->pwd = get_current_dir_name();
			return 1;
		}

		return 0;
	}

	return 0;
}
