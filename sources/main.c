#include "operator.h"

int main(){
	//processOperators("../resources/testFileOperator");
	FILE* file = NULL;
	char character = 0;
	file = fopen("../resources/testFileOperator", "rb");
	if(file == NULL){
		fprintf(stderr, "Erreur ouverture du fichier \n");
	}
	while((character = fgetc(file)) != EOF){
		fprintf(stdout, "Position du curseur : %d %c \n", SEEK_CUR, character);
		fgetc(file);
		//fprintf(stdout, "Position du curseur 2 : %d %c \n", SEEK_CUR, character = fgetc(file));
		fseek(file, -1, SEEK_CUR);
	}
	
	fclose(file);
	exit(EXIT_SUCCESS);
}