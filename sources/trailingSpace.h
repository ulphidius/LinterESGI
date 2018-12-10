/*
	Creator : LAURENT Louis 20181117
	Last change : LAURENT Louis 20181118

	Fichier pour l'erreur de l'espace à la fin de ligne.

*/
#ifndef TRAILING_SPACE_H_
#define TRAILING_SPACE_H_

#include "fileUtils.h"

// Fonction de vérification des espaces en fin de lignes, il prend en paramètre le chemin du fichier à tester
int functionTestTrailingSpace(char*);

// Fonction de vérification de la syntaxe des espaces pour une ligne, elle prend en paramètres la ligne, la taille de la ligne, le numéro de la ligne et le nom du fichier
int checkTrailingSpaces(char*, int, int, char*);

// Fonction de vérification de la syntaxe des espaces pour toutes les lignes du fichier, elle prend en paramètres toutes les lignes du fichier, un tableau avec le nombre de charactères pour chaque ligne, le nombre de lignes et le nom du fichier
int processTrailingSpace(char**, int*, int, char*);

#endif