/*
	Creator : LAURENT Louis 20181202
	Last change : LAURENT Louis 20181202

	Fichier de vérification pour '{' à la fin d'une ligne.

*/

#ifndef ARRAY_BRACKET_EOL_H_
#define ARRAY_BRACKET_EOL_H_

#include "fileUtils.h"

// Fonction de vérification des {, elle prend en paramètre le nom du fichier à tester
void functionTestBracket(char*);

void checkBracket(FILE*, char*);

void isTarget(char*, int, char*);
#endif