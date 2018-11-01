/*
	Creator : LAURENT Louis 20181015
	Last change : LAURENT Louis 20181029

	Fichier pour la vérification de syntaxe des operateurs.

*/

#include "operator.h"

void functionTest(){
	FILE* file = NULL;
	char* string = NULL;
	char* path = "../resources/testFileOperator";
	char** strings = NULL;
	int numberOfLines = 0;
	int* numberCharacter = NULL;
	int i = 0;
	string = malloc(sizeof(char) * 10);
	string = strcpy(string, "a+=b = 0");
	//checkOperators(string);

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

	processOperators(strings, numberCharacter, numberOfLines);

	freeArray2((void**)strings, numberOfLines);
	free(numberCharacter);
	free(string);

}

/*void checkOperators(char* string, int lineNumber){
	int i = 0;
	long int value = 0;
	char* startAdd = NULL;
	char* stockage = NULL;

	const char* operators[] = {"<<=", ">>=", "||", "&&", "+=", "-=", "*=", "/=", "%=", "==", "^=", "<<", ">>", "|=", "&=", "+", "-", "*", "/", "%", "=", "^", "|", "&", "<", ">", "!", "?", ":"};
	const int numberOperators = 29;
	
	if(string == NULL){
		exit(EXIT_FAILURE);
		fprintf(stdout, "\n");
	}
	startAdd = string;
	do{
		if(strlen(string) > 3){	
			for(i = 0; i < numberOperators; i++){
				if((stockage = strstr(string, operators[i])) != NULL){
					printf("first : %s | %s\n", string, stockage);
					if(*(stockage-1) != ' ' && *(stockage+1) != ' '){
						printf("Syntaxe error on line with operator : %s at line : %d\n", operators[i], lineNumber);
					}
					value = strlen(operators[i]) + (stockage - string);
					string += value;
					printf("second : %s | %s\n", string, stockage);
				}else{
					continue;
				}
			}	
		}	
	}while(stockage != NULL);
	
	string = startAdd;
}
*/

void checkOperators(char* string, int sizeChaine, int lineNumber){
	int i = 0;
	int y = 0;
	int sizeSingle = 16;
	
	//const char* operators[] = {"<<=", ">>=", "||", "&&", "+=", "-=", "*=", "/=", "%=", "==", "^=", "<<", ">>", "|=", "&=", "+", "-", "*", "/", "%", "=", "^", "|", "&", "<", ">", "!", "?", ":"};
	const char singleOperators[] = {'+', '-', '*', '/', '<', '>', '!', '?', ':', '~', '^', '=', '&', '|', '%'};

	for(i = 1; i < (sizeChaine - 1); i++){
		if(strlen(string) > 3){
			for(y = 0; y < sizeSingle; y++){
				if(string[i] == singleOperators[y]){
					//printf("string : %s detected : %c position : %d\n",string, singleOperators[y], i);
					if(string[i - 1] != ' ' || string[i + 1] != ' '){
						//printf("%c\n", singleOperators[y]);
						if(string[i + 1] == '<'){
							if(string[i + 2] == '='){
								if(string[i - 1] != ' ' || string[i + 3] != ' '){
									fprintf(stdout, "Syntaxe error on line with operator : %c<= at line : %d\n", singleOperators[y], lineNumber + 1);
								}
								i += 3;
							}else if(string[i - 1] != ' ' || (string[i + 2] != ' ' && string[i + 2] != '=')){
								fprintf(stdout, "Syntaxe error on line with operator : %c< at line : %d\n", singleOperators[y], lineNumber + 1);
								i += 2;
							}else{
								i += 2;
							}
						}else if(string[i + 1] == '>'){
							if(string[i + 2] == '='){
								if(string[i - 1] != ' ' || string[i + 3] != ' '){
									fprintf(stdout, "Syntaxe error on line with operator : %c>= at line : %d\n", singleOperators[y], lineNumber + 1);
								}
								i += 3;
							}else if(string[i - 1] != ' ' || string[i + 2] != ' '){
								fprintf(stdout, "Syntaxe error on line with operator : %c> at line : %d\n", singleOperators[y], lineNumber + 1);
								i += 2;
							}else{
								i += 2;
							}
						}else if(string[i + 1] == '|'){
							if(string[i - 1] != ' ' || string[i + 2] != ' '){
								fprintf(stdout, "Syntaxe error on line with operator : %c| at line : %d\n", singleOperators[y], lineNumber + 1);
								i += 2;
							}else{
								i += 2;
							}
						}else if(string[i + 1] == '&'){
							if(string[i - 1] != ' ' || string[i + 2] != ' '){
								fprintf(stdout, "Syntaxe error on line with operator : %c& at line : %d\n", singleOperators[y], lineNumber + 1);
								i += 2;
							}else{
								i += 2;
							}
						}else if(string[i + 1] == '='){
							if(string[i - 1] != ' ' || string[i + 2] != ' '){
								fprintf(stdout, "Syntaxe error on line with operator : %c= at line : %d\n", singleOperators[y], lineNumber + 1);
								i += 2;
							}else{
								i += 2;
							}
						}else{
							fprintf(stdout, "Syntaxe error on line with operator : %c at line : %d\n", singleOperators[y], lineNumber + 1);
							i += 1;
						}
					}	
				}
			}
		}
	}
}

void processOperators(char** strings, int* sizeLine, int numberLignes){
	int i = 0;

	for(i = 0; i < numberLignes; i++){
		checkOperators(strings[i], sizeLine[i], i);
	}	
}
