/*
	Creator : LAURENT Louis 20181027
	Last change : LAURENT Louis 20181117

	Fichier utilitaire pour la manipulation des fichiers.

*/

#include "fileUtils.h"
#include "stringUtils.h"

int countNumberLines(FILE * file){
	int result = 0;
	char character = 0;

	if(file == NULL){
		fprintf(stderr, "Un des paramètres est incorrect\n");
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

// int* countNumberChar(FILE * file, int linesNumber){
// 	int* result = NULL;
// 	int cpt = -1;
// 	int cpt2 = 0;

// 	char startComment = 0;
// 	char multiComment = 0;
// 	char multiCommentEnd = 0;
// 	char lineComment = 0;
// 	char stringLine = 0;

// 	char character = 0;

// 	if(file == NULL || linesNumber <= 0){
// 		fprintf(stderr, "Un des paramètres est incorrect\n");
// 		exit(EXIT_FAILURE);
// 	}
// 	result = initArray("int", linesNumber);
	
// 	fseek(file, 0, SEEK_SET);
// 	while((character = fgetc(file)) != EOF){
// 		switch(character){
// 			case '\n':
// 				result[cpt2] = cpt;
// 				cpt = 0;
// 		 		cpt2++;
// 		 		lineComment = 0;	
// 				break;
// 			case '"':
// 				if(stringLine == 0){
// 					stringLine = 1;

// 				}else
// 					stringLine = 0;
					
// 				cpt++;
// 				break;
// 			case '/':
// 				if(stringLine == 1){
// 					cpt++;
				
// 				}else if(startComment == 0){
// 					startComment = 1;
// 					cpt++;
				
// 				}else if(startComment == 1){
// 					startComment = 0;
// 					lineComment = 1;
// 					cpt--;
				
// 				}else if(multiCommentEnd == 1){
// 					multiComment = 0;
// 					multiCommentEnd = 0;
				
// 				}
// 				break;
// 			case '*':
// 				if(stringLine == 1){
// 					cpt++;
				
// 				}else if(startComment == 1){
// 					multiComment = 1;
// 					startComment = 0;
// 					cpt--;
				
// 				}else if(multiComment == 1){
// 					multiCommentEnd = 1;

// 				}else if(multiComment == 0 && lineComment == 0){
// 					cpt++;
// 				}
// 				break;
// 			default :
// 				if(multiComment == 1 || lineComment == 1){
// 					cpt--;
// 				}
// 				startComment = 0;
// 				multiCommentEnd = 0;
// 				cpt++;
// 				break;
// 		}
// 	}

// 	return result;
// }

int* countNumberChar(FILE * file, int linesNumber){
    int* result = NULL;
    int i;
    int cpt;

    char is_inline_comment = 0;
    char is_block_comment = 0;
    char start_comment = 0;
    char end_comment = 0;
    char end_line;
    char is_string = 0;
    char character;

    if(file == NULL || linesNumber <= 0){
        fprintf(stderr, "Un des paramètres est incorrect\n");
        exit(EXIT_FAILURE);
    }
    result = malloc(sizeof(int) * linesNumber);

    fseek(file, 0, SEEK_SET);
    for (i = 0; i < linesNumber; i++) {
        end_line = 0;
        cpt = 0;
        while(!end_line && (character = fgetc(file)) != EOF){
            switch (character) {
                case '\n':
                    start_comment = 0;
                    end_comment = 0;
                    if (!is_string) {
                        is_inline_comment = 0;
                        end_line = 1;
                    } else {
                        cpt++;
                    }
                    break;
				case '"':
                    start_comment = 0;
                    end_comment = 0;
                    if (!is_inline_comment && !is_block_comment) {
                        is_string = !is_string;
                    }
                    break;
                case '/':
                    if (is_string) {
                        cpt++;
                    } else if (start_comment) {
                        start_comment = 0;
                        cpt--;
                        is_inline_comment = 1;
                    } else if (end_comment) {
                        end_comment = 0;
                        is_block_comment = 0;
                    } else if (!is_inline_comment && !is_block_comment) {
                        start_comment = 1;
                        cpt++;
                    }
                    break;
                case '*':
                    if (is_string) {
                        cpt++;
                    } if (start_comment) {
                        start_comment = 0;
                        cpt--;
                        is_block_comment = 1;
                    } else if (is_block_comment) {
                        end_comment = 1;
                    } else if (!is_inline_comment && !is_block_comment) {
                        cpt++;
                    }
                    break;
                default:
                    start_comment = 0;
                    end_comment = 0;
                    if (!is_inline_comment && !is_block_comment) {
                        cpt++;
                    }
                    break;
            }
        }
        result[i] = cpt;
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
        fprintf(stderr, "Un des paramètres est incorrect\n");
        exit(EXIT_FAILURE);
    }

    numberOfCharacter = countNumberChar(file, numberOfLines);

    lines = malloc(sizeof(char*) * numberOfLines);
    for (i = 0; i < numberOfLines; i++) {
        *(lines + i) = malloc(numberOfCharacter[i] + 1);
    }

    fseek(file, 0, SEEK_SET);
    for(i = 0; i < numberOfLines; i++){
        for(y = 0; y < numberOfCharacter[i]; y++){
            character = fgetc(file);
            lines[i][y] = character;
        }
        lines[i][y] = '\0';
        character = fgetc(file);
        while (character != '\n' && character != EOF) {
            character = fgetc(file);
        }
    }

    fclose(file);
    free(numberOfCharacter);

    return lines;
}