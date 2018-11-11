/*
**  Filename : error.c
**
**  Made by : TeamDev
**
**  Description : functions used to read .c files
*/
#include "error.h"


/**
 * init an Error
 **/
Error *initError(){
    Error *ll;
    ll = malloc(sizeof(ErrorConf));
    ll->size = 0;
    ll->head = NULL;

    return ll;
}

/**
 * init an ErrorConf
 **/
ErrorConf *initErrorConf(long line, char *file, char *rule){
    ErrorConf *ll;
    ll = malloc(sizeof(ErrorConf));
    ll->line = line;
    ll->file = malloc(sizeof(char) * (strlen(file) + 1));
    if (ll->file == NULL){
        return NULL;
    }
    strcpy(ll->file, file);
    ll->rule = malloc(sizeof(char) * (strlen(rule) + 1));
    if (ll->rule == NULL){
        free(ll->file);
        return NULL;
    }
    strcpy(ll->rule, rule);

    return ll;
}

/**
 * add error at the end of the list
 **/
void addErrorConf(Error *error, long line, char *file, char *rule){
    ErrorConf *new;
    new = initErrorConf(line, file, rule);

    new->next = error->head;
    error->head = new;
    error->size ++;
}

/**
 * free the whole ErrorConf list
 **/
int freeErrorConf(ErrorConf *key){
    if(key == NULL){
        return 0;
    }
    if(key->next != NULL){
        freeErrorConf(key->next);
    }
    free(key->file);
    free(key->rule);
    free(key);
    return 1;
}

/**
 * free the Error
 **/
void freeError(Error *error){
    freeErrorConf(error->head);
    free(error);
}


/**
 * print all error
 **/
void printError(Error *error){
    ErrorConf *key;
    key = error->head;

    printf("\n    /!\\ ERROR (%d) /!\\ \n",error->size);
    printf(" --------------------------\n");
    while(key != NULL){
        printf("| in %s l. %d : \"%s\"\n", key->file, key->line, key->rule);
        key = key->next;
    }
    printf("|__________________________\n");
}
