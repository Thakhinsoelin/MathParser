#include <stdio.h>
#include "Ast.h"
#include "vec.h"
#include "Scanner.h"

int main(void) {
  Pointer *pointer = createPointer();
    Token* tokens = vector_create();
    scanTokens(&tokens, pointer, "-5 unknown * (3 + 4)");
    vec_size_t size = vector_size(tokens);
    printf("%li\n", size);
    for (vec_size_t i = 0; i < size; i++) {
      TokenType type = tokens[i].type;
      printf("Token %d: Type %s\n", i, turnToString(type));
    }
    return 0;
    ASTNode* test =
        ast_binary(OP_MUL,
            ast_binary(OP_ADD,
                ast_number(3),
                ast_number(4)
            ), 
            ast_urnary(OP_NEGATE,
                ast_number(5))
            );
    double answer = evaluate(test);
    printf("The answer is: %f\n", answer);
}