/*
	Creator : LAURENT Louis 20181117
	Last change : LAURENT Louis 20181118

	Fichier pour l'erreur de l'espace à la fin de ligne.

*/

#include "trailingSpace.h"

void functionTestTrailingSpace(char* path){
	FILE* file = NULL;
	char** strings = NULL;
	int numberOfLines = 0;
	int* numberCharacter = NULL;

	file = fopen(path, "rb");
	if(file == NULL){
		fprintf(stdout, "Echec de l'ouverture\n");
		exit(EXIT_FAILURE);
	}
	
	numberOfLines = countNumberLines(file);
	numberCharacter = countNumberChar(file, numberOfLines);
	strings = readLines(file, numberOfLines);

	processTrailingSpace(strings, numberCharacter, numberOfLines, path);

	freeArray2((void**)strings, numberOfLines);
	free(numberCharacter);

}

void checkTrailingSpaces(char* string, int sizeLine, int lineNumber, char* path){
	int i = 0;

	while(string[i] != '\0'){
		if(strlen(string) > 3){
			if(string[strlen(string) - 1] == ' '){
				printf("Erreur espace à la fin de la ligne : %d dans le fichier : %s\n", lineNumber + 1, path);
				break;
			}
		}
		i++;
	}
}

void processTrailingSpace(char** strings, int* sizeLine, int numberLines, char* path){
	int i = 0;

	for(i = 0; i < numberLines; i++){
		checkTrailingSpaces(strings[i], sizeLine[i], i, path);
	}	
}