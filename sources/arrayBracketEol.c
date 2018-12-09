/*
	Creator : LAURENT Louis 20181202
	Last change : LAURENT Louis 20181202

	Fichier de vérification pour '{' à la fin d'une ligne.

*/

#include "arrayBracketEol.h"

void functionTestBracket(char* path){
	FILE* file = NULL;

	if(path == NULL){
		fprintf(stderr, "Le chemin en paramètre est NULL\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(path, "rb");
	if(file == NULL){
		fprintf(stderr, "Erreur à l'allocation de la mémoire \n");
		exit(EXIT_FAILURE);
	}

	checkBracket(file, path);

	fclose(file);
}

void checkBracket(FILE* file, char* path){
	int lines = 0;
	int i = 0;
	char** content = NULL;

	if(file == NULL){
		fprintf(stderr, "Le chemin en paramètre est NULL\n");
		exit(EXIT_FAILURE);
	}

	lines = countNumberLines(file);
	content = readLines(file, lines);

	for(i = 0; i < lines; i++){
		isTarget(content[i], i, path);
	}

	freeArray2((void**)content, lines);

}

void isTarget(char* line, int lineNumber, char* path){
	char* positionEOL = 0;

	if((positionEOL = strchr(line, '{')) != NULL){
		if((*(positionEOL + 1) != '\n' && *(positionEOL + 1) != '\0') || strlen(line) < 5){
			fprintf(stdout, "The { is not at the end of line on line : %d inside the file : %s\n", lineNumber, line);
		}
	}
}