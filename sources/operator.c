/*
	Creator : LAURENT Louis 20181015
	Last change : LAURENT Louis 20181125

	Fichier pour la vérification de syntaxe des operateurs.

*/

#include "operator.h"

int checkOperators(char* string, int sizeChaine, int lineNumber, char* path){
	int i = 0;
	int y = 0;
	int cpt = 0;
	int sizeSingle = 15;
	
	const char singleOperators[] = {'+', '-', '*', '/', '<', '>', '!', '?', ':', '~', '^', '=', '&', '|', '%'};

	for(i = 0; i < sizeChaine; i++){
		if(strlen(string) > 3){
			for(y = 0; y < sizeSingle; y++){
				if(string[i] == singleOperators[y]){
					if(i == 0 || i == (sizeChaine - 1)){
						fprintf(stdout, "[Operators-Spacing] %s on : %c l.%d\n", path, singleOperators[y], lineNumber + 1);
						cpt++;
					}else if(string[i - 1] != ' ' || string[i + 1] != ' '){
						switch(singleOperators[y]){
							case '+':
								cpt += plusCase(string, &i, lineNumber, path);	
								break;
							
							case '-':
								cpt += minusCase(string, &i, lineNumber, path);
								break;
							
							case '*':
								cpt += timesCase(string, &i, lineNumber, path);							
								break;
							
							case '/':
								cpt += divideCase(string, &i, lineNumber, path);
								break;
							
							case '<':
								cpt += lowerCase(string, &i, lineNumber, path);
								break;
							
							case '>':
								cpt += greaterCase(string, &i, lineNumber, path);
								break;
							
							case '!':
								cpt += exclamationMarkCase(string, &i, lineNumber, path);
								break;

							case '^':
								cpt += squareCase(string, &i, lineNumber, path);
								break;
							
							case '=':
								cpt += equalCase(string, &i, lineNumber, path);
								break;
							
							case '&':
								cpt += andCase(string, &i, lineNumber, path);								
								break;
							
							case '|':
								cpt += orCase(string, &i, lineNumber, path);
								break;
							
							case '%':
								cpt += moduloCase(string, &i, lineNumber, path);
								break;
						}
					}	
				}
			}
		}
	}

	return cpt;
}

int processOperators(char* path){
	
	FILE* file = NULL;
	char** strings = NULL;
	int numberOfLines = 0;
	int i = 0;
	int cpt = 0;
	int* numberCharacter = NULL;

	file = fopen(path, "rb");
	if(file == NULL){
		fprintf(stdout, "Echec de l'ouverture\n");
		exit(EXIT_FAILURE);
	}
	
	numberOfLines = countNumberLines(file);
	numberCharacter = countNumberChar(file, numberOfLines);
	strings = readLines(file, numberOfLines);


	for(i = 0; i < numberOfLines; i++){
		cpt += checkOperators(strings[i], numberCharacter[i], i, path);
	}

	freeArray2((void**)strings, numberOfLines);
	free(numberCharacter);
	return cpt;
}

void errorsGestionnary(char* operator, int lineNumber, char* path){
	fprintf(stdout, "[Operators-Spacing] %s on : %s l.%d \n", path, operator, lineNumber);


}

int plusCase(char* string, int* position, int lineNumber, char* path){
	int cpt = 0;
	if(string[*position + 1] == '='){
		if(string[*position - 1] != ' ' || string[*position + 2] != ' '){
			errorsGestionnary("+=", lineNumber + 1, path);
			*position += 2;
			cpt++;
		}else{
			*position += 2;
		}
	}else{
		errorsGestionnary("+", lineNumber + 1, path);
		cpt++;
	}
	return cpt;
}

int minusCase(char* string, int* position, int lineNumber, char* path){
	int cpt = 0;
	if(string[*position + 1] == '='){
		if(string[*position - 1] != ' ' || string[*position + 2] != ' '){
			errorsGestionnary("-=", lineNumber + 1, path);
			*position += 2;
			cpt++;
		}else{
			*position += 2;
		}
	}else{
		errorsGestionnary("-", lineNumber + 1, path);
		cpt++;
	}

	return cpt;
}

int timesCase(char* string, int* position, int lineNumber, char* path){
	int cpt = 0;
	if(string[*position + 1] == '='){
		if(string[*position - 1] != ' ' || string[*position + 2] != ' '){
			errorsGestionnary("*=", lineNumber + 1, path);
			*position += 2;
			cpt++;
		}else{
			*position += 2;
		}
	}else{
		errorsGestionnary("*", lineNumber + 1, path);
		cpt++;
	}
	return cpt;
}

int divideCase(char* string, int* position, int lineNumber, char* path){
	int cpt = 0;
	if(string[*position + 1] == '='){
		if(string[*position - 1] != ' ' || string[*position + 2] != ' '){
			errorsGestionnary("/=", lineNumber + 1, path);
			*position += 2;
			cpt++;
		}else{
			*position += 2;
		}
	}else{
		errorsGestionnary("/", lineNumber + 1, path);
		cpt++;
	}

	return cpt;
}

int greaterCase(char* string, int* position, int lineNumber, char* path){
	int cpt = 0;
	if(string[*position + 1] == '>'){
		if(string[*position + 2] == '='){
			if(string[*position - 1] != ' ' || string[*position + 3] != ' '){
				errorsGestionnary(">>=", lineNumber + 1, path);
				cpt++;
			}
			*position += 3;
		}else if(string[*position - 1] != ' ' || string[*position + 2] != ' '){
			errorsGestionnary(">>", lineNumber + 1, path);
			*position += 2;
			cpt++;
		}else{
			*position += 2;
		}
	}else if(string[*position + 1] == '='){
		if(string[*position - 1] != ' ' || string[*position + 2] != ' '){
			errorsGestionnary(">=", lineNumber + 1, path);
			*position += 2;
			cpt++;
		}else{
			*position += 2;
		}
	}else{
		errorsGestionnary(">", lineNumber + 1, path);
		cpt++;
	}

	return cpt;
}

int lowerCase(char* string, int* position, int lineNumber, char* path){
	int cpt = 0;
	if(string[*position + 1] == '<'){
		if(string[*position + 2] == '='){
			if(string[*position - 1] != ' ' || string[*position + 3] != ' '){
				errorsGestionnary("<<=", lineNumber + 1, path);
				cpt++;
			}
			*position += 3;
		}else if(string[*position - 1] != ' ' || (string[*position + 2] != ' ')){
			errorsGestionnary("<<", lineNumber + 1, path);
			*position += 2;
			cpt++;
		}else{
			*position += 2;
		}
	}else if(string[*position + 1] == '='){
		if(string[*position - 1] != ' ' || string[*position + 2] != ' '){
			errorsGestionnary("<=", lineNumber + 1, path);
			*position += 2;
			cpt++;
		}else{
			*position += 2;
		}
	}else{
		errorsGestionnary("<", lineNumber + 1, path);
		cpt++;
	}

	return cpt;
}

int exclamationMarkCase(char* string, int* position, int lineNumber, char* path){
	int cpt = 0;
	if(string[*position + 1] == '='){
		if(string[*position - 1] != ' ' || string[*position + 2] != ' '){
			errorsGestionnary("!=", lineNumber + 1, path);
			*position += 2;
			cpt++;
		}else{
			*position += 2;
		}
	}else{
		errorsGestionnary("!", lineNumber + 1, path);
		cpt++;
	}

	return cpt;
}

int squareCase(char* string, int* position, int lineNumber, char* path){
	int cpt = 0;

	if(string[*position + 1] == '='){
		if(string[*position - 1] != ' ' || string[*position + 2] != ' '){
			errorsGestionnary("^⁼", lineNumber + 1, path);
			*position += 2;
			cpt++;
		}else{
			*position += 2;
		}
	}else{
		errorsGestionnary("^", lineNumber + 1, path);
		cpt++;
	}

	return cpt;
}

int equalCase(char* string, int* position, int lineNumber, char* path){
	int cpt = 0;

	if(string[*position + 1] == '='){
		if(string[*position - 1] != ' ' || string[*position + 2] != ' '){
			errorsGestionnary("==", lineNumber + 1, path);
			*position += 2;
			cpt++;
		}else{
			*position += 2;
		}
	}else{
		errorsGestionnary("=", lineNumber + 1, path);
		cpt++;
	}

	return cpt;
}

int andCase(char* string, int* position, int lineNumber, char* path){
	int cpt = 0;

	if(string[*position + 1] == '&'){
		if(string[*position - 1] != ' ' || string[*position + 2] != ' '){
			errorsGestionnary("&&", lineNumber + 1, path);		
			*position += 2;
			cpt++;
		}else{
			*position += 2;
		}
	}else if(string[*position + 1] == '='){
		if(string[*position - 1] != ' ' || string[*position + 2] != ' '){
			errorsGestionnary("&=", lineNumber + 1, path);		
			*position += 2;
			cpt++;
		}else{
			*position += 2;
		}
	}else{
		errorsGestionnary("&", lineNumber + 1, path);	
		cpt++;
	}

	return cpt;
}

int orCase(char* string, int* position, int lineNumber, char* path){
	int cpt = 0;

	if(string[*position + 1] == '|'){
		if(string[*position - 1] != ' ' || string[*position + 2] != ' '){
			errorsGestionnary("||", lineNumber + 1, path);
			*position += 2;
			cpt++;
		}else{
			*position += 2;
		}
	}else if(string[*position + 1] == '='){
		if(string[*position - 1] != ' ' || string[*position + 2] != ' '){
			errorsGestionnary("|=", lineNumber + 1, path);
			*position += 2;
			cpt++;
		}else{
			*position += 2;
		}
	}else{
		errorsGestionnary("|", lineNumber + 1, path);
		cpt++;
	}

	return cpt;
}

int moduloCase(char* string, int* position, int lineNumber, char* path){
	int cpt = 0;

	if(string[*position + 1] == '='){
		if(string[*position - 1] != ' ' || string[*position + 2] != ' '){
			errorsGestionnary("%=", lineNumber + 1, path);
			*position += 2;
			cpt++;
		}else{
			*position += 2;
		}
	}else{
		errorsGestionnary("%", lineNumber + 1, path);
		cpt++;
	}

	return cpt;
}