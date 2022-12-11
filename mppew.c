#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <libgen.h>

int main (int argc, char* argv[]) {
    int i;
    char new_cmd[1000];
    FILE *fptr;
    char* new_args[argc];

    fptr = fopen("command.cmd", "r");
    if (NULL == fptr) {
	printf("%s\n","[Info] Multi Platform Process Execution Wrapper ver. 0.1");
	printf("%s\n","[Info] Created by MWierszycki. Licensed under GPL-2.0-only.");
	printf("%s\n","[Info] See https://github.com/mwierszycki/mppew");
	printf("%s\n","");
	printf("%s\n","[Erro] The command.cmd file doesn't find!");
	printf("%s\n","");
	printf("%s\n","[Info] Create a command.cmd file with full path to program which should be executed.");
	printf("%s\n","[Info] By defult all arguments are passed automatically.");
        return 0;
    }
    else {
        fscanf(fptr, "%[^\n]", new_cmd);
        new_args[0] = basename(new_cmd);
    }

    for( i = 1;  i <= argc;  i++ ) {
        new_args[i] = argv[i];
    }

//    printf("%s ", new_cmd);
//    for( i = 0;  i <= argc;  i++ ) {
//        printf("%d = %s ", i, new_args[i]);
//    }
//    printf("\n");
//    return 0;
    return execv(new_cmd, new_args);
}
