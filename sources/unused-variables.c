#include "variables.h"



int unusedVariables(char* filePath){
	int lineN = 1;
	int i = 0;
	int k = 0;
	int err = 0;
	int j = 0;
	int h = 0;
	int declaration = 0;
	int noSpace = 0;
	char breakChar;
	int* errorLine = malloc(sizeof(int *) * 200);
	char* varName = malloc(sizeof(char) * 50);
	int** allNodes = malloc(sizeof(int*) * 200);
	for(j = 0; j < 200; j++){
	    allNodes[j] = malloc(sizeof(int) * 1);
	    allNodes[j][0] = 0;
	}
	int** varNodes = malloc(sizeof(int*) * 200);
	for(j = 0; j < 200; j++){
	    varNodes[j] = malloc(sizeof(int) * 1);
	    varNodes[j][0] = 0;
	}
	char* line = malloc(sizeof(char) * 500);
	char* word = malloc(sizeof(char) * 500);
	char*** allVariables = malloc(sizeof(char**) * 200);
	for(j = 0; j < 200; j++){
	    allVariables[j] = malloc(sizeof(char*) * 2);
	    for(h = 0; h < 2; h++){
	        allVariables[j][h] = malloc(sizeof(char) * 50);
	    }
	}
	for(j = 0; j < 200; j++){
	        allVariables[j][0][0] = '0';
	        allVariables[j][1] = "unused";
	}

    j = 0;
    h = 0;

	FILE* f = fopen(filePath, "r");

	while(fgets(line, 500, f)){
		word = strtok(line, " ");
		while(word != NULL){

                j = updateNodes(j, allNodes, word);
                k = getVar(k, word, varName, &noSpace);


    			//Boucle pour la déclaration de variables || Utilisation de la variable
    			while(allVariables[i] && i < 200){
                        if(isVar(varName)){
                        declaration = 1;
    			        break;
    			    }
    			    //Commenté pour le if:   && allNodes[i] == node
    			    if(strcmp(varName, allVariables[i][0]) == 0 && word[k] != '(' && varNodes[i][0] == j){
    			        allVariables[i][1] = "used";
    			        errorLine[i] = -1;
    			        break;
    			    }

    			    if(strcmp(allVariables[i][0], "0") == 0 && word[k] != '(' && declaration == 1){
    			        h = 0;
    			        declaration = 0;
    			        varNodes[i][0] = j;
    			        while(varName[h]){
    			            allVariables[i][0][h] = varName[h];
    			            h++;
    			        }
    			        errorLine[i] = lineN;
    			        break;
    			    }

    			    if(word[k] == '{')
                        break;
    			    i++;
    			}
    			i = 0;
    			h = 0;
    			if(noSpace == 0){
    			    word = strtok(NULL, " ");
    			}else if(noSpace == 1){
    			    breakChar = word[k];
    			    word = strtok(word, &breakChar);
    			    word = strtok(NULL, &breakChar);
    			    noSpace = 0;
    			}
    			k = 0;
    		    strcpy(varName, "");
            }
            lineN++;
		}

    i = 0;
    while(strcmp(allVariables[i][0], "0") != 0){
        if(allVariables[i][0][0] <= 122 && allVariables[i][0][0] >= 97){
            if(strcmp(allVariables[i][1], "unused") == 0){
                printf("\n[unused-variables] %s : l.%d (Erreur, la variable %s n'est pas utilisee)", filePath, errorLine[i], allVariables[i][0]);
                err++;
            }
        }
        i++;
    }

	fclose(f);
	free(allVariables);
	free(line);
	free(word);
	free(errorLine);
	free(varNodes);
	free(allNodes);
    return err;
}
