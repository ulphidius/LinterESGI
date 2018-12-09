// #include "config.h"
// #include "confKey.h"
// #include "error.h"
// #include "linter.h"
// #include "functions.h"

int main(){

//Charge la configuration
<<<<<<< HEAD
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
=======
    // ConfigKey *conf;
    // conf = loadConfig("\n");
//Stocke en mémoire la liste des fichiers à lire
    // CheckFile * list;
    // readFolder(".",conf,&list);

    // printCheckFile(list);
	// fclose(file);
	// processOperators("../resources/testFileOperator");
	// functionTestCommat("../resources/testFileOperator");
	// checkLinesNumbers("../resources/testFileOperator", atoi("30"));
	// checkCharactersNumbers("../resources/testFileOperator", atoi("10"));
	// functionTestTrailingSpace("../resources/testFileOperator");
	// functionStartComment("../resources/testFileOperator");
	// functionTestIndent("../resources/testFileOperator");
	// functionTestBracket("../resources/testFileOperator");
    // lintFile(conf,list);
>>>>>>> ulphidius

	return 0;
}
