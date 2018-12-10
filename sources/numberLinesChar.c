/*
	Creator : LAURENT Louis 20181111
	Last change : LAURENT Louis 20181118

	Fichier pour les erreurs de nombre de lignes dans le fichier et de caractères par ligne.

*/
#include "numberLinesChar.h"

int checkLinesNumbers(char* path, int limit){
	FILE* file = NULL;
	int result = 0;
	int cpt = 0;
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
		printf("[Max-File-Line-Numbers] %s : %d (Suppérieur à %d) \n", path, result + 1, limit);
		cpt++;
	}

	fclose(file);
	return cpt;
}

int checkCharactersNumbers(char* path, int limit){
	FILE* file = NULL;
	int lines = 0;
	int i  = 0;
	int cpt = 0;
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
			printf("[Max-Line-Numbers] %s : l.%d\n", path, i + 1);
			cpt++;
		}	
	}
	free(numberOfCharacters);
	fclose(file);
}