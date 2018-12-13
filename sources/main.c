#include "arrayBracketEol.h"
#include "indent.h"
#include "startComment.h"
#include "trailingSpace.h"
#include "numberLinesChar.h"
#include "commat.h"
#include "operator.h"

int main(){

	char* name = "../resources/testFileOperator";
	processOperators(name);
	functionTestCommat(name);
	checkLinesNumbers(name, atoi("30"));
	checkCharactersNumbers(name, atoi("10"));
	functionTestTrailingSpace(name);
	functionStartComment(name);
	functionTestIndent(name);
	functionTestBracket(name);

	return 0;
}
