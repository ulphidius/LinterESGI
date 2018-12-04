
#include "linter.h"

void lintFile(ConfigKey *conf, CheckFile *list)
{
    list = list->head;
    ConfigKey *rules = getConfigKey("rules", conf);

    printKey(rules);
    rules->cValue = rules->cValue->head;

    while(list != NULL){
        //list->name : "chemin du fichier"
        while(rules->cValue != NULL){
            switch(choiceRule(rules->cValue->content)){

                //case array-bracket-eol
                case 1:
                    if(strcmp(rules->cValue->value,"yourString") == 0){
                        printf("[x]cVal : %s\n",rules->cValue->value);
                    }else{
                        printf("[-]cVal : %s\n",rules->cValue->value);
                    }
                    break;

                //case indent
                case 2:
                    if(strcmp(rules->cValue->value,"yourString") == 0){
                        //func
                    }
                    break;

                //case comments-header
                case 3:
                    if(strcmp(rules->cValue->value,"yourString") == 0){
                        //func
                    }
                    break;

                //case no-trailing-spaces
                case 4:
                    if(strcmp(rules->cValue->value,"yourString") == 0){
                        //func
                    }
                    break;

                //case no-multi-declaration
                case 5:
                    if(strcmp(rules->cValue->value,"yourString") == 0){
                        //func
                    }
                    break;

                //case unused-variable
                case 6:
                    if(strcmp(rules->cValue->value,"yourString") == 0){
                        //func
                    }
                    break;

                //case undeclared-variable
                case 7:
                    if(strcmp(rules->cValue->value,"yourString") == 0){
                        //func
                    }
                    break;

                //case no-prototype
                case 8:
                    if(strcmp(rules->cValue->value,"yourString") == 0){
                        //func
                    }
                    break;

                //case unused-function
                case 9:
                    if(strcmp(rules->cValue->value,"yourString") == 0){
                        //func
                    }
                    break;

                //case undeclared-function
                case 10:
                    if(strcmp(rules->cValue->value,"yourString") == 0){
                        //func
                    }
                    break;

                //case variable-assignment-type
                case 11:
                    if(strcmp(rules->cValue->value,"yourString") == 0){
                        //func
                    }
                    break;

                //case function-parameters-type
                case 12:
                    if(strcmp(rules->cValue->value,"yourString") == 0){
                        //func
                    }
                    break;

                //case operators-spacing
                case 13:
                    if(strcmp(rules->cValue->value,"yourString") == 0){
                        //func
                    }
                    break;

                //case comma-spacing
                case 14:
                    if(strcmp(rules->cValue->value,"yourString") == 0){
                        //func
                    }
                    break;

                //case max-line-numbers
                case 15:
                    if(strcmp(rules->cValue->value,"yourString") == 0){
                        //func
                    }
                    break;

                //case max-file-line-numbers
                case 16:
                    if(strcmp(rules->cValue->value,"yourString") == 0){
                        //func
                    }
                    break;

                default :
                    printf("Erreur : la regle \"%s\" est inconnue.\n", rules->cValue->content);
                    break;

            }
            rules->cValue = rules->cValue->next;
        }
        list = list->next;
    }

}

int choiceRule(char *string){

    if(strcmp("array-bracket-eol",string) == 0){
      return 1;
    }
    if(strcmp("indent",string) == 0){
      return 2;
    }
    if(strcmp("comments-header",string) == 0){
      return 3;
    }
    if(strcmp("no-trailing-spaces",string) == 0){
      return 4;
    }
    if(strcmp("no-multi-declaration",string) == 0){
      return 5;
    }
    if(strcmp("unused-variable",string) == 0){
      return 6;
    }
    if(strcmp("undeclared-variable",string) == 0){
      return 7;
    }
    if(strcmp("no-prototype",string) == 0){
      return 8;
    }
    if(strcmp("unused-function",string) == 0){
      return 9;
    }
    if(strcmp("undeclared-function",string) == 0){
      return 10;
    }
    if(strcmp("variable-assignment-type",string) == 0){
      return 11;
    }
    if(strcmp("function-parameters-type",string) == 0){
      return 12;
    }
    if(strcmp("operators-spacing",string) == 0){
      return 13;
    }
    if(strcmp("comma-spacing",string) == 0){
      return 14;
    }
    if(strcmp("max-line-numbers",string) == 0){
      return 15;
    }
    if(strcmp("max-file-line-numbers",string) == 0){
      return 16;
    }

    return 0;
}


