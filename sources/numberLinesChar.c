/*
	Creator : LAURENT Louis 20181111
	Last change : LAURENT Louis 20181118

	Fichier pour les erreurs de nombre de lignes dans le fichier et de caractères par ligne.

*/
#include "numberLinesChar.h"

void checkLinesNumbers(char* path, int limit){
	FILE* file = NULL;
	int result = 0;
	char character = 0;

	if(path == NULL || limit <= 0){
		fprintf(stderr, "Erreur une des données en paramètre est vide \n");
		exit(EXIT_FAILURE);
	}

	file = fopen(path, "rb");

	while((character = fgetc(file)) != EOF){
		if(character == '\n'){
			result++;
		}
	}

	if((result + 1) > limit){
		printf("Erreur le nombre de lignes dans le fichier : %s est : %d et la limite est %d \n", path, result + 1, limit);
	}

	fclose(file);
}

void checkCharactersNumbers(char* path, int limit){
	FILE* file = NULL;
	int lines = 0;
	int i  = 0;
	int* numberOfCharacters = NULL;

	if(path == NULL || limit <= 0){
		fprintf(stderr, "Erreur une des données en paramètre est vide \n");
		exit(EXIT_FAILURE);
	}

	file = fopen(path, "rb");

	if(file == NULL){
		fprintf(stderr, "Erreur à l'allocation\n");
		exit(EXIT_FAILURE);	
	}

	lines = countNumberLines(file);
	numberOfCharacters = countNumberChar(file, lines);

	for(i  = 0; i < lines; i++){
		if(numberOfCharacters[i] > limit){
			printf("Erreur le nombre de caractères sur la ligne est : %d et la limite est : %d dans le fichier : %s à la ligne : %d\n", numberOfCharacters[i], limit, path, i);
		}	
	}
	free(numberOfCharacters);
	fclose(file);
}