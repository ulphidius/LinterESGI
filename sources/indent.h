/*
	Creator : LAURENT Louis 20181118
	Last change : LAURENT Louis 20181118

	Fichier de vérification de l'indentation dans le fichier.

*/

#ifndef INDENT_H_
#define INDENT_H_

#include "fileUtils.h"

// Fonction de vérification de l'indentation au sein du fichier, il prend en paramètre le chemin du fichier
void functionTestIndent(char*);

void processIndent(char** lines, int numberOfLines, int* numberOfCharacters, char* path);

#endif