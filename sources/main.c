
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

    char **tab_excluded = malloc(sizeof(char*)*5);
    for(i = 0; i < 5; i ++){
        tab_excluded[i] = malloc(sizeof(char) * 200);
    }
    sprintf(tab_excluded[0], ".git");
    sprintf(tab_excluded[1], "INSTALL");
    sprintf(tab_excluded[2], "aikongroi.c");
    sprintf(tab_excluded[3], "gigeegt.c");
    sprintf(tab_excluded[4], "ssssf.c");

    readFolder(".");


    for(i = 0; i < 5; i ++){
        free(tab_excluded[i]);
    }
    free(tab_excluded);

	return 0;
}
