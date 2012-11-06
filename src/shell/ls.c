#include "ls.h"

int execute_ls(char *path){
	struct dirent *f;
	DIR *d;

	d = opendir(path);

	if (!d){
		printf("Could not open %s: ", path);

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
