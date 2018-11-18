#include "operator.h"
#include "commat.h"
#include "numberLinesChar.h"
#include "trailingSpace.h"
#include "startComment.h"

int main(){
	//processOperators("../resources/testFileOperator");
	// FILE* file = NULL;
	// char character = 0;
	// file = fopen("../resources/testFileOperator", "rb");
	// if(file == NULL){
	// 	fprintf(stderr, "Erreur ouverture du fichier \n");
	// }
	// fseek(file, 0, SEEK_SET);
	// while(fgetc(file) != EOF){
		
	// 	printf("%ld\n", ftell(file));
	// 	fgetc(file);
	// 	printf("%ld\n", ftell(file));
	// 	fseek(file, -1, ftell(file));
	// 	printf("%ld\n", ftell(file));
	// }

	// fclose(file);
	// char * string = "../resources/testFileOperator";
	// int test1 = 0;

	// test1 = countNumberLines(file);
	// countNumberChar(file, test1);

	// fclose(file);
	processOperators("../resources/testFileOperator");
	functionTestCommat("../resources/testFileOperator");
	checkLinesNumbers("../resources/testFileOperator", 30);
	checkCharactersNumbers("../resources/testFileOperator", 10);
	functionTestTrailingSpace("../resources/testFileOperator");
	functionStartComment("../resources/testFileOperator");
	
	exit(EXIT_SUCCESS);
}