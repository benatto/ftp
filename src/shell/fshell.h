#ifndef __H_FSHELL__

#define __H_FSHELL__

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "ls.h"
#include "../types/env.h"

#define BUFF_SIZE 256
#define CMD_COUNT 5

typedef enum command{
	ls = 0,
	cd = 1,
	get = 2,
	put = 3,
	exit_ = 4
}tcommand;

tenv_info *env;

static char *cmds[] = {"ls", "cd", "get", "put", "exit"};

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

/*Parses a command and executes it
 *returns 1 if success or 0 if failed and sets ERRNO for related value
*/
int parse_command(char*);

#endif
