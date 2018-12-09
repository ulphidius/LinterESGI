#ifndef LINTER_H_INCLUDED
#define LINTER_H_INCLUDED

#include "file.h"
#include "config.h"

#include "commat.h"
#include "numberLinesChar.h"
#include "trailingSpace.h"
#include "startComment.h"
#include "indent.h"
#include "operator.h"
#include "arrayBracketEol.h"

void lintFile(ConfigKey *conf, CheckFile *list);

int choiceRule(char *string);

#endif // LINTER_H_INCLUDED
