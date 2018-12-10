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

#include "error.h"

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
char *strtok_r(char *str, const char *delim, char **save);
char *myInput(int choice);
int getFileSize(FILE *fp);
char *getKey(char **text);
int getValue(char* text, ConfigKey* key, Error *error);
ConfigKey *getConfiguration(char *cvalue, Error *error);
ConfigKey *getConfigKey(char *name,ConfigKey *conf);
char *isExtending(ConfigKey *conf);
char *asConfigKey(char *name, ConfigKey *conf, int type);
ConfigKey *asConfigKeyName(char *name, ConfigKey *conf);
void separateContent(char **value, char **content);
int fusionKey(ConfigKey *conf,ConfigKey *conf2);
int addBValueKey(ConfigKey *conf, ConfigKey *conf2);
int addValueKey(ConfigKey *conf, ConfigKey *conf2);
int addCValueKey(ConfigKey *conf, ConfigKey *conf2);
ConfigKey *copyKey(ConfigKey *conf);
void freeConfigKey(ConfigKey *key);
void freeConfig(ConfigKey *key);
void freeConfigBasicValue(ConfigBasicValue *val);
void freeConfigValue(ConfigValue *val);
void freeConfigContentValue(ConfigContentValue *val);
ConfigKey *initConfigKey(char *nameKey);
ConfigBasicValue *initConfigBasicValue(char *name);
ConfigValue *initConfigValue(char *name);
ConfigContentValue *initConfigContentValue(char *name, char *value);
ConfigKey *loadConfig(char *fp);
void printConfig(ConfigKey *key);
void printKey(ConfigKey *key);
void printBasic(ConfigKey *key);
