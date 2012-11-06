#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <errno.h>

/*lists dir content for a given path
 *returns 1 if success 0 for fail and sets errno for a proper value*/
int execute_ls(char*);
