#include "commat.h"
#include "config.h"
#include "confKey.h"
#include "error.h"
#include "file.h"
#include "numberLinesChar.h"
#include "trailingSpace.h"
#include "startComment.h"
#include "indent.h"

int main(){

int i;

    ConfigKey *conf;
    conf = loadConfig("\n");

    CheckFile * list;
/*
    list = initCheckFile("ok");

    printf("key : %s", list->name);*/

    readFolder(".",conf,&list);

    printCheckFile(list);

	return 0;
}
