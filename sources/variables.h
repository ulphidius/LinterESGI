#ifndef VARIABLES_H_INCLUDED
#define VARIABLES_H_INCLUDED

/*
**  Filename : variables.h
**
**  Made by : TeamDev
**
**  Description :
*/

/**
 * Lib
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * Define
 **/


/**
 * Structure
 **/



/**
 * Functions
 **/
int unusedVariables(char* filePath);
int noMultiDeclarations(char* filePath);
int undeclaredVariables(char* filePath);
int updateNodes(int j, int** allNodes, char* word);
int getVar(int k, char* word, char* varName, int* noSpace);
int isVar(char* varName);


#endif // VARIABLES_H_INCLUDED
