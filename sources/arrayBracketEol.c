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


	fclose(file);
}

void checkBracket(FILE* file){
	int lines = 0;
	int i = 0;
	int y = 0;
	int* numberCharacters = NULL;
	char** content = NULL;

	if(file == NULL){
		fprintf(stderr, "Le chemin en paramètre est NULL\n");
		exit(EXIT_FAILURE);
	}

	lines = countNumberLines(file);
	numberCharacters = countNumberChar(file, lines);
	content = readLines(file, lines);

	for(i = 0; i < lines; i++){
		for(y = 0; y < numberCharacters[i]; y++){

		}
	}


}

int isTarget(char* line){

}