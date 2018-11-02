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

char *strtok_r(char * n , const char * c , char ** ce){
return NULL;}


/**
 * Use as FILE* .lconf for test
 **/
char* myInput(int choice){
    char* val;
    val = malloc(sizeof(char) * 200);
        switch(choice){
            case 1 :
                sprintf(val, "=rules\n- rule4 = on\n- rule5 = off\n- rule6 = 50\n\n=excludedFiles\n- bonjour.c\n- test.c\n\n=recursive\nfalse");
                break;

            default :
                sprintf(val, "=extends\nmain.lconf\n\n=rules\n- rule1 = on\n- rule2 = off\n- rule3 = 50\n\n=excludedFiles\n- bonjour.c\n- test.c\n\n=recursive\ntrue");
                break;
    }
    return val;
}

/**
 * Get the size of the file for allocation
 **/
int getFileSize(FILE *fp){
    long size;
    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    return (int)size;
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
 * get a specific configuration parameter
 **/
ConfigKey* getConfiguration(char* ctext){
    char *key;
    char *param;
    char *val;
	int type;
	ConfigKey *head;
	ConfigKey *kl;
	head = NULL;
	while((key = getKey(&ctext)) != NULL){
    	//printf("\nclé : %s\n", key);
    	if(head == NULL){
	        kl = initConfigKey(key);
	        if(getValue(ctext, kl) == 1){
        	    return NULL;
        	}
		}else{
	        kl->next = initConfigKey(key);
	        if(getValue(ctext, kl->next) == 1){
        	    return NULL;
        	}
		}
		if(head == NULL){
		    head = kl;
		    head->head = head;
		}else{
		    kl->next->head = head;
	        kl = kl->next;
		}
    	free(key);
	}
    return head;
}

/**
 * get a specific configuration parameter
 **/
ConfigKey* getConfigKey(char* name,ConfigKey* conf){
    ConfigKey *head;
    ConfigKey *found;

    head = conf;
    while(conf != NULL){
        if(strcmp(conf->name, name) == 0){
            found = conf;
            conf = head;
            return found;
        }
        conf = conf->next;
    }
    conf = head;
    return NULL;
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
 * Check for the given name if a key exist, a return it (or the value if it's a cValue).
 **/
char* asConfigKey(char* name, ConfigKey* conf, int type){
    ConfigBasicValue *bvHead;
    ConfigBasicValue *bvFound;
    ConfigValue *vHead;
    ConfigValue *vFound;
    ConfigContentValue *cvHead;
    ConfigContentValue *cvFound;

    conf = conf->head;
    switch (type){

        case BVALUE :
            bvHead = conf->bValue;
            while(conf->bValue != NULL){
                if(strcmp(conf->bValue->content, name) == 0){
                    bvFound = conf->bValue;
                    conf->bValue = bvHead;
                    return bvFound->content;
                }
                conf->bValue = conf->bValue->next;
            }
            conf->bValue = bvHead;
            break;

        case VALUE :
            vHead = conf->value;
            while(conf->value != NULL){
                if(strcmp(conf->value->content, name) == 0){
                    vFound = conf->value;
                    conf->value = vHead;
                    return conf->value->content;
                }
                conf->value = conf->value->next;
            }
            conf->value = vHead;
            break;

        case CVALUE :
            cvHead = conf->cValue;
            while(conf->cValue != NULL){
                if(strcmp(conf->cValue->content, name) == 0){
                    cvFound = conf->cValue;
                    conf->cValue = cvHead;
                    return conf->cValue->value;
                }
                conf->cValue = conf->cValue->next;
            }
            conf->cValue = cvHead;
            break;

        default :
            bvHead = conf->bValue;
            while(conf->bValue != NULL){
                if(strcmp(conf->bValue->content, name) == 0){
                    bvFound = conf->bValue;
                    conf->bValue = bvHead;
                    return bvFound->content;
                }
                conf->bValue = conf->bValue->next;
            }
            conf->bValue = bvHead;
            vHead = conf->value;
            while(conf->value != NULL){
                if(strcmp(conf->value->content, name) == 0){
                    vFound = conf->value;
                    conf->value = vHead;
                    return conf->value->content;
                }
                conf->value = conf->value->next;
            }
            conf->value = vHead;
            cvHead = conf->cValue;
            while(conf->cValue != NULL){
                if(strcmp(conf->cValue->content, name) == 0){
                    cvFound = conf->cValue;
                    conf->cValue = cvHead;
                    return conf->cValue->value;
                }
                conf->cValue = conf->cValue->next;
            }
            conf->cValue = cvHead;
            break;

    }

    return NULL;
}

/**
 *  Check if the config list lready already has a named key
 **/
ConfigKey* asConfigKeyName(char* name, ConfigKey* conf){
    ConfigKey* head = conf;

    conf = conf->head;
    while(conf != NULL){
        if(strcmp(conf->name, name) == 0){
            return conf;
        }
        conf = conf->next;
    }

    conf = head;
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
 * Add a conf2 key to a first one, by addition and without overwrite
 **/
int fusionKey(ConfigKey* conf,ConfigKey* conf2){
    ConfigKey *headConf;
    ConfigKey *headConf2;
    ConfigKey *current;

    conf = conf->head;
    conf2 = conf2->head;
    headConf = conf;
    headConf2 = conf2;
    while(conf2 != NULL){
        current = asConfigKeyName(conf2->name, conf); //   ex : (rules, extends)    -> NULL
        if(current != NULL){                          //        (rules, rules)      -> conf
            if(conf2->bValue != NULL){
                addBValueKey(current, conf2);
            }
            if(conf2->value != NULL){
                addValueKey(current, conf2);
            }
            if(conf2->cValue != NULL){
                addCValueKey(current, conf2);

            }
            current = NULL;
        }else{
            while(conf->next != NULL){
                conf = conf->next;
            }
            current = copyKey(conf2);
            conf->next = current;
            current = NULL;
        }
        conf = headConf;
        conf2 = conf2->next;
    }
    conf2 = headConf2;
    conf = headConf;
    return 1;
}

/**
 * Duplication of a ConfigKey (for fusion)
 **/
ConfigKey* copyKey(ConfigKey* conf){
    if(conf == NULL){
        return NULL;
    }
    ConfigKey* cpy;
    ConfigBasicValue *bvHead;
    ConfigBasicValue *bvFound;
    ConfigValue *vHead;
    ConfigValue *vFound;
    ConfigContentValue *cvHead;
    ConfigContentValue *cvFound;

    cpy = initConfigKey(conf->name);
    bvHead = conf->bValue;
    while(conf->bValue != NULL){
        if(cpy->bValue == NULL){
		    cpy->bValue = initConfigBasicValue(conf->bValue->content);
		    cpy->bValue->head = cpy->bValue;
		}else{
		    cpy->bValue->next = initConfigBasicValue(conf->bValue->content);
		    cpy->bValue->next->head = cpy->bValue->head;
            cpy->bValue = cpy->bValue->next;
		}
        conf->bValue = conf->bValue->next;
    }
    conf->bValue = bvHead;

    vHead = conf->value;
    while(conf->value != NULL){
        if(cpy->value == NULL){
		    cpy->value = initConfigValue(conf->value->content);
		    cpy->value->head = cpy->value;
		}else{
		    cpy->value->next = initConfigValue(conf->value->content);
		    cpy->value->next->head = cpy->value->head;
            cpy->value = cpy->value->next;
		}
        conf->value = conf->value->next;
    }
    conf->value = vHead;

    cvHead = conf->cValue;
    while(conf->cValue != NULL){
        if(cpy->cValue == NULL){
		    cpy->cValue = initConfigContentValue(conf->cValue->content, conf->cValue->value);
		    cpy->cValue->head = cpy->cValue;
		}else{
		    cpy->cValue->next = initConfigContentValue(conf->cValue->content, conf->cValue->value);
		    cpy->cValue->next->head = cpy->cValue->head;
            cpy->cValue = cpy->cValue->next;
		}
        conf->cValue = conf->cValue->next;
    }
    conf->cValue = cvHead;

    return cpy;
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
 * Free a config key
 **/
void freeConfigKey(ConfigKey* key){
    if(key != NULL){
        free(key->name);
        if(key->bValue != NULL){
            freeConfigBasicValue(key->bValue);
        }
        if(key->value != NULL){
            freeConfigValue(key->value);
        }

        if(key->cValue != NULL){
            freeConfigContentValue(key->cValue);
        }

        free(key);
    }
}

/**
 * Free the whole config
 **/
void freeConfig(ConfigKey* key){
    if(key->next != NULL){
        freeConfig(key->next);
    }
    //printf("\nfreeing %8s :",key->name);
    if(key->name != NULL){
        free(key->name);
    }
    if(key->bValue != NULL){
        freeConfigBasicValue(key->bValue->head);
    }
    if(key->value != NULL){
        freeConfigValue(key->value->head);
    }

    if(key->cValue != NULL){
        freeConfigContentValue(key->cValue->head);
    }
    if(key != key->head)
        free(key);
    //printf(": done !\n");
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
 * Initialisation of a classic configuration key
 **/
ConfigKey* initConfigKey(char* nameKey){
	ConfigKey* ll;

	ll = malloc(sizeof(ConfigKey));
	ll->name = malloc(sizeof(char) * (strlen(nameKey) + 2));
	sprintf(ll->name, "%s", nameKey);
    ll->bValue = NULL;
    ll->value = NULL;
    ll->cValue = NULL;
    ll->next = NULL;
    ll->head = NULL;

    return ll;
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


ConfigKey *loadConfig(char *fp){
    ConfigKey* conf;
    char *ctext;
    char *text;
    FILE *configFile;
    //
    if(fp[0] == '\n'){ //debug
        text = myInput(0);
        ctext = malloc(sizeof(char) * (strlen(text) + 3));
    	sprintf(ctext, "\n\n%s", text);
	    conf = getConfiguration(ctext);
	    return conf;
    }
    if(fp[0] == '\t'){ //debug
        text = myInput(1);
        ctext = malloc(sizeof(char) * (strlen(text) + 3));
    	sprintf(ctext, "\n\n%s", text);
	    conf = getConfiguration(ctext);
	    return conf;
    }
    //
    configFile = fopen(fp, "r");
    text = malloc(sizeof(char) * (getFileSize(configFile) + 1));
    fgets(text, strlen(text) ,configFile);
    ctext = malloc(sizeof(char) * (strlen(text) + 3));
	sprintf(ctext, "\n\n%s", text);
	conf = getConfiguration(ctext);
	fclose(configFile);
	free(ctext);
	free(text);

	return conf;
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
    while(key->bValue != NULL){ //bValue
        printf("|%s\n", key->bValue->content);
        key->bValue = key->bValue->next;
    }
    if(bvHead != NULL){
        key->bValue = bvHead;
    }
    vHead = key->value;
    while(key->value != NULL){ //value
        printf("|- %s\n", key->value->content);
        key->value = key->value->next;
    }
    if(vHead != NULL){
        key->value = vHead;
    }
    cvHead = key->cValue;
    while(key->cValue != NULL){ //cValue
        printf("|- %s = %s\n", key->cValue->content, key->cValue->value);
        key->cValue = key->cValue->next;
    }
    if(cvHead != NULL){
        key->cValue = cvHead;
    }

}
