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

// Fonction de vérification de validité de la syntaxe pour les opérateurs pour une ligne, il prend en paramètreq la chaine de caractères à traiter, le nombre de caractères, le numéro de la ligne et nom du fichier 
void checkOperators(char*, int, int, char*);

// Fonction de vérification des lignes d'un fichier, il prend en paramètre le path du fichier à vérifier.
void processOperators(char*);

#endif