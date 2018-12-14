#include "commat.h"
#include "config.h"
#include "confKey.h"
#include "linter.h"
#include "numberLinesChar.h"
#include "trailingSpace.h"
#include "startComment.h"
#include "indent.h"
#include "functions.h"

int main(){


    ConfigKey *conf;
    //conf = loadConfig("\n");
    conf = loadAll("resources/main.lconf");
    //printConfig(conf);
    //Stocke en mémoire la liste des fichiers à lire
    CheckFile * list;
    if(conf == NULL){
        printf("error");
        return -1;
    }
    //printConfig(conf);
    readFolder(".",conf,&list);



    printCheckFile(list);
    //lintFile(conf,list,0);
    lintFile(conf,initCheckFile("resources/test_variable.c"),0);


    //processOperators("../resources/testFileOperator");
	// functionTestCommat("../resources/testFileOperator");
	// checkLinesNumbers("../resources/testFileOperator", atoi("30"));
	// checkCharactersNumbers("../resources/testFileOperator", atoi("10"));
	// functionTestTrailingSpace("../resources/testFileOperator");
	// functionStartComment("../resources/testFileOperator");
	// functionTestIndent("../resources/testFileOperator");
	// functionTestBracket("../resources/testFileOperator");

	return 0;
}
