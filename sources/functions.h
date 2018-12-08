#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <string.h>
#include <stdlib.h>

int checkFunction(char *fp,int cas);
char ** arrayP(char** in, int size, char *add);
int asPrototype(char* name, char** list, int size);
int checkType(char* line);
int checkFunc(char* line);
char *mysubstr(char *src,char pos);
int checkName(char* name1, char* name2);
int checkDeclaration(char* type, char* name);
char* trim(char* line);

#endif // FUNCTIONS_H_INCLUDED
