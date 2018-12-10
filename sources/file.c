/*
**  Filename : file.c
**
**  Made by : TeamDev
**
**  Description : functions used to read .c files
*/
#include "file.h"
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>



/**
 * Initialisation d
 **/
CheckFile* initCheckFile(char* nameKey){
	CheckFile* ll;

	ll = malloc(sizeof(CheckFile));
	ll->name = malloc(sizeof(char) * (strlen(nameKey) + 2));
	strcpy(ll->name, nameKey);
    ll->next = NULL;
    ll->head = NULL;

    return ll;
}

void freeCheckFile(CheckFile* val){
    if(val->next != NULL){
        freeCheckFile(val->next);
    }
    free(val);
}

/**
 * Print the current key
 **/
void printCheckFile(CheckFile* key){
    key = key->head;
    while(key->next != NULL){
        printf("|%s\n", key->name);
        key = key->next;
    }
    printf("|%s\n", key->name);
}


int isDir(const char *path) {
   struct stat statbuf;
   if (stat(path, &statbuf) != 0)
       return 0;
   return S_ISDIR(statbuf.st_mode);
}

int isCFile(char *file){
    char* type = malloc(sizeof(char) * 3);
    strcpy(type,file + strlen(file)-2); // get only ".c"
    if(strcmp(type,".c")!=0){
        return FALSE;
    }

    return TRUE;
}

int isExcludedFile(char *file, ConfigKey *conf){
    ConfigKey *current;

    if(!isCFile(file)){
        return TRUE;
    }
    conf = conf->head;
    current = getConfigKey("excludedFiles", conf);
    if(current == NULL){
        return FALSE;
    }
    current->value = current->value->head;
    while(current->value != NULL){
        if(strcmp(current->value->content, file) == 0){
            current->value = current->value->head;
            return TRUE;
        }
        if(current->value->next == NULL){
            current->value = current->value->head;
            break;
        }
        current->value = current->value->next;
    }
    return FALSE;
}

void readFolder(char *name, ConfigKey * key, CheckFile ** file){
    ConfigKey *recursive;
    int rec;
    recursive = getConfigKey("recursive", key);
    if(recursive != NULL){
        if(recursive->bValue->content != NULL){
            if(strcmp(recursive->bValue->content, "true") == 0){
                rec = 1;
            }else{
                rec = 0;
            }
        }else{
            rec = 0;
        }
    }else{
        rec = 0;
    }
    printf("\n");

    DIR *dp;
    struct dirent *ep;
    char path[4096];
    char temp[4096];
    int i = 0;
    dp = opendir (name);
    if (dp != NULL)
    {
        while (ep = readdir (dp)){
            if(isDir(ep->d_name) == 1 && rec == 1){
                if(strcmp(ep->d_name, ".")!=0 && strcmp(ep->d_name, "..")!=0  ){
                    strcpy(path, name);
                    strcat(path, "/");
                    strcpy(path, ep->d_name);
                    readFolder(path, key, file);
                }
            }else{
                if(strcmp(ep->d_name, ".")!=0 && strcmp(ep->d_name, "..")!=0  ){
                    if(isExcludedFile(ep->d_name, key) == FALSE){
                        snprintf(temp, sizeof temp, "%s\/%s", name, ep->d_name);
                        if(i == 0){
                            (*file) = initCheckFile(temp);
                            (*file)->head = (*file);
                        }else{
                            (*file)->next = initCheckFile(temp);
                            (*file)->next->head = (*file)->head;
                            (*file) = (*file)->next;
                        }
                        i++;
                    }
                }
            }
        }
        (void) closedir (dp);
    }
    else{
        perror ("Couldn't open the directory");
    }
    return 0;
}

