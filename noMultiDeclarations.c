#include "variables.h"

int noMultiDeclaration(){
    int err = 0, err2 = 0;
    int pointVirgule = 0;
    int lineN = 1;
    char* line = malloc(sizeof(char) * 50);
    char* word = malloc(sizeof(char) * 50);

    FILE* f = fopen("test.c", "w");
    fprintf(f, "int a;\nint b;\nint c;int d;");
    fclose(f);
    f = fopen("test.c", "r");

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
        word = strtok(line, " ");
        if(strcmp(word, "int") == 0 || strcmp(word, "char") == 0 || strcmp(word, "long") == 0 || strcmp(word, "short") == 0 || strcmp(word, "float") == 0 || strcmp(word, "double") == 0 || strcmp(word, "const") == 0){
            while(word !=  NULL){
                word = str(line, ";");
                printf("word = %c\n", word[strlen(word) - 1]);
                if(word[1] == '\n')
                    break;
                if(strcmp(word, "int") == 0 || strcmp(word, "char") == 0 || strcmp(word, "long") == 0 || strcmp(word, "short") == 0 || strcmp(word, "float") == 0 || strcmp(word, "double") == 0 || strcmp(word, "const") == 0){
                    printf("Erreur: Multiples declarations de variables sur la ligne %d\n", lineN);
                    err++;
                }
                word = strtok(NULL, " ");
        }
        }
        lineN++;
    }

    fclose(f);
    return err;
}
