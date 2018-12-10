/*
	Creator : LAURENT Louis 20181118
	Last change : LAURENT Louis 20181118

	Fichier de vérification de l'indentation dans le fichier.

*/
#include "indent.h"

int functionTestIndent(char* path){
	FILE* file = NULL;
	int numberOfLines = 0;
	int err = 0;
	int* numberOfCharacters = NULL;
	char** lines = NULL;

	if(path == NULL){
		fprintf(stderr, "Le chemin en paramètre est NULL\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(path, "rb");

	if(file == NULL){
		fprintf(stderr, "Erreur à l'ouverture du fichier \n");
		exit(EXIT_FAILURE);
	}

	numberOfLines = countNumberLines(file);
	numberOfCharacters = countNumberChar(file, numberOfLines);

	lines = readLines(file, numberOfLines);

	err = processIndent(lines, numberOfLines, numberOfCharacters, path);

	freeArray2((void**)lines, numberOfLines);
	free(numberOfCharacters);
	fclose(file);

	return err;
}

int processIndent(char** lines, int numberOfLines, int* numberOfCharacters, char* path){
    int err = 0;
    int i;
    int y;
    int indent;
    char indentOver;
    int level = 0;

    for(i  = 0; i < numberOfLines; i++){
        indent = 0;
        indentOver = 0;
        for(y = 0; y < numberOfCharacters[i]; y++){
            switch(lines[i][y]){
                case '{':
                    level++;
                    break;
                case '}':
                    level--;
                    break;
                case '\t':
                    if (!indentOver)
                        indent++;
                    break;
                case '\r':
                    if (!indentOver)
                        indent++;
                    break;
                 default:
                    if (!indentOver && indent != level) {
                        indentOver = 1;
                        printf("[indent] %s : l.%d\n", path, i + 1);
						err ++;
                    }
                    break;
            }
        }
    }
    return err;
}
