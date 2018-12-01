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

/**
 * Define
 **/
#define TRUE 1
#define FALSE 0

/**
 * Structure
 **/

typedef struct checkFile{
    char *name;
    struct checkFile *next;
    struct checkFile *head;
} CheckFile;

/**
 * Functions
 **/
CheckFile* initCheckFile(char* nameKey);
void freeCheckFile(CheckFile* val);
void printCheckFile(CheckFile* key);
int isCFile(char *file);
int isExcludedFile(char *file, ConfigKey *conf);
void readFolder(char *name, ConfigKey * key, CheckFile ** file);
