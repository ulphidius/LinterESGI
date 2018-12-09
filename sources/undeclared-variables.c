#include "variables.h"



int undeclaredVariables(char *filePath){
	int lineN = 1;
	int i = 0;
	int k = 0;
	int err = 0;
	int j = 0;
	int h = 0;
	int l = 0;
	int declaration = 0;
	int noSpace = 0;
	char breakChar;
	char* error = malloc(sizeof(char) * 100);
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
	char* line = malloc(sizeof(char) * 50);
	char* word = malloc(sizeof(char) * 50);
	char*** allVariables = malloc(sizeof(char**) * 200);
	for(j = 0; j < 200; j++){
	    allVariables[j] = malloc(sizeof(char*) * 2);
	    for(h = 0; h < 2; h++){
	        allVariables[j][h] = malloc(sizeof(char) * 50);
	    }
	}
	for(j = 0; j < 200; j++){
	        allVariables[j][0][0] = '0';
	        allVariables[j][1] = "undeclared";
	}
	char** allErrors = malloc(sizeof(char*) * 200);
    *allErrors = malloc(sizeof(char) * 200);

    j = 0;
    h = 0;

	FILE* f = fopen("test.c", "w");
	fprintf(f, "void test(){\nint a;\nint b;\nint d\nb=a+d;\nchar c;\nb += b;\n}\nint newTest(){\nint a;\n int b;\nb = d + b;\n}");
	fclose(f);
	f = fopen("test.c", "r");

	while(fgets(line, 50, f)){
		word = strtok(line, " ");
		while(word != NULL){
		        if(strchr(word, '{') != NULL){
		            if(allNodes[j][0] == 0){
		                j++;
		                allNodes[j][0]++;
		            }else if(allNodes[j][0] > 0){
		                allNodes[j][0]++;
		            }
		        }

		        if(strchr(word, '}') != NULL){
		            if(allNodes[j][0] > 0){
		                allNodes[j][0]--;
		            }
		        }

    		    //Récupération du mot de la variable
    			while(word[k]){
    			    if((word[k] <= 122 && word[k] >= 97) || (word[k] >= 65 && word[k] <= 95 && k >= 1) || (word[k] >= 48 && word[k] <= 57 && k >= 1)){
    			        varName[k] = word[k];
    			    }else if((word[k] == ',' || word[k] == '+' || word[k] == '-' || word[k] == '*' || word[k] == '/' || word[k] == '%' || word[k] == '=') && k >= 1){
    			        noSpace = 1;
    			        break;
    			    }else{
    			        break;
    			    }
    				k++;
    			}
    			if(k >= 1){
    			    varName[k] = '\0';
    			}

    			printf("\nvarName: %s\n", varName);
    			//Boucle pour la déclaration de variables || Utilisation de la variable
    			while(allVariables[i] && i < 200){
    			    if(strcmp(varName, "int") == 0 || strcmp(varName, "char") == 0 ||strcmp(varName, "float") == 0 ||strcmp(varName, "double") == 0 ||strcmp(varName, "long") == 0 ||strcmp(varName, "short") == 0 || strcmp(varName, "void") == 0){
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
    			    }else if(strcmp(allVariables[i][0], "0") == 0 && word[k] != '(' && declaration == 0 && varName[0] <= 122 && varName[0] >= 97){
    			        sprintf(error, "\nErreur ligne %d: la variable %s n\'est pas declaree", lineN, varName);
    			        strcpy(allErrors[l], error);
    			        l++;
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
    while(i < l){
        printf("%s", allErrors[i]);
        i++;
    }

	fclose(f);
	free(allVariables);
	free(line);
	free(word);
	return err;
}
