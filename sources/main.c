#include "commat.h"
#include "config.h"
#include "confKey.h"
#include "error.h"
#include "linter.h"
#include "numberLinesChar.h"
#include "trailingSpace.h"
#include "startComment.h"
#include "indent.h"
#include "functions.h"

int main(){

//Charge la configuration
    ConfigKey *conf;
    //conf = loadConfig("\n");
    conf = loadAll("resources/main.lconf");
//Stocke en mémoire la liste des fichiers à lire
    CheckFile * list;
    if(conf == NULL){
        printf("error");
        return -1;
    }
    //printConfig(conf);
    readFolder(".",conf,&list);

    //printCheckFile(list);

    lintFile(conf,list,0);

	return 0;
}
