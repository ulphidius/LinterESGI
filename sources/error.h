#ifndef ERROR_H_INCLUDED
#define ERROR_H_INCLUDED

/*
**  Filename : error.h
**
**  Made by : TeamDev
**
**  Description : contain struct and prototype of all functions in file.c
*/

/**
 * Lib
 **/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * Define
 **/


/**
 * Structure
 **/
 typedef struct errorConf{
     long line;
     char *file;
     char *rule;
     struct errorConf *next;
 }ErrorConf;

 typedef struct error{
     int size;
     ErrorConf *head;
 }Error;




/**
 * Functions
 **/
Error *initError();
ErrorConf *initErrorConf(long line, char *file, char *rule);
void addErrorConf(Error *error, long line, char *file, char *rule);
int freeErrorConf(ErrorConf *key);
void freeError(Error *error);
void printError(Error *error);

#endif // ERROR_H_INCLUDED
