/*
	Creator : LAURENT Louis 20181015
	Last change : LAURENT Louis 20181028

	Fichier pour la vérification de syntaxe des operateurs.

*/

#ifndef OPERATOR_H_
#define OPERATOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stringUtils.h"
#include "fileUtils.h"

void functionTest();

// Fonction de vérification de validité de la syntaxe pour les opérateurs pour une ligne, il prend en paramètreq la chaine de caractères à traiter, le nombre de caractères et le numéro de la ligne 
void checkOperators(char*, int, int);

// Fonction de vérification des lignes d'un fichier, il prend en paramètre un tableau double dimensions avec les lignes du fichier, le nombre de caractères de ce fichier et le nombre de lignes de ce fichier.
void processOperators(char**, int*, int);

#endif