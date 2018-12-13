#include "arrayBracketEol.h"
#include "indent.h"
#include "startComment.h"
#include "trailingSpace.h"
#include "numberLinesChar.h"
#include "commat.h"
#include "operator.h"

int main(){

	
	processOperators("../resources/testFileOperator");
	functionTestCommat("../resources/testFileOperator");
	checkLinesNumbers("../resources/testFileOperator", atoi("30"));
	checkCharactersNumbers("../resources/testFileOperator", atoi("10"));
	functionTestTrailingSpace("../resources/testFileOperator");
	functionStartComment("../resources/testFileOperator");
	functionTestIndent("../resources/testFileOperator");
	functionTestBracket("../resources/testFileOperator");

	return 0;
}
