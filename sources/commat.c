/*
	Creator : LAURENT Louis 20181101
	Last change : LAURENT Louis 20181117

	Fichier pour la vérification de syntaxe des virgules;

*/

#include "commat.h"

void functionTestCommat(char* path){
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

	processCommats(strings, numberCharacter, numberOfLines, path);

	freeArray2((void**)strings, numberOfLines);
	free(numberCharacter);
	fclose(file);
}

void checkCommats(char* string, int sizeLine, int numberLines, char* path){
	int y = 0;
	const char toCheck = ',';

	for(y = 0; y < sizeLine; y++){
		if(y == (sizeLine - 1) && string[y] == toCheck){
			fprintf(stdout, "Syntaxe error on line with operator : %c at line : %d on file : %s on character number : %d\n", toCheck, numberLines + 1, path , y + 1);
		}else{
			if(string[y] == toCheck && string[y + 1] != ' '){
				fprintf(stdout, "Syntaxe error on line with operator : %c at line : %d on file : %s on character number : %d\n", toCheck, numberLines + 1, path, y + 1);
			}
		}
	}

}

void processCommats(char** strings, int* sizeLine, int numberLines, char* path){
	int i = 0;

	for(i = 0; i < numberLines; i++){
		checkCommats(strings[i], sizeLine[i], i, path);
	}	
}