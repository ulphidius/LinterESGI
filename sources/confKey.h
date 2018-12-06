/*
**  Filename : confKey.h
**
**  Made by : TeamDev
**
*/

/**
 * Lib
 **/
#include <stdio.h>


#ifndef CONFKEY_H_INCLUDED
#define CONFKEY_H_INCLUDED

/**
 * Define
**/

#define BVALUE 1
#define VALUE 2
#define CVALUE 3

/**
 * Struct
 **/

typedef struct configBasicValue{
    char *content;
    struct configBasicValue *next;
    struct configBasicValue *head;
} ConfigBasicValue;

typedef struct configValue{
    char *content;
    struct configValue *next;
    struct configValue *head;
} ConfigValue;

typedef struct configContentValue{
    char *content;
    char *value;
    struct configContentValue *next;
    struct configContentValue *head;
} ConfigContentValue;

typedef struct configKey{
    char *name;
    ConfigBasicValue *bValue;
    ConfigValue *value;
    ConfigContentValue *cValue;
    struct configKey *next;
    struct configKey *head;
} ConfigKey;

/**
 * Functions
 **/
ConfigKey *getConfiguration(char *name);
ConfigKey *getConfigKey(char *name,ConfigKey *conf);
char *asConfigKey(char *name, ConfigKey *conf, int type);
ConfigKey *asConfigKeyName(char *name, ConfigKey *conf);
int fusionKey(ConfigKey *conf,ConfigKey *conf2);
ConfigKey *copyKey(ConfigKey *conf);
void freeConfigKey(ConfigKey *key);
void freeConfig(ConfigKey *key);
ConfigKey *loadConfig(char *fp);


#endif // CONFKEY_H_INCLUDED
