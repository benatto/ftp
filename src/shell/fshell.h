#ifndef __H_FSHELL__

#define __H_FSHELL__

#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>

/*
 * Describes some usefull env information
 */
typedef struct env_info{
	char *user;
	char *pwd;
	char *user_home;
	char *hostname;
}tenv_info;

typedef enum command{
	ls = 1,
	cd = 2,
	get = 3,
	put = 4
}tcommand;

tenv_info *env;

/*Initilizes ftp shell env variables
 *returns 1 if success or 0 if failed
 */
int init_shell();

void print_prompt();

#endif
