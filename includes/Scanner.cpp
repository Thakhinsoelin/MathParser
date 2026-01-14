#include "Scanner.h"
#include <string.h>
#include <stdlib.h>

//int start = 0;
//int current = 0;

/*void scanTokens(Tokens* tokens, const char* input)
{
	int inputLength = strlen(input);
	for (int i = 0; i < inputLength; ++i) {
		
	}
}*/

ASTNode* parse_factor(Lexer* l)
{
	Token t = l->current;
	switch (t.type)
	{
	case TOK_NUMBER:

	default:
		break;
	}
	return nullptr;
}
