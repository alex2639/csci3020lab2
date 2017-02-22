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
    if(argc==1){
      FILE *file=fopen(argv[1],"r");
      char *line;
      while(fscanf(file,"%s",line)!=EOF){
        get_commands(NULL,line,arg,pwd);
      }

    }else if(argc==2)
    {
      if(strcmp(argv[1],"<")==0)
      {
        FILE *file=fopen(argv[2],"r");
        char *line;
        while(fscanf(file,"%s",line)!=EOF){
          get_commands(NULL,line,arg,pwd);
          if(strcmp(line,"quit")==0){
            break;
          }
        }
        return EXIT_SUCCESS;
      }
      else if(strcmp(argv[1],">")==0)
      {
        FILE *file=fopen(argv[2],"w");
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
            get_commands(file,command,arg,pwd);
            if(strcmp(command,"quit")==0){
              break;
            }
            printf("%s> ", pwd);
        }
        return EXIT_SUCCESS;
      }
      else if(strcmp(argv[1],">>")==0)
      {
        FILE *file=fopen(argv[2],"a");
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
            get_commands(file,command,arg,pwd);
            if(strcmp(command,"quit")==0){
              break;
            }
            printf("%s>", pwd);
        }
        return EXIT_SUCCESS;
      }
    }
    else if(argc==4)
    {
      FILE *in_file=fopen(argv[2],"r");
      FILE *out_file;
      if(strcmp(argv[3],">")==0)
      {
        out_file=fopen(argv[4],"w");
      }
      else
      {
        out_file=fopen(argv[4],"a");
      }
      char *line;
      while(fscanf(in_file,"%s",line)!=EOF)
      {
        get_commands(out_file,line,arg,pwd);
        if(strcmp(line,"quit")==0){
          break;
        }
      }
      return EXIT_SUCCESS;
    }

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
        get_commands(NULL,command,arg,pwd);
        if(strcmp(command,"quit")==0){
          break;
        }
        printf("%s>", pwd);
    }
    return EXIT_SUCCESS;
}
