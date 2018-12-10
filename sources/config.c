/*
**  Filename : config.c
**
**  Made by : TeamDev
**
**  Description : Used to load the configuration from lconf files
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "config.h"

char *strtok_r(char *s, const char *delim, char **save_ptr){
  char *end;
  if (s == NULL)
    s = *save_ptr;
  if (*s == '\0')
    {
      *save_ptr = s;
      return NULL;
    }
  /* Scan leading delimiters.  */
  s += strspn (s, delim);
  if (*s == '\0')
    {
      *save_ptr = s;
      return NULL;
    }
  /* Find the end of the token.  */
  end = s + strcspn (s, delim);
  if (*end == '\0')
    {
      *save_ptr = end;
      return s;
    }
  /* Terminate the token and make *SAVE_PTR point past it.  */
  *end = '\0';
  *save_ptr = end + 1;
  return s;
}

/**
 * Use as FILE* .lconf for test
 **/
char* myInput(int choice){
    char* val;
    val = malloc(sizeof(char) * 200);
        switch(choice){
            case 1 :
                sprintf(val, "=rules\n- rule4 = on\n- rule5 = off\n- rule6 = 50\n\n=excludedFiles\n- bonjour.c\n- config.c\n\n=recursive\nfalse");
                break;

            default :
                sprintf(val, "=extends\nmain.lconf\n\n=rules\n- array-bracket-eol = 1\n- rule2 = off\n- rule3 = 50\n\n=excludedFiles\n- bonjour.c\n- config.c\n\n=recursive\ntrue");
                break;
    }
    return val;
}

/**
 * Get the size of the file for allocation
 **/
int getFileSize(FILE *fp){
    long size;
    fseek(fp, 0, 2);
    size = ftell(fp);
    fseek(fp, 0, 0);
    return (int)size;
}

/**
 * Initialisation of a basic value (as VALUE)
 **/
ConfigBasicValue* initConfigBasicValue(char* name){
	ConfigBasicValue* ll;

	ll = malloc(sizeof(ConfigBasicValue));
	ll->content = malloc(strlen(name));
	sprintf(ll->content, "%s", name);
	ll->next = NULL;
    ll->head = NULL;
    return ll;
}

/**
 * Initialisation of a basic value (as - VALUE)
 **/
ConfigValue* initConfigValue(char* name){
	ConfigValue* ll;

	ll = malloc(sizeof(ConfigValue));
	ll->content = malloc(strlen(name));
	sprintf(ll->content, "%s", name);
	ll->next = NULL;
    ll->head = NULL;
    return ll;
}

/**
 * Initialisation of a content value (as - CONTENT = VALUE)
 **/
ConfigContentValue* initConfigContentValue(char* name, char* value){
	ConfigContentValue* ll;

	ll = malloc(sizeof(ConfigContentValue));
	ll->content = malloc(strlen(name));
	sprintf(ll->content, "%s", name);
	ll->value = malloc(strlen(value));
	sprintf(ll->value, "%s", value);
	ll->next = NULL;
    ll->head = NULL;
    return ll;
}

/**
 * get all values of the top key
 **/
int getValue(char* text, ConfigKey* key){
    char *rValue;
    char *stock;
    char *temp;
    char *eValue;
    ConfigValue* vHead = NULL;
    ConfigBasicValue* bvHead = NULL;
    ConfigContentValue* cvHead = NULL;

    temp = malloc(strlen(text) + 1);
	strcpy(temp, text);

	stock = strtok_r(temp, "\n", &temp); //                             strtok_r can cut multiple string in a row
	while( stock != NULL && strlen(stock) > 2){
	    if(stock[0] == '=' || stock[0] == '\n'){
	        break;
	    }
        rValue = malloc(200);
		if(stock[0] == '-'){
		    stock += 2; //                                              +2 for '- '
			if(strchr(stock, '=') == NULL){ //                          is a cValue
				sprintf(rValue, "%s", stock);
				if(vHead == NULL){
				    key->value = initConfigValue(rValue);
				}else{
				    key->value->next = initConfigValue(rValue);
				}
				if(vHead == NULL){
				    vHead = key->value;
			        vHead->head = vHead;
				}else{
				    key->value->next->head = key->value->head;
				    key->value = key->value->next;
				}
			}else{  //                                                  is a value
				sprintf(rValue, "%s",stock);
				separateContent(&rValue, &eValue);
				if(cvHead == NULL){
				    key->cValue = initConfigContentValue(rValue, eValue);
				}else{
			    	key->cValue->next = initConfigContentValue(rValue, eValue);
		            free(eValue);
				}
				if(cvHead == NULL){
				    cvHead = key->cValue;
				    cvHead->head = cvHead;
				}else{
				    key->cValue->next->head = key->cValue->head;
				    key->cValue = key->cValue->next;
				}

			}
		}else{  //                                                      is a bValue
			sprintf(rValue, "%s",stock);
			if(bvHead == NULL){
			    key->bValue = initConfigBasicValue(rValue);
			}else{
    			key->bValue->next = initConfigBasicValue(rValue);
			}
			if(bvHead == NULL){
			    bvHead = key->bValue;
			    bvHead->head = bvHead;
			}else{
			    key->bValue->next->head = key->bValue->head;
			    key->bValue = key->bValue->next;
			}

		}

		stock = strtok_r(NULL, "\n", &temp);
		free(rValue);
	}
	if(key->next != NULL)
	    freeConfigKey(key->next);
	key->value = vHead;
	key->bValue = bvHead;
	key->cValue = cvHead;

    return 0;
}

/**
 * Get the first key of the text given, and reduce him
 **/
char* getKey(char** text){
    char *key;
	char *first;
	char *last;

    if(strstr(*text, "\n\n=") == NULL){//               remove the "\n\n=" string
        return NULL;
    }
    *text = strstr(*text, "\n\n=") + sizeof(char) * 3;

	first = malloc(strlen(*text) + 1);
	strcpy(first, *text);//                             To prevent strtok to cut the original string
    last = strtok(first, "\n");

    key = malloc(sizeof(char) * (strlen(last) + 1));
    strcpy(key, last);
    *text += strlen(last) + 1;//                        remove the KEY and '\n'
    free(first);

    return key;
}

/**
 * check if other l.conf file need to be added to conf file.
 **/
char* isExtending(ConfigKey* conf){
    conf = conf->head;
    ConfigKey* test = getConfigKey("extends", conf);
    char* t;
	if(test != NULL){
	    t = malloc(sizeof(char) * strlen(test->bValue->content + 1));
	    sprintf(t,"%s", test->bValue->content);
	    return t;
	}
	return NULL;
}

/**
 * Cut in two element the string, separate by " = " (case : CVALUE)
 **/
void separateContent(char **value, char **content){
    char *tmp;
    char *stock;

    stock = malloc(sizeof(char) * strlen(*value));
    sprintf(stock, "%s", *value);
    tmp = strtok(stock, " ");
    free(*value);
    (*value) = malloc(sizeof(char) * strlen(tmp));
    sprintf(*value, "%s", tmp);
    tmp = strtok(NULL, " ");
    tmp = strtok(NULL, " ");
    (*content) = malloc(sizeof(char) * strlen(tmp));
    sprintf(*content, "%s", tmp);
}

/**
 * Add a BValue at the end of a given conf;
 **/
int addBValueKey(ConfigKey* conf, ConfigKey* conf2){
    ConfigKey *current;
    ConfigKey *tempConf;
    ConfigKey *endConf;
    int empty = 0;

    endConf = conf;
    if(conf->bValue == NULL){
        empty = 1;
    }else{
        while(endConf->bValue->next != NULL){
            endConf->bValue = endConf->bValue->next;
        }
    }
    conf2->bValue = conf2->bValue->head;
    while(conf2->bValue != NULL){
        if(asConfigKey(conf2->bValue->content, conf, BVALUE) == NULL){
            if(empty == 1){
                endConf->bValue = initConfigBasicValue(conf2->bValue->content);
                endConf->bValue->head = endConf->bValue;
                empty = 0;
            }else{
                endConf->bValue->next = initConfigBasicValue(conf2->bValue->content);
                endConf->bValue->next->head = endConf->bValue->head;
            }
            endConf->bValue = endConf->bValue->next;
        }
        conf2->bValue = conf2->bValue->next;
    }
    conf->bValue = conf->bValue->head;
    return 1;
}

/**
 * Add a Value at the end of a given conf;
 **/
int addValueKey(ConfigKey* conf, ConfigKey* conf2){
    ConfigKey *current;
    ConfigKey *tempConf;
    ConfigKey *endConf;
    int empty = 0;

    endConf = conf;
    if(conf->value == NULL){
        empty = 1;
    }else{
        while(endConf->value->next != NULL){
            endConf->value = endConf->value->next;
        }
    }
    conf2->value = conf2->value->head;
    while(conf2->value != NULL){
        if(asConfigKey(conf2->value->content, conf, BVALUE) == NULL){
            if(empty == 1){
                endConf->value = initConfigValue(conf2->value->content);
                endConf->value->head = endConf->value;
                empty = 0;
            }else{
                endConf->value->next = initConfigValue(conf2->value->content);
                endConf->value->next->head = endConf->value->head;
            }
            endConf->value = endConf->value->next;
        }
        conf2->value = conf2->value->next;
    }
    conf->value = conf->value->head;
    return 1;
}

/**
 * Add a CValue at the end of a given conf;
 **/
int addCValueKey(ConfigKey* conf, ConfigKey* conf2){
    ConfigKey *current;
    ConfigKey *tempConf;
    ConfigKey *endConf;
    int empty = 0;

    endConf = conf;
    if(conf->cValue == NULL){
        empty = 1;
    }else{
        while(endConf->cValue->next != NULL){
            endConf->cValue = endConf->cValue->next;
        }
    }
    conf2->cValue = conf2->cValue->head;
    while(conf2->cValue != NULL){
        if(asConfigKey(conf2->cValue->content, conf, BVALUE) == NULL){
            if(empty == 1){
                endConf->cValue = initConfigContentValue(conf2->cValue->content, conf2->cValue->value);
                endConf->cValue->head = endConf->cValue;
                empty = 0;
            }else{
                endConf->cValue->next = initConfigContentValue(conf2->cValue->content, conf2->cValue->value);
                endConf->cValue->next->head = endConf->cValue->head;
            }
            endConf->cValue = endConf->cValue->next;
        }
        conf2->cValue = conf2->cValue->next;
    }
    conf->cValue = conf->cValue->head;

    return 1;
}

/**
 * Free the whole Bvalue of a key
 **/
void freeConfigBasicValue(ConfigBasicValue* val){
    if(val->next != NULL){
        freeConfigBasicValue(val->next);
    }
    free(val);
    //printf("-b-");
}

/**
 * Free the whole value of a key
 **/
void freeConfigValue(ConfigValue* val){
    if(val->next != NULL){
        freeConfigValue(val->next);
    }
    free(val);
    //printf("-v-");
}

/**
 * Free the whole Cvalue of a key
 **/
void freeConfigContentValue(ConfigContentValue* val){
    if(val->next != NULL){
        freeConfigContentValue(val->next);
    }
    free(val);
    //printf("-c-");
}

/**
 * Print the whole config
 **/
void printConfig(ConfigKey* key){
    ConfigKey* kHead;
    ConfigBasicValue* bvHead;
    ConfigValue* vHead;
    ConfigContentValue* cvHead;

    kHead = key;


    printf("/---------------------------\n");
    while(key != NULL){
        printKey(key);
        printf("\n\n");
        key = key->next;
    }
    printf("\\---------------------------\n");

    key = kHead;
}

/**
 * Print the current key
 **/
void printKey(ConfigKey* key){
    ConfigBasicValue* bvHead;
    ConfigValue* vHead;
    ConfigContentValue* cvHead;

    printf("|=%s\n", key->name);
    bvHead = key->bValue;
    if(bvHead != NULL)
        bvHead = key->bValue->head;
    while(key->bValue != NULL){ //bValue
        printf("|%s\n", key->bValue->content);
        key->bValue = key->bValue->next;
    }
    if(bvHead != NULL){
        key->bValue = bvHead;
    }
    vHead = key->value;
    if(vHead != NULL)
        vHead = key->value->head;
    while(key->value != NULL){ //value
        printf("|- %s\n", key->value->content);
        key->value = key->value->next;
    }
    if(vHead != NULL){
        key->value = vHead;
    }
    cvHead = key->cValue;
    if(cvHead != NULL)
        cvHead = key->cValue->head;
    while(key->cValue != NULL){ //cValue
        printf("|- %s = %s\n", key->cValue->content, key->cValue->value);
        key->cValue = key->cValue->next;
    }
    if(cvHead != NULL){
        key->cValue = cvHead;
    }

}
