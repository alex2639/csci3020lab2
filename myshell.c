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
    if(argc==1){
      FILE *file=fopen(argv[1],"r");
      char *line;
      while(fscanf(file,line)!=EOF){
        if (strcmp(line, "cd") == 0)
        {
            cd()
        }

        else if(strcmp(line, "clr") == 0)
        {
            clear_shell();
        }

        // quit command -- exit the shell
        else if (strcmp(line, "quit") == 0)
        {
            return EXIT_SUCCESS;
        }

        else if (strcmp(line, "echo")==0)
        {
            echo(arg);
        }

        else if (strcmp(line, "environ")==0)
        {
            environ(pwd);
        }

        else if (strcmp(line, "dir")==0)
        {
            dir();
        }

        else if (strcmp(line, "help")==0)
        {
            help();
        }

        else if (strcmp(line,"pause")==0)
        {
            pause();
        }

        // Unsupported command
        else
        {
            fputs("Unsupported command, use help to display the manual\n", stderr);
        }
      }
      return EXIT_SUCCESS;
    }else if(argc==2)
    {
      if(strcmp(argv[1],"<")==0)
      {
        FILE *file=fopen(argv[2],"r");
        char *line;
        while(fscanf(file,line)!=EOF)
        {
          if (strcmp(line, "cd") == 0)
          {
              cd();
          }

          else if(strcmp(line, "clr") == 0)
          {
              clear_shell();
          }

          // quit command -- exit the shell
          else if (strcmp(line, "quit") == 0)
          {
              return EXIT_SUCCESS;
          }

          else if (strcmp(line, "echo")==0)
          {
              echo(arg,NULL);
          }

          else if (strcmp(line, "environ")==0)
          {
              environ(pwd,NULL);
          }

          else if (strcmp(line, "dir")==0)
          {
              dir();
          }

          else if (strcmp(line, "help")==0)
          {
              help();
          }

          else if (strcmp(line,"pause")==0)
          {
              pause();
          }

          // Unsupported command
          else
          {
              fputs("Unsupported command, use help to display the manual\n", stderr);
          }
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

            if (strcmp(command, "cd") == 0)
            {
                cd();
            }

            else if(strcmp(command, "clr") == 0)
            {
                clear_shell();
            }

            // quit command -- exit the shell
            else if (strcmp(command, "quit") == 0)
            {
                return EXIT_SUCCESS;
            }

            else if (strcmp(command, "echo")==0)
            {
                echo(arg,file);
            }

            else if (strcmp(command, "environ")==0)
            {
                environ(pwd,file);
            }

            else if (strcmp(command, "dir")==0)
            {
                dir();
            }

            else if (strcmp(command, "help")==0)
            {
                help();
            }

            else if (strcmp(command,"pause")==0)
            {
                pause();
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
      else if(strcmp(argv[1],">>")==0)
      {
        FILE *file=fopen(argv[2],"wa");
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
                cd();
            }

            else if(strcmp(command, "clr") == 0)
            {
                clear_shell();
            }

            // quit command -- exit the shell
            else if (strcmp(command, "quit") == 0)
            {
                return EXIT_SUCCESS;
            }

            else if (strcmp(command, "echo")==0)
            {
                echo(arg,file);
            }

            else if (strcmp(command, "environ")==0)
            {
                environ(pwd,file);
            }

            else if (strcmp(command, "dir")==0)
            {
                dir();
            }

            else if (strcmp(command, "help")==0)
            {
                help();
            }

            else if (strcmp(command,"pause")==0)
            {
                pause();
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
    }
    else if(argc==4)
    {
      FILE *in_file=fopen(argv[2],"r");
      if(strcmp(argv[3],">")==0)
      {
        FILE *out_file=fopen(argv[4],"w");
      }
      else
      {
        FILE *out_file=fopen(argv[4],"wa");
      }
      char *line;
      while(fscanf(in_file,line)!=EOF)
      {
        if (strcmp(line, "cd") == 0)
        {
            cd();
        }

        else if(strcmp(line, "clr") == 0)
        {
            clear_shell();
        }

        // quit command -- exit the shell
        else if (strcmp(line, "quit") == 0)
        {
            return EXIT_SUCCESS;
        }

        else if (strcmp(line, "echo")==0)
        {
            echo(arg,out_file);
        }

        else if (strcmp(line, "environ")==0)
        {
            environ(pwd,out_file);
        }

        else if (strcmp(line, "dir")==0)
        {
            dir();
        }

        else if (strcmp(line, "help")==0)
        {
            help();
        }

        else if (strcmp(line,"pause")==0)
        {
            pause();
        }

        // Unsupported command
        else
        {
            fputs("Unsupported command, use help to display the manual\n", stderr);
        }
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

        if (strcmp(command, "cd") == 0)
        {
            cd();
        }

        else if(strcmp(command, "clr") == 0)
        {
            clear_shell();
        }

        // quit command -- exit the shell
        else if (strcmp(command, "quit") == 0)
        {
            return EXIT_SUCCESS;
        }

        else if (strcmp(command, "echo")==0)
        {
            echo(arg,NULL);
        }

        else if (strcmp(command, "environ")==0)
        {
            environ(pwd,NULL);
        }

        else if (strcmp(command, "dir")==0)
        {
            dir();
        }

        else if (strcmp(command, "help")==0)
        {
            help();
        }

        else if (strcmp(command,"pause")==0)
        {
            pause();
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
