/*
	Creator : LAURENT Louis 20181118
	Last change : LAURENT Louis 20181118

	Fichier de vérification du commentaire d'entête.

*/
#include "startComment.h"

int functionStartComment(char* path){
	FILE* file = NULL;
	char caracter1 = 0;
	char caracter2 = 0;
	int cpt = 0;

	if(path == NULL){
		fprintf(stderr, "Erreur path NULL\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(path, "rb");

	if(file == NULL){
		fprintf(stderr, "Erreur ouverture du fichier\n");
		exit(EXIT_FAILURE);
	}

	fseek(file, 0, SEEK_SET);
	caracter1 =  fgetc(file);
	caracter2 =  fgetc(file);
	if(caracter1 != '/' || caracter2 != '*'){
		fprintf(stdout, "[Comments_Header] %s l.1\n", path);
		cpt++;
	}

	fclose(file);
	return cpt;
}