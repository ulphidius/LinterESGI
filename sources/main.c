#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "config.h"
#include "commat.h"


typedef struct variable{
    char* name;
    int type;
} Variable;

int main(int argc,char *argv[]) {
    /** Load Config explained in #documentation **/
	ConfigKey *conf;
	conf = loadConfig("\n");
	
	
	
	
	
	freeConfig(conf->head);
	functionTestCommat();
	return 0;
}