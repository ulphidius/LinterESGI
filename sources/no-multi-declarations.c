#include "variables.h"

int noMultiDeclarations(char* filePath){

    int err = 0;
    int lineN = 1;
    int k = 0;
    int i = 0;
    int l = 0;
    int var = 0;
    int declaration = 0;
    char* error = malloc(sizeof(char) * 100);
    char* line = malloc(sizeof(char) * 50);
    char* word = malloc(sizeof(char) * 50);
    char* varName = malloc(sizeof(char) * 50);
    char** allErrors = malloc(sizeof(char*) * 200);
    for(i = 0; i < 200; i++){
        allErrors[i] = malloc(sizeof(char) * 200);
    }
    i = 0;

    FILE* f = fopen(filePath, "r");

    while(fgets(line, 2000, f)){
        word = strtok(line, ",");
        var = 0;
            while(word !=  NULL){

               getVarMulti(&k, word, varName);

                if(k >= 1 && word[k] != '(')
                   isWordComma(&k, word, varName, &declaration, &var);
                if(var > 1){
                    sprintf(error, "\n[no-multi-declaration] %s : l.%d (Erreur: plusieurs variables sont declarees)", filePath, lineN);
                    strcpy(allErrors[l], error);
                    l++;
                    err++;
                    var = 0;
                }
                word = strtok(NULL, " ");
                k = 0;
                strcpy(varName, "");
            }
        lineN++;
    }


    lineN = 1;
    rewind(f);

    while(fgets(line, 2000, f)){
        word = strtok(line, ";");
        var = 0;
            while(word !=  NULL){

                getVarMulti(&k, word, varName);

                if(k >= 1 && word[k] != '(')
                    isWordSemicolon(&k, word, varName, &declaration, &var);

                if(var > 1){
                    sprintf(error, "\n[no-multi-declaration] %s : l.%d (Erreur: plusieurs variables sont declarees)", filePath, lineN);
                    strcpy(allErrors[l], error);
                    l++;
                    err++;
                    var = 0;
                }
                word = strtok(NULL, ";");
                k = 0;
                strcpy(varName, "");
            }
        lineN++;
    }

    while(i < l){
        printf("%s", allErrors[i]);
        i++;
    }
    fclose(f);
    return err;
}


void isWordComma(int* k, char* word, char* varName, int* declaration, int* var){
    if(strcmp(varName, "int") == 0 || strcmp(varName, "char") == 0 || strcmp(varName, "long") == 0 || strcmp(varName, "short") == 0 || strcmp(varName, "float") == 0 || strcmp(varName, "double") == 0 || strcmp(varName, "const") == 0){
        (*declaration) = 1;
    }
    if((*declaration) == 1 && varName[0] <= 122 && varName[0] >= 97 && word[*k] != '\n'){
        if(word[*k] == ';')
            (*declaration) = 0;
        (*var)++;
    }
}

void isWordSemicolon(int* k, char* word, char* varName, int* declaration, int* var){
    if(strcmp(varName, "int") == 0 || strcmp(varName, "char") == 0 || strcmp(varName, "long") == 0 || strcmp(varName, "short") == 0 || strcmp(varName, "float") == 0 || strcmp(varName, "double") == 0 || strcmp(varName, "const") == 0){
        (*declaration) = 1;
    }
    if((*declaration) == 1 && varName[0] <= 122 && varName[0] >= 97 && word[*k] != '\n'){
        (*declaration) = 0;
        (*var)++;
    }
    return;
}

void getVarMulti(int* k, char* word, char* varName){
    while(word[*k]){
        if((word[*k] <= 122 && word[*k] >= 97) || (word[*k] >= 65 && word[*k] <= 95 && (*k) >= 1) || (word[*k] >= 48 && word[*k] <= 57 && (*k) >= 1)){
            varName[*k] = word[*k];
            (*k)++;
        }else{
            break;
        }
    }
    return;
}
