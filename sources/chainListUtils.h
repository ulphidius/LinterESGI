/*
	Creator : LAURENT Louis 20181202
	Last change : LAURENT Louis 20181202

	Fichier utilitaire pour la création de liste chainé.
*/
#ifndef CHAIN_LIST_UTILS_H_
#define CHAIN_LIST_UTILS_H_

#include <stdio.h>
#include <stdlib.h>

// Maillon de la chaine
typedef struct ChainLink{
	void* current;
	void* next;

} ChainLink;

// Element initial de la chaine.
typedef struct ChainStart{
	void* start;

} ChainStart;

// Initialisation de la chaine, elle prend en paramètre l'élement de la structure
ChainStart* initList(void*);

// Ajout d'un élément dans la chaine, elle prend en paramètres le début de la chaine et la valeur à ajouter
void addElement(ChainStart*, void*);

// Suppression d'un element de la chaine, elle prend en paramètres le début de chaine et la valeur à supprimer
void deleteElement(ChainStart*, void*); 

#endif