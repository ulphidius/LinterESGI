/*
	Creator : LAURENT Louis 20181111
	Last change : LAURENT Louis 20181117

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

	if(result > limit){
		printf("Erreur le nombre de lignes dans le fichier : %s est : %d et la limite est %d \n", path, result, limit);
	}

	fclose(file);
}

void checkCharactersNumbers(char* path, int limit){
	FILE* file = NULL;
	int result = 0;
	char character = 0;

	if(path == NULL || limit <= 0){
		fprintf(stderr, "Erreur une des données en paramètre est vide \n");
		exit(EXIT_FAILURE);
	}

	file = fopen(path, "rb");

	while((character = fgetc(file)) != EOF){
		result++;

		if(result > limit){
			printf("Erreur le nombre de caractères sur la ligne est : %d et la limite est : %d dans le fichier : %s", result, limit, path);
		
		}

		if(character == '\n'){
			result = 0;
		}
	}

	fclose(file);
}