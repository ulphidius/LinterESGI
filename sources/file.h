/*
**  Filename : file.h
**
**  Made by : TeamDev
**
**  Description : contain struct and prototype of all functions in file.c
*/

/**
 * Lib
 **/
 
#include "config.h"
#include <dirent.h>
 
 
/**
 * Define
 **/
#define TRUE 1
#define FALSE 0
 
/**
 * Structure
 **/
 
 
 
/**
 * Functions
 **/
int isExcludedFile(char *file, ConfigKey *conf);
void readFolder(char *name, int indent);