/*
 * MyShell Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2017, Alex, Damon
 * All rights reserved.
 *
 */
#ifndef UTILITY_H_
#define UTILITY_H_

// Include your relevant functions declarations here they must start with the
// extern keyword such as in the following example:
// extern void display_help(void);
extern void cd(void);
extern void clear_shell(void);
extern void echo(char *arg,FILE *file);
extern void environ(char *pwd,FILE *file);
extern void dir(void);
extern void help(void);
extern void pause(void);

#endif /* UTILITY_H_ */
