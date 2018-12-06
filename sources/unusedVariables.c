#include "variables.h"



int unusedVariables(){
	int lineN = 1;
	int i = 0;
	int k = 0;
	int err = 0;
	char* varName = malloc(sizeof(char) * 50);
	int node = 0; 
	int** allNodes = malloc(sizeof(int*) * 200);
	for(int j = 0; j < 200; j++){
	    allNodes[j] = malloc(sizeof(int) * 1);
	}
	char* line = malloc(sizeof(char) * 50);
	char* word = malloc(sizeof(char) * 50);
	char*** allVariables = malloc(sizeof(char**) * 200);
	for(int j = 0; j < 200; j++){
	    allVariables[j] = malloc(sizeof(char*) * 2);
	    for(int h = 0; h < 2; h++){
	        allVariables[j][h] = malloc(sizeof(char) * 50);       
	    }
	}
 
	
	for(int j = 0; j < 200; j++){
	        allVariables[j][0] = "0";
	        allVariables[j][1] = "unused";
	}
 
	FILE* f = fopen("test.c", "w");
	fprintf(f, "int a;\nint b;\nb = 5 + 10;\n a = a + b");
	fclose(f);
	f = fopen("test.c", "r");

	while(fgets(line, 50, f)){
		word = strtok(line, " ");
		while(word != NULL){
		    
    		    //Récupération du mot de la variable
    			while(word[k]){
    			    if((word[k] <= 122 && word[k] >= 97) || (word[k] >= 65 && word[k] <= 95 && k >= 1) || (word[k] >= 48 && word[k] <= 57 && k >= 1)){
    			        varName[k] = word[k];
    			    }else{
    			        break;
    			    }
    				k++;
    			}
    			if(k > 0){
    			    varName[k] = '\0';
    			}
    			//Boucle pour la déclaration de variables || Utilisation de la variable
    			while(allVariables[i]){
    			    //Commenté pour le if:   && allNodes[i] == node
    			    if(strcmp(varName, allVariables[i][0]) == 0 && word[k + 1] != '('){
    			        allVariables[i][1] = "used";
    			        break;
    			    }
    			    
    			    if(strcmp(allVariables[i][0], "0") == 0 && word[k + 1] != '('){
    			        //allVariables[i][0] = varName;
    			        k = 0;
    			        while(varName[k]){
    			            printf("\n\nHello%c", allVariables[i][0][k]);
    			            allVariables[i][0][k] = varName[k];
    			            k++;
    			        }
    			        printf("allVariables[0][0] = %s\n\n", allVariables[i][0]);
    			        //strcpy(allVariables[i][0], varName);
    			        //printf("%d   coucou             %s", i, allVariables[i][0]);
    			        //allNodes[i] = node;
    			        break;
    			    }
    			    i++;
    			}
    			i = 0;
    			k = 0;
    			word = strtok(NULL, " ");
    			printf("\nallVariables[0][0] = %s\n", allVariables[0][0]);
    		    strcpy(varName, "");
    			printf("\nallVariables[0][0] = %s\n", allVariables[0][0]);
            }
            lineN++;
		}


	printf("\nVariable: %s\nUtilisation: %s\n\nVariable: %s\nUtilisation: %s", allVariables[0][0], allVariables[0][1], allVariables[1][0], allVariables[1][1]);
	
	fclose(f);
	free(allVariables);
	free(line);
	free(word);
	return err;
}