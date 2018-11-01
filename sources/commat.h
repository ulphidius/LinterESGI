/*
	Creator : LAURENT Louis 20181101
	Last change : LAURENT Louis 20181101

	Fichier pour la vérification de syntaxe des virgules;

*/

#ifndef COMMAT_H_
#define COMMAT_H_

#include "stringUtils.h"
#include "fileUtils.h"

// Fonction de test
void functionTestCommat();

// Fonction de vérification de la syntaxe des virgules pour une ligne, elle prend en paramètres la ligne, la taille de la ligne et le numéro de la ligne
void checkCommats(char*, int, int);

// Fonction de vérification de la syntaxe des virgules pour toutes les lignes du fichier, elle prend en paramètres toutes les lignes du fichier, un tableau avec le nombre de charactères pour chaque ligne et le nombre de ligne
void processCommats(char**, int*, int);

#endif