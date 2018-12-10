/*
	Creator : LAURENT Louis 20181117
	Last change : LAURENT Louis 20181118

	Fichier pour l'erreur de l'espace à la fin de ligne.

*/

#include "trailingSpace.h"

int functionTestTrailingSpace(char* path){
	FILE* file = NULL;
	char** strings = NULL;
	int numberOfLines = 0;
	int cpt = 0;
	int* numberCharacter = NULL;

	file = fopen(path, "rb");
	if(file == NULL){
		fprintf(stdout, "Echec de l'ouverture\n");
		exit(EXIT_FAILURE);
	}
	
	numberOfLines = countNumberLines(file);
	numberCharacter = countNumberChar(file, numberOfLines);
	strings = readLines(file, numberOfLines);

	cpt = processTrailingSpace(strings, numberCharacter, numberOfLines, path);

	freeArray2((void**)strings, numberOfLines);
	free(numberCharacter);

	return cpt;
}

int checkTrailingSpaces(char* string, int sizeLine, int lineNumber, char* path){
	int i = 0;
	int cpt = 0;

	while(string[i] != '\0'){
		if(strlen(string) > 3){
			if(string[strlen(string) - 1] == ' '){
				printf("[Trailling-Space] %s : l.%d\n", path, lineNumber + 1);
				cpt++;
				break;
			}
		}
		i++;
	}

	return cpt;
}

int processTrailingSpace(char** strings, int* sizeLine, int numberLines, char* path){
	int i = 0;
	int cpt = 0;

	for(i = 0; i < numberLines; i++){
		cpt += checkTrailingSpaces(strings[i], sizeLine[i], i, path);
	}

	return cpt;	
}