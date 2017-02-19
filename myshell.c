/*
 * MyShell Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2017, Alex, Damon, Irfaan
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

        if (strcmp(command, "cd") == 0)
        {
            char *ar = strtok(NULL, "");
            if(ar != NULL)
            {
                strcpy(arg, ar);
               // printf("command: %s, arg: %s\n", command, arg);
               if(chdir(arg) != 0)
               {
                   //Can't find the directory specified'
                    printf("can't find %s\n", arg);
               }
               else
               {
                   //Set new pwd
                  getcwd(pwd, sizeof(pwd));
               }
            }
            else
            {
                //print pwd and a new line
                 printf("%s\n", pwd);
            }
        }

        else if(strcmp(command, "clr") == 0)
        {
            printf("\033[2J");
        }


        // other commands here...

        // quit command -- exit the shell
        else if (strcmp(command, "quit") == 0)
        {
            return EXIT_SUCCESS;
        }

        else if (strcmp(command, "echo")==0)
        {
          //printf("%s\n", buffer);
          char *ar = strtok(NULL, "");
          if(ar != NULL)
          {
            strcpy(arg, ar);
            printf("%s ", arg);
          }
          printf("\n");
        }

        else if (strcmp(command, "environ")==0)
        {

        }

        else if (strcmp(command, "dir")==0)
        {

        }

        else if (strcmp(command, "help")==0)
        {

        }

        else if (strcmp(command,"pause")==0)
        {
          while(1)
          {
            char c = getchar();
            if(c == '\n')//if ENTER key is pressed
            {
              break;
            }
          }
        }

        // Unsupported command
        else
        {
            fputs("Unsupported command, use help to display the manual\n", stderr);
        }
        printf("%s>", pwd);
    }
    return EXIT_SUCCESS;
}
