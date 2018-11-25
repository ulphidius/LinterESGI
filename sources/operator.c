/*
	Creator : LAURENT Louis 20181015
	Last change : LAURENT Louis 20181125

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
								plusCase(string, &i, lineNumber, path);	
								break;
							
							case '-':
								minusCase(string, &i, lineNumber, path);
								break;
							
							case '*':
								timesCase(string, &i, lineNumber, path);							
								break;
							
							case '/':
								divideCase(string, &i, lineNumber, path);
								break;
							
							case '<':
								lowerCase(string, &i, lineNumber, path);
								break;
							
							case '>':
								greaterCase(string, &i, lineNumber, path);
								break;
							
							case '!':
								exclamationMarkCase(string, &i, lineNumber, path);
								break;

							case '^':
								squareCase(string, &i, lineNumber, path);
								break;
							
							case '=':
								equalCase(string, &i, lineNumber, path);
								break;
							
							case '&':
								andCase(string, &i, lineNumber, path);								
								break;
							
							case '|':
								orCase(string, &i, lineNumber, path);
								break;
							
							case '%':
								moduloCase(string, &i, lineNumber, path);
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

void errorsGestionnary(char* operator, int lineNumber, char* path){
	fprintf(stdout, "Syntaxe error on line with operator : %s at line : %d inside file : %s\n", operator, lineNumber, path);

}

void plusCase(char* string, int* position, int lineNumber, char* path){
	if(string[*position + 1] == '='){
		if(string[*position - 1] != ' ' || string[*position + 2] != ' '){
			errorsGestionnary("+=", lineNumber + 1, path);
			*position += 2;
		}else{
			*position += 2;
		}
	}else{
		errorsGestionnary("+", lineNumber + 1, path);
	}
}

void minusCase(char* string, int* position, int lineNumber, char* path){
	if(string[*position + 1] == '='){
		if(string[*position - 1] != ' ' || string[*position + 2] != ' '){
			errorsGestionnary("-=", lineNumber + 1, path);
			*position += 2;
		}else{
			*position += 2;
		}
	}else{
		errorsGestionnary("-", lineNumber + 1, path);
	}
}

void timesCase(char* string, int* position, int lineNumber, char* path){
	if(string[*position + 1] == '='){
		if(string[*position - 1] != ' ' || string[*position + 2] != ' '){
			errorsGestionnary("*=", lineNumber + 1, path);
			*position += 2;
		}else{
			*position += 2;
		}
	}else{
		errorsGestionnary("*", lineNumber + 1, path);
	}
}

void divideCase(char* string, int* position, int lineNumber, char* path){
	if(string[*position + 1] == '='){
		if(string[*position - 1] != ' ' || string[*position + 2] != ' '){
			errorsGestionnary("/=", lineNumber + 1, path);
			*position += 2;
		}else{
			*position += 2;
		}
	}else{
		errorsGestionnary("/", lineNumber + 1, path);
	}
}

void greaterCase(char* string, int* position, int lineNumber, char* path){
	if(string[*position + 1] == '>'){
		if(string[*position + 2] == '='){
			if(string[*position - 1] != ' ' || string[*position + 3] != ' '){
				errorsGestionnary(">>=", lineNumber + 1, path);
			}
			*position += 3;
		}else if(string[*position - 1] != ' ' || string[*position + 2] != ' '){
			errorsGestionnary(">>", lineNumber + 1, path);
			*position += 2;
		}else{
			*position += 2;
		}
	}else if(string[*position + 1] == '='){
		if(string[*position - 1] != ' ' || string[*position + 2] != ' '){
			errorsGestionnary(">=", lineNumber + 1, path);
			*position += 2;
		}else{
			*position += 2;
		}
	}else{
		errorsGestionnary(">", lineNumber + 1, path);
	}
}

void lowerCase(char* string, int* position, int lineNumber, char* path){
	if(string[*position + 1] == '<'){
		if(string[*position + 2] == '='){
			if(string[*position - 1] != ' ' || string[*position + 3] != ' '){
				errorsGestionnary("<<=", lineNumber + 1, path);
			}
			*position += 3;
		}else if(string[*position - 1] != ' ' || (string[*position + 2] != ' ')){
			errorsGestionnary("<<", lineNumber + 1, path);
			*position += 2;
		}else{
			*position += 2;
		}
	}else if(string[*position + 1] == '='){
		if(string[*position - 1] != ' ' || string[*position + 2] != ' '){
			errorsGestionnary("<=", lineNumber + 1, path);
			*position += 2;
		}else{
			*position += 2;
		}
	}else{
		errorsGestionnary("<", lineNumber + 1, path);
	}	
}

void exclamationMarkCase(char* string, int* position, int lineNumber, char* path){
	if(string[*position + 1] == '='){
		if(string[*position - 1] != ' ' || string[*position + 2] != ' '){
			errorsGestionnary("!=", lineNumber + 1, path);
			*position += 2;
		}else{
			*position += 2;
		}
	}else{
		errorsGestionnary("!", lineNumber + 1, path);
	}
}

void squareCase(char* string, int* position, int lineNumber, char* path){
	if(string[*position + 1] == '='){
		if(string[*position - 1] != ' ' || string[*position + 2] != ' '){
			errorsGestionnary("^⁼", lineNumber + 1, path);
			*position += 2;
		}else{
			*position += 2;
		}
	}else{
		errorsGestionnary("^", lineNumber + 1, path);
	}
}

void equalCase(char* string, int* position, int lineNumber, char* path){
	if(string[*position + 1] == '='){
		if(string[*position - 1] != ' ' || string[*position + 2] != ' '){
			errorsGestionnary("==", lineNumber + 1, path);
			*position += 2;
		}else{
			*position += 2;
		}
	}else{
		errorsGestionnary("=", lineNumber + 1, path);
	}	
}

void andCase(char* string, int* position, int lineNumber, char* path){
	if(string[*position + 1] == '&'){
		if(string[*position - 1] != ' ' || string[*position + 2] != ' '){
			errorsGestionnary("&&", lineNumber + 1, path);		
			*position += 2;
		}else{
			*position += 2;
		}
	}else if(string[*position + 1] == '='){
		if(string[*position - 1] != ' ' || string[*position + 2] != ' '){
			errorsGestionnary("&=", lineNumber + 1, path);		
			*position += 2;
		}else{
			*position += 2;
		}
	}else{
		errorsGestionnary("&", lineNumber + 1, path);	
	}
}

void orCase(char* string, int* position, int lineNumber, char* path){
	if(string[*position + 1] == '|'){
		if(string[*position - 1] != ' ' || string[*position + 2] != ' '){
			errorsGestionnary("||", lineNumber + 1, path);
			*position += 2;
		}else{
			*position += 2;
		}
	}else if(string[*position + 1] == '='){
		if(string[*position - 1] != ' ' || string[*position + 2] != ' '){
			errorsGestionnary("|=", lineNumber + 1, path);
			*position += 2;
		}else{
			*position += 2;
		}
	}else{
		errorsGestionnary("|", lineNumber + 1, path);
	}
}

void moduloCase(char* string, int* position, int lineNumber, char* path){
	if(string[*position + 1] == '='){
		if(string[*position - 1] != ' ' || string[*position + 2] != ' '){
			errorsGestionnary("%=", lineNumber + 1, path);
			*position += 2;
		}else{
			*position += 2;
		}
	}else{
		errorsGestionnary("%", lineNumber + 1, path);
	}
}