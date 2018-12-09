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

int* countNumberChar(FILE * file, int linesNumber){
    int* result = NULL;
    int i;
    int cpt;

    char commentLine = 0;
    char blockComment = 0;
    char startComment = 0;
    char endComment = 0;
    char endLine;
    char isString = 0;
    char character;

    if(file == NULL || linesNumber <= 0){
        fprintf(stderr, "Un des paramètres est incorrect\n");
        exit(EXIT_FAILURE);
    }
    result = malloc(sizeof(int) * linesNumber);

    fseek(file, 0, SEEK_SET);
    for (i = 0; i < linesNumber; i++) {
        endLine = 0;
        cpt = 0;
        while(!endLine && (character = fgetc(file)) != EOF){
            switch (character) {
                case '\n':
                    startComment = 0;
                    endComment = 0;
                    if (!isString) {
                        commentLine = 0;
                        endLine = 1;
                    } else {
                        cpt++;
                    }
                    break;
				case '"':
                    startComment = 0;
                    endComment = 0;
                    if (!commentLine && !blockComment) {
                        isString = !isString;
                    }
                    break;
                case '/':
                    if (isString) {
                        cpt++;
                    } else if (startComment) {
                        startComment = 0;
                        cpt--;
                        commentLine = 1;
                    } else if (endComment) {
                        endComment = 0;
                        blockComment = 0;
                    } else if (!commentLine && !blockComment) {
                        startComment = 1;
                        cpt++;
                    }
                    break;
                case '*':
                    if (isString) {
                        cpt++;
                    } if (startComment) {
                        startComment = 0;
                        cpt--;
                        blockComment = 1;
                    } else if (blockComment) {
                        endComment = 1;
                    } else if (!commentLine && !blockComment) {
                        cpt++;
                    }
                    break;
                default:
                    startComment = 0;
                    endComment = 0;
                    if (!commentLine && !blockComment) {
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