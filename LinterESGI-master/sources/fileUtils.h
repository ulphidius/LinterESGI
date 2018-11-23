/*
	Creator : LAURENT Louis 20181027
	Last change : LAURENT Louis 20181027

	Fichier utilitaire pour la manipulation des fichiers.

*/

#ifndef FILEUTILS_H_
#define FILEUTILS_H_

#include <stdlib.h>
#include <stdio.h>

#include "stringUtils.h"

// Fonction pour compter le nombre de ligne au sein du fichier envoyé en paramètre et renvoie le nombre de ligne au format integer.
int countNumberLines(FILE*);

// Fonction permetant de compter le nombre charactère sur chaque ligne, elle prend en paramètre le fichier ainsi que le nombre de ligne du fichier.
int* countNumberChar(FILE*, int);

// Fonction lecture des lignes d'un fichier il prend en paramètre le fichier à lire et le nombre de ligne, elle retourne un tableau avec les lignes du fichier.
char** readLines(FILE*, int);

#endif