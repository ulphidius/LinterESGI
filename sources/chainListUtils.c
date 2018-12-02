/*
	Creator : LAURENT Louis 20181202
	Last change : LAURENT Louis 20181202

	Fichier utilitaire pour la création de liste chainé.
*/
#include "chainListUtils.h"

ChainStart* initList(void* content){
	ChainStart* start = NULL;
	ChainLink* element = NULL;

	if(content == NULL){
		fprintf(stderr, "Paramètre vide envoyé \n");
		exit(EXIT_FAILURE);
	}

	start = malloc(sizeof(ChainStart) * 1);
	element = malloc(sizeof(ChainLink) * 1);

	if(start == NULL || element == NULL){
		fprintf(stderr, "Echec de l'allocation de la mémoire \n");
		exit(EXIT_FAILURE);	
	}

	element->current = content;
	element->next = NULL;

	start->start = element;

	return start;
}

void addElement(ChainStart* start, void* content){
	ChainLink* toLoad = NULL;
	ChainLink* current = NULL;

	if(start == NULL || content == NULL){
		fprintf(stderr, "Paramètre vide envoyé \n");
		exit(EXIT_FAILURE);
	}

	toLoad = malloc(sizeof(ChainLink) * 1);

	if(toLoad == NULL){
		fprintf(stderr, "Echec de l'allocation de la mémoire \n");
		exit(EXIT_FAILURE);	
	}

	toLoad->current = content;
	toLoad->next = NULL;
	
	current = start->start;

	while(current->next != NULL){
		current = current->next;
	}

	current->next = toLoad;

}