#include "variables.h"

int noMultiDeclarations(char* filePath){

    int err = 0;
    int lineN = 1;
    int k = 1;
    int i = 0;
    int l = 0;
    int var = 0;
    int declaration = 0;
    char* error = malloc(sizeof(char) * 100);
    char* line = malloc(sizeof(char) * 50);
    char* word = malloc(sizeof(char) * 50);
    char* varName = malloc(sizeof(char) * 50);
    char** allErrors = malloc(sizeof(char*) * 200);
    *allErrors = malloc(sizeof(char) * 200);

    FILE* f = fopen("test.c", "w");
    fprintf(f, "int a;\nint b;\nint c;int d;\nint\np;int o;");
    fclose(f);
    f = fopen("test.c", "r");

    //FILE* f = fopen(filePath, "r");

    while(fgets(line, 50, f)){
        word = strtok(line, " ");
        if(strcmp(word, "int") == 0 || strcmp(word, "char") == 0 || strcmp(word, "long") == 0 || strcmp(word, "short") == 0 || strcmp(word, "float") == 0 || strcmp(word, "double") == 0 || strcmp(word, "const") == 0){
            while(word !=  NULL){
                if(strchr(word, ',') != NULL){
                    printf("\nErreur: Multiples declarations de variables sur la ligne %d\n", lineN);
                    err++;
                }
                word = strtok(NULL, " ");
        }
        }
        lineN++;
    }


    lineN = 1;
    rewind(f);
    while(fgets(line, 50, f)){
        word = strtok(line, ";");
            while(word !=  NULL){
                printf("\nWord = %s", word);
                printf("\nvarName = %s", varName);
                printf("\nvar = %d", var);
                printf("\nDeclaration = %d\n", declaration);
                while(word[k]){
    			    if((word[k] <= 122 && word[k] >= 97) || (word[k] >= 65 && word[k] <= 95 && k >= 1) || (word[k] >= 48 && word[k] <= 57 && k >= 1)){
                        varName[k] = word[k];
                        k++;
    			    }else{
    			        break;
    			    }
    			}
                if(k >= 1 && word[k] != '('){
                    if(strcmp(varName, "int") == 0 || strcmp(varName, "char") == 0 || strcmp(varName, "long") == 0 || strcmp(varName, "short") == 0 || strcmp(varName, "float") == 0 || strcmp(varName, "double") == 0 || strcmp(varName, "const") == 0){
                        declaration = 1;
                    }else if(declaration == 1){
                        declaration = 0;
                        var++;
                    }
                }
                if(var > 0){
                    sprintf(error, "\nErreur ligne %d: plusieurs variables sont declarees", lineN);
                    strcpy(allErrors[l], error);
                    l++;
                    err++;
                }
                word = strtok(NULL, ";");
                k = 0;
            }
            var = 0;
        lineN++;
    }


    while(i < l){
        printf("%s", allErrors[i]);
        i++;
    }
    fclose(f);
    free(line);
    free(word);
    return err;
}
