/*
	Creator : LAURENT Louis 20181118
	Last change : LAURENT Louis 20181118

	Fichier de vérification de l'indentation dans le fichier.

*/
#include "indent.h"

void functionTestIndent(char* path){
	FILE* file = NULL;
	int numberOfLines = 0;
	int* numberOfCharacters = NULL;
	char** lines = NULL;

	if(path == NULL){
		fprintf(stderr, "Le chemin en paramètre est NULL\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(path, "rb");

	if(file == NULL){
		fprintf(stderr, "Erreur à l'ouverture du fichier \n");
		exit(EXIT_FAILURE);
	}

	numberOfLines = countNumberLines(file);
	numberOfCharacters = countNumberChar(file, numberOfLines);
	
	lines = readLines(file, numberOfLines);
	
	processIndent(lines, numberOfLines, numberOfCharacters, path);

	freeArray2((void**)lines, numberOfLines);
	free(numberOfCharacters);
	fclose(file);
}

void processIndent(char** lines, int numberOfLines, int* numberOfCharacters, char* path){
    int i;
    int y;
    int indent;
    char indent_over;
    int level = 0;

    // printf("lol\n");
    
    for(i  = 0; i < numberOfLines; i++){
        indent = 0;
        indent_over = 0;
        for(y = 0; y < numberOfCharacters[i]; y++){
            switch(lines[i][y]){
                case '{':
                    level++;
                    break;
                case '}':
                    level--;
                    break;
                case '\t':
                    if (!indent_over)
                        indent++;
                    break;
                 default:
                    if (!indent_over && indent != level) {
                        indent_over = 1;
                        printf("Erreur d'indentation à la ligne : %d dans le fichier : %s\n", i + 1, path);
                    }
                    break;
            }
        }
    }
}