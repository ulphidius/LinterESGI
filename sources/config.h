/*
**  Filename : config.h
**
**  Made by : TeamDev
**
**  Description : contain struct and prototype of all functions in functions.c
*/

/**
 * Lib
 **/
#include "confKey.h"


#ifndef CONFKEY_H_INCLUDED
#define CONFKEY_H_INCLUDED

/**
 * Define
**/

#define BVALUE 1
#define VALUE 2
#define CVALUE 3


/**
 * Functions
 **/
char *myInput(int choice);
int getFileSize(FILE *fp);
char *getKey(char **text);
int getValue(char *text, ConfigKey *key);
char *isExtending(ConfigKey *conf);
void separateContent(char **value, char **content);
int addBValueKey(ConfigKey *conf, ConfigKey *conf2);
int addValueKey(ConfigKey *conf, ConfigKey *conf2);
int addCValueKey(ConfigKey *conf, ConfigKey *conf2);
void freeConfigBasicValue(ConfigBasicValue *val);
void freeConfigValue(ConfigValue *val);
void freeConfigContentValue(ConfigContentValue *val);
ConfigKey *initConfigKey(char *nameKey);
ConfigBasicValue *initConfigBasicValue(char *name);
ConfigValue *initConfigValue(char *name);
ConfigContentValue *initConfigContentValue(char *name, char *value);
void printConfig(ConfigKey *key);
void printKey(ConfigKey *key);



#endif // CONFKEY_H_INCLUDED
