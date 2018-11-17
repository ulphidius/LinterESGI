/*
	Creator : LAURENT Louis 20181101
	Last change : LAURENT Louis 20181117

	Fichier pour la vérification de syntaxe des virgules;

*/

#include "commat.h"

void functionTestCommat(char* path){
	FILE* file = NULL;
	// char* path = "../resources/testFileOperator";
	char** strings = NULL;
	int numberOfLines = 0;
	int* numberCharacter = NULL;
	int i = 0;

	file = fopen(path, "rb");
	if(file == NULL){
		fprintf(stdout, "Echec de l'ouverture\n");
		exit(EXIT_FAILURE);
	}
	
	numberOfLines = countNumberLines(file);
	numberCharacter = countNumberChar(file, numberOfLines);
	strings = readLines(file, numberOfLines);

	for(i = 0; i < numberOfLines; i++){
		//printf("%s\n", strings[i]);
	}

	processCommats(strings, numberCharacter, numberOfLines, path);

	freeArray2((void**)strings, numberOfLines);
	free(numberCharacter);

}

void checkCommats(char* string, int sizeLine, int numberLignes, char* path){
	int y = 0;
	const char toCheck = ',';

	for(y = 0; y < sizeLine; y++){
		if(y == (sizeLine - 1) && string[y] == toCheck){
			fprintf(stdout, "Syntaxe error on line with operator : %c on file : %s at line : %d on character number : %d\n", toCheck, path, numberLignes + 1, y + 1);
		}else{
			if(string[y] == toCheck && string[y + 1] != ' '){
				fprintf(stdout, "Syntaxe error on line with operator : %c on file : %s at line : %d on character number : %d\n", toCheck, path, numberLignes + 1, y + 1);
			}
		}
	}

}

void processCommats(char** strings, int* sizeLine, int numberLignes, char* path){
	int i = 0;

	for(i = 0; i < numberLignes; i++){
		checkCommats(strings[i], sizeLine[i], i, path);
	}	
}