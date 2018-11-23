/*
	Creator : LAURENT Louis 20181021
	Last change : LAURENT Louis 20181027

	Fichier avec des utilitaires pour les chaines de caractères.

*/

#ifndef STRINGUTILS_H_
#define STRINGUTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prend en paramètres le tableau et son nombres de colonnes 
void freeArray2(void**, int);

// Initialisation d'un tableau double dimenssions de type neutre elle prend en paramètres le type du futur tableau ainsi que la dimension du tableau et la taille de chaque éléments
void** initArray2(char*, int, int*);

// Initialisation d'un tableau de type neutre, elle prend en paramètres le type du futur tableau et ça dimension
void* initArray(char*, int);

// Initialisation d'un tableau double dimensions de char*, elle prend le nombre de colonnes ainsi que le nombres de lignes, pour la taille des chaines le +1 pour le `\0` est pris en compte
char** initChar2(int, int*);

// Initialisation d'un tableau de char, elle prend en paramètres la taille du tableau
char* initChar(int);

// Initialisation d'un tableau double dimensions de int, elle prend en paramètres le nombre de colonnes ainsi que le nombre de lignes 
int** initInt2(int, int*);

// Initialisation d'un tableau de int, elle prend en paramètres la taille du tableau
int* initInt(int);

// Initialisation d'un tableau double dimensions de float, elle prend en paramètres le nombre de colonnes ainsi que le nombre de lignes
float** initFloat2(int, int*);

// Initialisation d'un tableau de float, elle prend en paramètres la taille du tableau
float* initFloat(int);

// Initialisation d'un tableau double dimensions de double, elle prend en paramètres le nombre de colonnes ainsi que le nombre de lignes
double** initDouble2(int, int*);

// Initialisation d'un tableau de double, elle prend en paramètres la taille du tableau
double* initDouble(int);

// Affichage d'un tableau double dimmensions, elle prend en paramètres le type du tableau, le tableau, le nombre de colonnes et la taille des lignes 
void showArray2(char*, void**, int, int);

// Affichage d'un tableau de string, elle prend en paramètre le tableau et le nombre de colonnes
void showChar2(char**, int);

// Affichage d'un tableau de integer, elle prend en paramètre le tableau, le nombre de colonnes et le nombre de cellules
void showInt2(int**, int, int);

// Affichage d'un tableau de double, elle prend en paramètre le tableau, le nombre de colonnes et le nombre de cellules
void showDouble2(double**, int, int);

// Affichage d'un tableau de float, elle prend en paramètre le tableau, le nombre de colonnes et le nombre de cellules
void showFloat2(float**, int, int);

#endif