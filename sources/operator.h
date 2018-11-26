/*
	Creator : LAURENT Louis 20181015
	Last change : LAURENT Louis 20181125

	Fichier pour la vérification de syntaxe des operateurs.

*/

#ifndef OPERATOR_H_
#define OPERATOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stringUtils.h"
#include "fileUtils.h"

// Fonction de vérification de validité de la syntaxe pour les opérateurs pour une ligne, elle prend en paramètres la chaine de caractères à traiter, le nombre de caractères, le numéro de la ligne et nom du fichier 
void checkOperators(char*, int, int, char*);

// Fonction de vérification des lignes d'un fichier, elle prend en paramètre le path du fichier à vérifier.
void processOperators(char*);

// Fonction de gestion de l'affichage des erreurs, elle prend en paramètres l'opérateur cible, le numéro de la ligne et le nom du fichier
void errorsGestionnary(char*, int, char*);

// Gestion du cas avec +, elle prend en paramètres la ligne à tester, la position dans la ligne (on envoie dans ce cas l'adresse de la variable), le numéro de la ligne et le nom du fichier
void plusCase(char*, int*, int, char*);

// Gestion du cas avec -, elle prend en paramètres la ligne à tester, la position dans la ligne (on envoie dans ce cas l'adresse de la variable), le numéro de la ligne et le nom du fichier
void minusCase(char*, int*, int, char*);

// Gestion du cas avec *, elle prend en paramètres la ligne à tester, la position dans la ligne (on envoie dans ce cas l'adresse de la variable), le numéro de la ligne et le nom du fichier
void timesCase(char*, int*, int, char*);

// Gestion du cas avec /, elle prend en paramètres la ligne à tester, la position dans la ligne (on envoie dans ce cas l'adresse de la variable), le numéro de la ligne et le nom du fichier
void divideCase(char*, int*, int, char*);

// Gestion du cas avec >, elle prend en paramètres la ligne à tester, la position dans la ligne (on envoie dans ce cas l'adresse de la variable), le numéro de la ligne et le nom du fichier
void greaterCase(char*, int*, int, char*);

// Gestion du cas avec <, elle prend en paramètres la ligne à tester, la position dans la ligne (on envoie dans ce cas l'adresse de la variable), le numéro de la ligne et le nom du fichier
void lowerCase(char*, int*, int, char*);

// Gestion du cas avec !, elle prend en paramètres la ligne à tester, la position dans la ligne (on envoie dans ce cas l'adresse de la variable), le numéro de la ligne et le nom du fichier
void exclamationMarkCase(char*, int*, int, char*);

// Gestion du cas avec ^, elle prend en paramètres la ligne à tester, la position dans la ligne (on envoie dans ce cas l'adresse de la variable), le numéro de la ligne et le nom du fichier
void squareCase(char*, int*, int, char*);

// Gestion du cas avec =, elle prend en paramètres la ligne à tester, la position dans la ligne (on envoie dans ce cas l'adresse de la variable), le numéro de la ligne et le nom du fichier
void equalCase(char*, int*, int, char*);

// Gestion du cas avec &, elle prend en paramètres la ligne à tester, la position dans la ligne (on envoie dans ce cas l'adresse de la variable), le numéro de la ligne et le nom du fichier
void andCase(char*, int*, int, char*);

// Gestion du cas avec |, elle prend en paramètres la ligne à tester, la position dans la ligne (on envoie dans ce cas l'adresse de la variable), le numéro de la ligne et le nom du fichier
void orCase(char*, int*, int, char*);

// Gestion du cas avec %, elle prend en paramètres la ligne à tester, la position dans la ligne (on envoie dans ce cas l'adresse de la variable), le numéro de la ligne et le nom du fichier
void moduloCase(char*, int*, int, char*);

#endif