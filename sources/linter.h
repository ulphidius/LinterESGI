#ifndef LINTER_H_INCLUDED
#define LINTER_H_INCLUDED

#include "file.h"
#include "config.h"

void lintFile(ConfigKey *conf, CheckFile *list);

int choiceRule(char *string);

#endif // LINTER_H_INCLUDED
