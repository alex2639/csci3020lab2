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
const char s[2] = " ";
// Define functions declared in myshell.h here


int main(int argc, char *argv[])
{
    // Input buffer and and commands
    char buffer[BUFFER_LEN] = { 0 };
    char command[BUFFER_LEN] = { 0 };
    char arg[BUFFER_LEN] = { 0 };

    // Parse the commands provided using argc and argv
    //printf("%d \n",argc);
    //printf("%s \n",argv);


    // Perform an infinite loop getting command input from users
    while (fgets(buffer, BUFFER_LEN, stdin) != NULL)
    {
        // Perform string tokenization to get the command and argument
        //command=argv[0];

        // Check the command and execute the operations for each command
        // cd command -- change the current directory

        //*command = strtok(buffer," ")[0];
        //printf("%s\n", command);
        //printf("%s\n", arg);
        //printf("%s\n", buffer);
        //*command=buffer;
        //printf("%s\n", command);
        char word[strlen(buffer)];
        strcpy(word, buffer);
        strcpy(command,strtok(word," "));

        if (strcmp(command, "cd") == 0)
        {
            // your code here
            strcpy(arg, strtok(NULL," "));
            printf("command: %s arg: %s\n", command, arg);

        }
        else if(strcmp(command, "cd\n") == 0)
        {
            printf("do whatever\n");
            //Whatever we want "cd" by itself can go here until we come up with a more
            //elegant solution
        }

        // other commands here...

        // quit command -- exit the shell
        else if (strcmp(command, "quit") == 0)
        {
            return EXIT_SUCCESS;
        }

        // Unsupported command
        else
        {
            //fputs("Unsupported command, use help to display the manual\n", stderr);
            memmove(&buffer[strlen(buffer)-1], &buffer[strlen(buffer)],strlen(buffer)-(strlen(buffer)-1));

            char *token = strtok(buffer,s);

            printf("%s[", "");
            while(token !=NULL){

              printf("%s", token);
              token=strtok(NULL,s);
              if(token!=NULL){
                printf("%s", ", ");
              }
            }
            printf("%s\n","]");
        }
    }
    return EXIT_SUCCESS;
}
