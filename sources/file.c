/*
**  Filename : file.c
**
**  Made by : TeamDev
**
**  Description : functions used to read .c files
*/
#include "file.h"
#include <dirent.h>

int isExcludedFile(char *file, ConfigKey *conf){
    ConfigKey *current;

    conf = conf->head;
    current = asConfigKeyName("excludedFiles", conf);
    if(current == NULL){
        return FALSE;
    }
    current->value = current->value->head;
    while(current->value != NULL){
        if(strcmp(current->value->content, file) == 0){
            return TRUE;
        }
        current->value = current->value->next;
    }
    return FALSE;
}

void readFolder(char *name){
    int i;
    DIR *dp;
    struct dirent *ep;

    dp = opendir (name);
    if (dp != NULL)
    {
        i = 0;
        while (ep = readdir (dp)){
            //bvalue = bvalue->head;
            while(bvalue->next != null){
                if (strcmp(ep->d_name,current)){
                    i = 1;
                    break;
                }
                bvalue = bvalue->next;
            }
            puts (ep->d_name);
        }
        (void) closedir (dp);
    }
    else{
        perror ("Couldn't open the directory");
    }
    return 0;
}
