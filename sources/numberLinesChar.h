/*
	Creator : LAURENT Louis 20181111
	Last change : LAURENT Louis 20181111

	Fichier pour les erreurs de nombre de lignes dans le fichier et de caractères par ligne.

*/

#ifndef NUMBER_LINES_CHAR_H_
#define NUMBER_LINES_CHAR_H_

#include "fileUtils.h"

// Foction de vérification du nombre de lignes dans le fichier, elle prend en paramètres le path du fichier et la limite à ne pas dépasser.
int checkLinesNumbers(char*, int);
// Fonction de vérification du nombre de caractères par lignes, elle prend en paramètres le path du fichier et la limite à ne pas dépasser.
int checkCharactersNumbers(char*, int);

#endif