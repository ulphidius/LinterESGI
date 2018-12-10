/*
	Creator : LAURENT Louis 20181027
	Last change : LAURENT Louis 20181029

	Fichier utilitaire pour la manipulation des fichiers.

*/

#include "fileUtils.h"
#include "stringUtils.h"

int countNumberLines(FILE * file){
	int result = 0;
	char character = 0;

	if(file == NULL){
		fprintf(stdout, "Un des paramètres est incorrect\n");
		exit(EXIT_FAILURE);
	}

	fseek(file, 0, SEEK_SET);
	while((character = fgetc(file)) != EOF){
		if(character == '\n'){
			result++;
		}
	}

	return (result + 1);
}

int* countNumberChar(FILE * file, int linesNumber){
	int* result = NULL;
	int cpt = 0;
	int cpt2 = 0;
	char character = 0;

	if(file == NULL || linesNumber <= 0){
		fprintf(stdout, "Un des paramètres est incorrect\n");
		exit(EXIT_FAILURE);
	}

	result = initArray("int", linesNumber);
	fseek(file, 0, SEEK_SET);
	while((character = fgetc(file)) != EOF){
		cpt++;
		if(character == '\n'){
			result[cpt2] = cpt;
			cpt = 0;
			cpt2++;
		}
	}

	return result;
}

char** readLines(FILE* file, int numberOfLines){
	int* numberOfCharacter = NULL;
	int i = 0;
	int y = 0;
	char** lines = NULL;
	char character = 0;

	if(file == NULL || numberOfLines <= 0){
		fprintf(stdout, "Un des paramètres est incorrect\n");
		exit(EXIT_FAILURE);
	}

	numberOfCharacter = countNumberChar(file, numberOfLines);

	lines = (char**)initArray2("char", numberOfLines, numberOfCharacter);

	fseek(file, 0, SEEK_SET);
	for(i = 0; i < numberOfLines; i++){
		//printf("caracterNumber : %d\n", numberOfCharacter[i]);
		for(y = 0; y < numberOfCharacter[i]; y++){
			character = fgetc(file);
			if(character == '\n'){
				lines[i][y] = '\0';
			}else{
				lines[i][y] = character;
			}
		}
	}

	fclose(file);
	free(numberOfCharacter);

	return lines;
}