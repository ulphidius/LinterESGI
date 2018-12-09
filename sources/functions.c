#include <stdio.h>
#include "functions.h"

int checkFunction(char* fp,int cas){
    FILE *f = fopen(fp, "r");
    if(f == NULL)
        return -1;
    char line[2000];
    char search[2000];
    char type[2000];
    char name[2000];
    char *tmp;
    char *trimline;
    int seek;
    int find = 0;
    int findR = 0;
    long int linenb = 0;
    char **prototype;
    int size = 1;

    while(fgets(line, 1999, f) != NULL){
        linenb++;
        trimline = trim(line);
        tmp = strtok(trimline, " ");
        strcpy(type, tmp);
        tmp = strtok(NULL, " ");
        if(tmp != NULL){
            strcpy(name, tmp);
            if(checkDeclaration(type, name)){
                if(cas == 1){
                    if(strchr(name, ';') != NULL){
                        prototype = arrayP(prototype, size, mysubstr(name, '('));
                        size++;
                    }else{
                        if(!asPrototype(name, prototype, size)){
                            printf("[no-prototype] %s : %ld (%s)\n",fp, linenb, mysubstr(name, '('));
                            findR ++;
                        }
                    }
                }else{
                    find = 0;
                    //printf("\n------------------------------------------------\nfind : %s\n------------------------------------------------\n",name);
                    //avance d'une ligne pour boucler à partir de n+1
                    fgets(search, 1999, f);
                    seek = ftell(f);
                    while(fgets(search, 1999, f)){
                        trimline = trim(search);
                        if(checkName(search, name)){
                            printf("[x]%s|%s\n",name,search);
                            find++;
                        }
                        //printf("(%d)(%d) |%s|\n",seek, ftell(f),search);
                        //getchar();
                    }
                    fseek(f, seek, SEEK_SET);
                    if(find == 0){
                        printf("[unused-function] %s : %ld (%s)\n",fp, linenb, mysubstr(name, '('));
                        findR ++;
                    }
                }
            }
        }

        //printf(" - type : %s\ - name : %s\n",type,name);
    }
    fclose(f);
    return findR;
}

char ** arrayP(char** in, int size, char *add){

    int i,j;
    char **out;

    out = malloc(sizeof(char*) * size);
    for(i = 0; i < size; i ++){
        if(i == size-1){
            out[i] = malloc(sizeof(char) * (strlen(add)+1));
            strcpy(out[i], add);
        }else{
            out[i] = malloc(sizeof(char) * (strlen(in[i])+1));
            strcpy(out[i], in[i]);
        }
    }
    free(in);
    return out;
}

int asPrototype(char* name, char** list,int size){
    int i = 0;
    for(i = 0; i < size; i ++){
        if(!strcmp(list[i], mysubstr(name, '('))){
            return 1;
        }
    }

    return 0;
}

char *mysubstr(char *src,char pos) {
    char *n;
    int i = 0;
    n = malloc(sizeof(char) * strlen(src));
    while(src[i]!='\0' && src[i]!=pos){
        n[i] = src[i];
        i++;
    }
    n[i] = '\0';

  return n;
}

int checkType(char* line){
    if(strstr(line,"int") != NULL || strstr(line,"char") != NULL || strstr(line,"long") != NULL || strstr(line,"short") != NULL || strstr(line,"void") != NULL)
        return 1;
    return 0;
}

int checkFunc(char* line){
    if(strchr(line, '(') != NULL)
        return 1;
    return 0;
}

int checkName(char* name1, char* name2){
    int i;
    char *n;
    char *m;

    n = mysubstr(name1, '(');

    m = mysubstr(name2, '(');

    //printf("n : |%s| m : |%s|\n",n,m);

    if(strstr(n,m) != NULL)
        return 1;
    return 0;
}

int checkDeclaration(char* type, char* name){
    if(type == NULL || name == NULL)
        return 0;
    //if(checkType(type) && checkFunc(name))
    //    return 1;
    if(checkType(type) && checkFunc(name))
        return 1;
    //    return 1;


    return 0;
}

char* trim(char* line){
    char *tmp;
    char *newLine;
    int i = 0;
    int j = 0;

    tmp = malloc(sizeof(char) * strlen(line));

    while(line[i] != '\0'){
        if(line[i] != ' ' && line[i] != '\t'){
            tmp[j] = line[i];
            j++;
        }else{
            if(line[i+1] != ' ' && line[i+1] != '\t' && line[i+1] != '('){
                tmp[j] = line[i];
                //tmp[j] = '.';
                j++;
            }
        }
        i++;
    }
    tmp[j] = '\0';
    newLine = malloc(sizeof(char) * strlen(tmp));
    strcpy(newLine, tmp);
    free(tmp);
    return newLine;
}
