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

//Charge la configuration
    ConfigKey *conf;
    conf = loadConfig("\n");
//Stocke en mémoire la liste des fichiers à lire
    CheckFile * list;
    readFolder(".",conf,&list);

    printCheckFile(list);
	// fclose(file);
	// processOperators("../resources/testFileOperator");
	// functionTestCommat("../resources/testFileOperator");
	// checkLinesNumbers("../resources/testFileOperator", atoi("30"));
	// checkCharactersNumbers("../resources/testFileOperator", atoi("10"));
	// functionTestTrailingSpace("../resources/testFileOperator");
	// functionStartComment("../resources/testFileOperator");
	// functionTestIndent("../resources/testFileOperator");
	
    lintFile(conf,list);

	return 0;
}
