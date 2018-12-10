/*
	Creator : LAURENT Louis 20181202
	Last change : LAURENT Louis 20181202

	Fichier de vérification pour '{' à la fin d'une ligne.

*/

#ifndef ARRAY_BRACKET_EOL_H_
#define ARRAY_BRACKET_EOL_H_

#include "fileUtils.h"

// Fonction de vérification des {, elle prend en paramètre le nom du fichier à tester
int functionTestBracket(char*);

// Fonction de vérification de chaque ligne du fichier chargé en mémoire, elle prend en paramètre le fichier
int checkBracket(FILE*, char*);

// Fonction de vérification d'une ligne du fichier, elle prend en paramètres la ligne, le numéro de la ligne et pour finir le nom du fichier
int isTarget(char*, int, char*);
#endif