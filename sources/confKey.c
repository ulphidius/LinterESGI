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
#include "confKey.h"


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

ConfigKey *loadAll(char *fp){
    ConfigKey* conf;
    ConfigKey* temp;
    int i = 0;
    int n = 0;

    temp = loadConfig(fp);
    if(temp == NULL){
        printf("Le fichier %s n'existe pas",fp);
        return NULL;
    }
    conf = getConfigKey("extends", temp);
    if(conf == NULL)
        return conf;
    while(conf->bValue != NULL){
        for(i = 0; i < n; i ++){
            if(conf->bValue == NULL)
                break;
            conf->bValue = conf->bValue->next;
        }
        if(conf->bValue == NULL)
            break;
        temp = loadConfig(conf->bValue->content);
        if(temp == NULL)
            break;
        conf = fusionKey(conf,temp);

        conf = getConfigKey("extends", conf);
    }
    return temp;
}
