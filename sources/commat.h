/*
	Creator : LAURENT Louis 20181101
	Last change : LAURENT Louis 20181117

	Fichier pour la vérification de syntaxe des virgules;

*/

#ifndef COMMAT_H_
#define COMMAT_H_

#include "stringUtils.h"
#include "fileUtils.h"

// Fonction de vérification des espaces entre les opérateurs, il prend en paramètre le nom du fichier
int functionTestCommat(char*);

// Fonction de vérification de la syntaxe des virgules pour une ligne, elle prend en paramètres la ligne, la taille de la ligne, le numéro de la ligne et le nom du fichier
int checkCommats(char*, int, int, char*);

// Fonction de vérification de la syntaxe des virgules pour toutes les lignes du fichier, elle prend en paramètres toutes les lignes du fichier, un tableau avec le nombre de charactères pour chaque ligne, le nombre de lignes et le nom du fichier
int processCommats(char**, int*, int, char*);

#endif
