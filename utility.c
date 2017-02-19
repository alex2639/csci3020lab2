/*
 * MyShell Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2017, <GROUP MEMBERS>
 * All rights reserved.
 * 
 */


#define _GNU_SOURCE //for scandir

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include "utility.h"


// Define your utility functions here, these will most likely be functions that you call
// in your myshell.c source file


void clear()
{
    printf("\033[2J");
}

void list_directory(char *directory)
{

    if(directory == NULL)
    {
        directory = "./";
    }

    DIR *dp;
    struct dirent **file_names;   
    int number_of_files;  
    dp = opendir (directory);

    number_of_files = scandir(directory, &file_names, NULL, alphasort);

    if (dp != NULL)
    {
        //while (file_names = readdir (dp))
        for(int i = 0; i < number_of_files; i ++)
        {
            puts (file_names[i]->d_name);
        }

        (void) closedir (dp);
    }
    else
    {
        perror ("Couldn't open the directory");
    }
    free(file_names);
}
