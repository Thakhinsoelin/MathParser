#include "Mparser.h"
#include "Ast.h"
#include "vec.h"
#include "Parser.h"
#include "Scanner.h"

double calculate(const char* input) {
  Pointer *pointer = createPointer();
    Token* tokens = vector_create();
    scanTokens(&tokens, pointer, input);
    vec_size_t size = vector_size(tokens);
    
    Parser parser;
    ASTNode *test = parse(tokens, &parser); 
    double answer = evaluate(test);
    return answer;
}