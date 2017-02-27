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

// Define your utility functions here, these will most likely be functions that you call
// in your myshell.c source file

void cd(char *pwd, char *arg){
  char *ar = strtok(NULL, "");
  if(ar != NULL)
  {
    strcpy(arg, ar);
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

void clear_shell(){
  //clear();
  printf("\033[H\033[J");
}

void echo(char *arg,FILE *file){
  char *ar = strtok(NULL, "");
  if(ar != NULL)
  {
    strcpy(arg, ar);
    if(file==NULL)
    {
      printf("%s ", arg);
    }
    else
    {
      fprintf(file, "%s ", arg);
    }
  }
  if(file==NULL)
  {
    printf("\n");
  }
  else
  {
    fprintf(file,"\n");
  }
}

void environ(char *pwd,FILE *file){
  const char* s = getenv("PATH");
  getcwd(pwd, sizeof(pwd));
  if(file==NULL)
  {
    printf("SHELL :%s\n",(s!=NULL)? s : "getenv returned NULL");
    printf("PWD: %s\n",pwd);
  }
  else
  {
    fprintf(file,"SHELL :%s\n",(s!=NULL)? s : "getenv returned NULL");
    fprintf(file,"PWD: %s\n",pwd);
  }

}

void dir(){
  // /char *ar = strtok(NULL, "");
  DIR *dir_path; //directory path storage variable
  struct dirent *current_file; //struct of directory
  dir_path = opendir ("./"); //opens current directory
  while (current_file = readdir(dir_path)){ //loops and prints the names of all the contents of a dir
    printf("%s\n", current_file->d_name);//prints current file name to terminal
  }
  (void)closedir (dir_path); //closes directory path
  //list_directory(ar);
}

//print readme to screen for user
void help(){
  //char *ar = strtok(NULL, "");
  char txt;
  FILE *README;
  README = fopen("README.md", "r"); //reading readme file
  if (README){	//if file exists
    while ((txt = getc(README)) != EOF){ //print each character to screen
        printf("%c", txt);
    }
    fclose(README);//close readme file
  }

  //if(ar != NULL)
  //{
    //char *cmd=strcat("man ", ar);
    //int status=system("README.md");
  //}
}

void pause_shell(){
  while(1)
  {
    char c = getchar();
    if(c == '\n')//if ENTER key is pressed
    {
      break;
    }
  }
}

void get_commands(FILE *out_file,char *line, char *arg, char* pwd){
    if (strcmp(line, "cd") == 0)
    {
        cd(pwd,arg);
    }

    else if(strcmp(line, "clr") == 0)
    {
        clear_shell();
    }

    // quit command -- exit the shell
    else if (strcmp(line, "quit") == 0)
    {
        return;
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
        pause_shell();
    }

    // Unsupported command
    else
    {
        fputs("Unsupported command, use help to display the manual\n", stderr);
    }
}
