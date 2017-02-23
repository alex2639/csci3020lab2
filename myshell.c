/*
 * MyShell Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2017, Alex, Damon
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include "utility.h"
#include "myshell.h"

// Put macros or constants here using #define
#define BUFFER_LEN 256

// Put global environment variables here

// Define functions declared in myshell.h here

int main(int argc, char *argv[])
{
    // Input buffer and and commands
    char buffer[BUFFER_LEN] = { 0 };
    char command[BUFFER_LEN] = { 0 };
    char arg[BUFFER_LEN] = { 0 };
    char pwd[1024];

    getcwd(pwd, sizeof(pwd));
    printf("%s> ", pwd);

    // Parse the commands provided using argc and argv    

    // Perform an infinite loop getting command input from users
    while (fgets(buffer, BUFFER_LEN, stdin) != NULL)
    {
        // Perform string tokenization to get the command and argument
        char *pos;
        if ((pos=strchr(buffer, '\n')) != NULL)
        {
            *pos = '\0';
        }
        strcpy(command, strtok(buffer, " "));
        get_commands(command,arg,pwd);
        if(strcmp(command,"quit")==0){
          break;
        }
        printf("%s>", pwd);
    }
    return EXIT_SUCCESS;
}
