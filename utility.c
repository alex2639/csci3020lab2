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

// Define your utility functions here, these will most likely be functions that you call
// in your myshell.c source file

void cd(){
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
  clear();
}

void echo(char *arg,FILE *file){
  char *ar = strtok(NULL, "");
  if(ar != NULL)
  {
    strcpy(arg, ar);
    if(file=NULL)
    {
      printf("%s ", arg);
    }
    else
    {
      fprintf(file, "%s ", arg);
    }
  }
  if(file=NULL)
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
  if(file=NULL)
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
  char *ar = strtok(NULL, "");
  list_directory(ar);
}

void help(){
  char *ar = strtok(NULL, "");
  if(ar != NULL)
  {
    char *cmd=strcat("man ", ar);
    int status=system(cmd);
  }
}

void pause(){
  while(1)
  {
    char c = getchar();
    if(c == '\n')//if ENTER key is pressed
    {
      break;
    }
  }
}
