#ifndef __H_FSHELL__

#define __H_FSHELL__

#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <errno.h>

#define BUFF_SIZE 256

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

/*Prints prompt line*/
void print_prompt();

/*Reads command from stdin
 *returns the command if success
 *and null if failed
 */
char *read_command();

/*Starts shell
 *returns 1 if success
 *0 if failed
*/
int start_shell();

#endif
