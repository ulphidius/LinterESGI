/*
**  Filename : error.c
**
**  Made by : TeamDev
**
**  Description : functions used to read .c files
**
**  Notes: Stockage des erreurs dans un fichiers, lecture du fichier à la fin du programme.
*/
#include "error.h"



int getConfErrors(){
    int error = 0;
    int lineN = 1;
    int lineSize;
    char* confFile = malloc(sizeof(char) * 1000);
    char* line = malloc(sizeof(char) * 50);
    char* ruleValue;

    FILE* f = fopen("main.lconf", "w");
    strcpy(confFile, "\n\n=extends\nmain.lconf\n\n=rules\n- indent = 1 \n- operators-spacing = off\n- indent = 50\n\n=excludedFiles\n- bonjour.c\n- test.c\n\n=recursive\ntrue\0");
    fprintf(f, confFile);
    fclose(f);


    f = fopen("main.lconf", "r");

    while(fgets(line, 50, f)){
       // printf("%s", line);

        //Vérification des clés
        if(strcmp(line, "\n") == 0 && lineN != 1){
            fgets(line, 50, f);
           // printf("%s", line);
            lineN++;
            if(strcmp(line, "=extends\n") != 0 && strcmp(line, "=rules\n") != 0 && strcmp(line, "=excludedFiles\n") != 0 && strcmp(line, "=recursive\n") != 0){
                lineSize = strlen(line);
                line[lineSize - 1] = '\0';
                printf("Erreur ligne %d, la cle %s n'existe pas\n", lineN, line);
                error = 1;
            }
        }


        //Vérification des BValues
        if(line[0] != '-' && strcmp(line, "\n") != 0 && line[0] != '='){
            if(strcmp(line, "true\n") != 0 && strcmp(line, "false\n") != 0 && strcmp(line, "true") != 0 && strcmp(line, "false") != 0){
                if(strchr(line, '.') == NULL){
                    lineSize = strlen(line);
                    line[lineSize - 1] = '\0';
                    printf("Erreur ligne %d, la valeur %s est inconnue\n", lineN, line);
                    error = 1;
                }
            }
        }


        //Vérification des Values
        if(line[0] == '-' && strcmp(line, "\n") != 0 && strchr(line, '=') == NULL && strchr(line, '.') == NULL){
            lineSize = strlen(line);
            line[lineSize - 1] = '\0';
            printf("Erreur ligne %d, la valeur %s est inconnue\n", lineN, line);
            error = 1;
        }


        //Vérification des CValues
        if(line[0] == '-' && strcmp(line, "\n") != 0 && strchr(line, '=') && strchr(line, '.') == NULL){
            lineSize = strlen(line);
            line[lineSize - 1] = ' ';
            separateContent(&line, &ruleValue);

            if(strcmp(line, "array-bracket-eol") == 0
               || strcmp(line, "operators-spacing") == 0
               || strcmp(line, "comma-spacing") == 0
               || strcmp(line, "comments-header") == 0
               || strcmp(line, "no-trailing-spaces") == 0
               || strcmp(line, "no-multi-declaration") == 0
               || strcmp(line, "unused-variable") == 0
               || strcmp(line, "undeclared-variable") == 0
               || strcmp(line, "no-prototype") == 0
               || strcmp(line, "unused-function") == 0
               || strcmp(line, "undeclared-function") == 0
               || strcmp(line, "variable-assignment-type") == 0
               || strcmp(line, "function-parameters-type") == 0){
                    if(strcmp(ruleValue, "on") != 0 && strcmp(ruleValue, "off") != 0){
                        error = 1;
                        printf("Erreur de valeur ligne %d", lineN);
                    }
               }else if(strcmp(line, "indent") == 0
               || strcmp(line, "max-line-numbers")== 0
               || strcmp(line, "max-file-line-numbers") == 0){
                    if(strcmp(ruleValue, "off") != 0 && isValueInteger() == 0)
                        printf("Erreur de valeur ligne %d", lineN);
                        error = 1;
               }else{
                    printf("Erreur ligne %d, ce nom de regle n\'existe pas", lineN);
                    error = 1;
               }
        }


        lineN++;
    }

    fclose(f);
    free(confFile);
    free(line);
    return error;
}

int isValueInteger(char* value){
    if(atoi(value) == 0 && strcmp(value, "0") != 0){
        return 0;
    }
    return 1;
}

void separateContentConf(char **value, char **content){
    char *tmp;
    char *stock;

    stock = malloc(sizeof(char) * strlen(*value));
    sprintf(stock, "%s", *value);
    tmp = strtok(stock, " ");
    tmp = strtok(NULL, " ");
    free(*value);
    (*value) = malloc(sizeof(char) * strlen(tmp));
    sprintf(*value, "%s", tmp);
    tmp = strtok(NULL, " ");
    tmp = strtok(NULL, " ");
    (*content) = malloc(sizeof(char) * strlen(tmp));
    sprintf(*content, "%s", tmp);
}
