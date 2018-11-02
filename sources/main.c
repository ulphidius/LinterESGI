#include "file.h"


typedef struct variable{
    char* name;
    int type;
} Variable;

int main(int argc,char *argv[]) {
    /** Load Config explained in #documentation **/
	ConfigKey *conf;
	conf = loadConfig("\n");
	ConfigKey *conf2;
	conf2 = loadConfig("\t");

	//fusionKey(conf,conf2);
	printConfig(conf);

	//printf(" excluded ? %d", isExcludedFile("test.c", conf));
	Error *type = initError();
	addErrorConf(type, 10, "main.c", "rule3 3+");
	addErrorConf(type, 100, "a.c", "rule3 3+");
	addErrorConf(type, 1235, "main.c", "rule3 3+");
	addErrorConf(type, 1043, "main.c", "rule3 3+");
	addErrorConf(type, 1503, "main.c", "rule3 3+");
	addErrorConf(type, 13430, "main.c", "rule3 3+");

	printError(type);
	freeError(type);

	freeConfig(conf->head);
	return 0;
}
