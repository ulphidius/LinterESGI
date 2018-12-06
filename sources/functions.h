#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED


int unusedfunction(char *fp);
int checkType(char* line);
int checkFunc(char* line);
char *mysubstr(char *src,char pos);
int checkName(char* name1, char* name2);
int checkDeclaration(char* type, char* name);
char* trim(char* line);

#endif // FUNCTIONS_H_INCLUDED
