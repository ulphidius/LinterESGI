#include "commat.h"
#include "config.h"
#include "confKey.h"
#include "error.h"
#include "linter.h"
#include "numberLinesChar.h"
#include "trailingSpace.h"
#include "startComment.h"
#include "indent.h"

int main(){

int i;

//Charge la configuration
    ConfigKey *conf;
    conf = loadConfig("\n");
//Stocke en mémoire la liste des fichiers à lire
    CheckFile * list;
    readFolder(".",conf,&list);

    printCheckFile(list);

    lintFile(conf,list);

	return 0;
}
