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
void getVarMulti(int* k, char* word, char* varName);
void isWordSemicolon(int* k, char* word, char* varName, int* declaration, int* var);
void isWordComma(int* k, char* word, char* varName, int* declaration, int* var);
void assignVariableUndeclared(int* i, char*** allVariables, char* varName, int* declaration, char* word, int* k, int* j, int* h, int* lineN, char** allErrors, char* error, int** varNodes, char* filePath, int* l);
void assignVariableUnused(int* i, char*** allVariables, char* varName, int* declaration, char* word, int* k, int* j, int* h, int* lineN, int** varNodes, char* filePath, int* errorLine);


#endif // VARIABLES_H_INCLUDED
