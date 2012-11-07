#include "ls.h"

int execute_ls(tenv_info *env){
	struct dirent *f;
	DIR *d;

	d = opendir(env->pwd);

	if (!d){
		printf("Could not open %s: ", env->pwd);

		switch (errno){
			case EACCES:
				printf("Access denied\n");
			break;
			case ENOENT:
				printf("Directory not exists\n");
			break;
			case ENOTDIR:
				printf("Not a directory\n");
			break;
			default:
				printf("Unknown error\n");
			break;
		}
	}

	while ((f = readdir(d)) != NULL){
		printf("%u - %s\n", f->d_type, f->d_name);
	}

	return 1;
}
