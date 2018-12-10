/*
**  Filename : file.c
**
**  Made by : TeamDev
**
**  Description : functions used to read .c files
*/
#include "file.h"

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
/*
void readFolder(char *name, int indent){
    DIR *dir;
    struct dirent *entry;

    if (!(dir = opendir(name)))
        return;

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            char path[1024];
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                continue;
            snprintf(path, sizeof(path), "%s/%s", name, entry->d_name);
            printf("%*s[%s]\n", indent, "", entry->d_name);
            readFolder(path, indent + 2);
        } else {
            printf("%*s- %s\n", indent, "", entry->d_name);
        }
    }
    closedir(dir);
}
*/
