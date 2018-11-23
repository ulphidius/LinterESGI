/*
	Creator : LAURENT Louis 20181015
	Last change : LAURENT Louis 20181118

	Fichier pour la vérification de syntaxe des operateurs.

*/

#include "operator.h"

void checkOperators(char* string, int sizeChaine, int lineNumber, char* path){
	int i = 0;
	int y = 0;
	int sizeSingle = 15;
	
	const char singleOperators[] = {'+', '-', '*', '/', '<', '>', '!', '?', ':', '~', '^', '=', '&', '|', '%'};

	for(i = 0; i < sizeChaine; i++){
		if(strlen(string) > 3){
			for(y = 0; y < sizeSingle; y++){
				if(string[i] == singleOperators[y]){
					// printf("string : %s detected : %c",string, singleOperators[y]);
					// '+', '-', '*', '/', '<', '>', '!', '?', ':', '~', '^', '=', '&', '|', '%'
					// "<<=", ">>=", "||", "&&", "+=", "-=", "*=", "/=", "%=", "==", "^=", "<<", ">>", "|=", "&=", "+", "-", "*", "/", "%", "=", "^", "|", "&", "<", ">", "!", "?", ":"
					if(i == 0 || i == (sizeChaine - 1)){
						//printf("string : %s detected : %c position : %d\n",string, singleOperators[y], i);
						// printf("string : %s detected : %c\n",string, singleOperators[y]);
						fprintf(stdout, "Syntaxe error on line with operator : %c at line : %d inside file : %s\n", singleOperators[y], lineNumber + 1, path);
					}else if(string[i - 1] != ' ' || string[i + 1] != ' '){
						// printf("string : %s detected : %c\n",string, singleOperators[y]);
						switch(singleOperators[y]){
							case '+':
								if(string[i + 1] == '='){
									if(string[i - 1] != ' ' || string[i + 2] != ' '){
										fprintf(stdout, "Syntaxe error on line with operator : += at line : %d inside file : %s\n", lineNumber + 1, path);
										i += 2;
									}else{
										i += 2;
									}
								}else{
									fprintf(stdout, "Syntaxe error on line with operator : + at line : %d inside file : %s\n ", lineNumber + 1, path);
								}
								break;
							
							case '-':
								if(string[i + 1] == '='){
									if(string[i - 1] != ' ' || string[i + 2] != ' '){
										fprintf(stdout, "Syntaxe error on line with operator : -= at line : %d inside file : %s\n", lineNumber + 1, path);
										i += 2;
									}else{
										i += 2;
									}
								}else{
									fprintf(stdout, "Syntaxe error on line with operator : - at line : %d inside file : %s\n", lineNumber + 1, path);
								}
								break;
							
							case '*':
								if(string[i + 1] == '='){
									if(string[i - 1] != ' ' || string[i + 2] != ' '){
										fprintf(stdout, "Syntaxe error on line with operator : *= at line : %d inside file : %s\n", lineNumber + 1, path);
										i += 2;
									}else{
										i += 2;
									}
								}else{
									fprintf(stdout, "Syntaxe error on line with operator : * at line : %d inside file : %s\n", lineNumber + 1, path);
								}
								break;
							
							case '/':
								if(string[i + 1] == '='){
									if(string[i - 1] != ' ' || string[i + 2] != ' '){
										fprintf(stdout, "Syntaxe error on line with operator : /= at line : %d inside file : %s\n", lineNumber + 1, path);
										i += 2;
									}else{
										i += 2;
									}
								}else{
									fprintf(stdout, "Syntaxe error on line with operator : / at line : %d inside file : %s\n", lineNumber + 1, path);
								}
								break;
							
							case '<':
								if(string[i + 1] == '<'){
									if(string[i + 2] == '='){
										if(string[i - 1] != ' ' || string[i + 3] != ' '){
											fprintf(stdout, "Syntaxe error on line with operator : <<= at line : %d inside file : %s\n", lineNumber + 1, path);
										}
										i += 3;
									}else if(string[i - 1] != ' ' || (string[i + 2] != ' ' && string[i + 2] != '=')){
										fprintf(stdout, "Syntaxe error on line with operator : << at line : %d inside file : %s\n", lineNumber + 1, path);
										i += 2;
									}else{
										i += 2;
									}
								}else{
									fprintf(stdout, "Syntaxe error on line with operator : > at line : %d inside file : %s\n", lineNumber + 1, path);
								}
								break;
							
							case '>':
								if(string[i + 1] == '>'){
									if(string[i + 2] == '='){
										if(string[i - 1] != ' ' || string[i + 3] != ' '){
											fprintf(stdout, "Syntaxe error on line with operator : >>= at line : %d inside file : %s\n", lineNumber + 1, path);
										}
										i += 3;
									}else if(string[i - 1] != ' ' || string[i + 2] != ' '){
										fprintf(stdout, "Syntaxe error on line with operator : >> at line : %d inside file : %s\n", lineNumber + 1, path);
										i += 2;
									}else{
										i += 2;
									}
								}else{
									fprintf(stdout, "Syntaxe error on line with operator : > at line : %d inside file : %s\n", lineNumber + 1, path);
								}
								break;
							
							case '!':
								if(string[i + 1] == '='){
									if(string[i - 1] != ' ' || string[i + 2] != ' '){
										fprintf(stdout, "Syntaxe error on line with operator : != at line : %d inside file : %s\n", lineNumber + 1, path);
										i += 2;
									}else{
										i += 2;
									}
								}else{
									fprintf(stdout, "Syntaxe error on line with operator : ! at line : %d inside file : %s\n", lineNumber + 1, path);
								}
								break;

							case '^':
								if(string[i + 1] == '='){
									if(string[i - 1] != ' ' || string[i + 2] != ' '){
										fprintf(stdout, "Syntaxe error on line with operator : ^= at line : %d inside file : %s\n", lineNumber + 1, path);
										i += 2;
									}else{
										i += 2;
									}
								}else{
									fprintf(stdout, "Syntaxe error on line with operator : ^ at line : %d inside file : %s\n", lineNumber + 1, path);
								}
								break;
							
							case '=':
								if(string[i + 1] == '='){
									if(string[i - 1] != ' ' || string[i + 2] != ' '){
										fprintf(stdout, "Syntaxe error on line with operator : == at line : %d inside file : %s\n", lineNumber + 1, path);
										i += 2;
									}else{
										i += 2;
									}
								}else{
									fprintf(stdout, "Syntaxe error on line with operator : = at line : %d inside file : %s\n", lineNumber + 1, path);
								}
								break;
							
							case '&':
								if(string[i + 1] == '&'){
									if(string[i - 1] != ' ' || string[i + 2] != ' '){
										fprintf(stdout, "Syntaxe error on line with operator : && at line : %d inside file : %s\n", lineNumber + 1, path);
										i += 2;
									}else{
										i += 2;
									}
								}else if(string[i + 1] == '='){
									if(string[i - 1] != ' ' || string[i + 2] != ' '){
										fprintf(stdout, "Syntaxe error on line with operator : &= at line : %d inside file : %s\n", lineNumber + 1, path);
										i += 2;
									}else{
										i += 2;
									}
								}else{
									fprintf(stdout, "Syntaxe error on line with operator : & at line : %d inside file : %s\n", lineNumber + 1, path);
								}
								break;
							
							case '|':
								if(string[i + 1] == '|'){
									if(string[i - 1] != ' ' || string[i + 2] != ' '){
										fprintf(stdout, "Syntaxe error on line with operator : || at line : %d inside file : %s\n", lineNumber + 1, path);
										i += 2;
									}else{
										i += 2;
									}
								}else if(string[i + 1] == '='){
									if(string[i - 1] != ' ' || string[i + 2] != ' '){
										fprintf(stdout, "Syntaxe error on line with operator : |= at line : %d inside file : %s\n", lineNumber + 1, path);
										i += 2;
									}else{
										i += 2;
									}
								}else{
									fprintf(stdout, "Syntaxe error on line with operator : | at line : %d inside file : %s\n", lineNumber + 1, path);
								}
								break;
							
							case '%':
								if(string[i + 1] == '='){
									if(string[i - 1] != ' ' || string[i + 2] != ' '){
										fprintf(stdout, "Syntaxe error on line with operator : %s at line : %d inside file : %s\n", "%=", lineNumber + 1, path);
										i += 2;
									}else{
										i += 2;
									}
								}else{
									fprintf(stdout, "Syntaxe error on line with operator : %c at line : %d inside file : %s\n", singleOperators[14], lineNumber + 1, path);
								}
								break;
						}
					}	
				}
			}
		}
	}
}

void processOperators(char* path){
	
	FILE* file = NULL;
	char** strings = NULL;
	int numberOfLines = 0;
	int i = 0;
	int* numberCharacter = NULL;

	//checkOperators(string);

	file = fopen(path, "rb");
	if(file == NULL){
		fprintf(stdout, "Echec de l'ouverture\n");
		exit(EXIT_FAILURE);
	}
	
	numberOfLines = countNumberLines(file);
	// printf("%d\n", numberOfLines);
	numberCharacter = countNumberChar(file, numberOfLines);
	strings = readLines(file, numberOfLines);

	// for(i = 0; i < numberOfLines; i++){
	// 	printf("%s\n", strings[i]);
	// }

	// for(i = 0; i < numberOfLines; i++){
	// 	printf("%d\n", numberCharacter[i]);
	// }

	for(i = 0; i < numberOfLines; i++){
		checkOperators(strings[i], numberCharacter[i], i, path);
	}

	freeArray2((void**)strings, numberOfLines);
	free(numberCharacter);
}
