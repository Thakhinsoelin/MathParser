#include <stdio.h>
#include "Ast.h"
#include "vec.h"
#include "Scanner.h"

int main(void) {
    Tokens* tokens = vector_create();
    scanTokens(tokens, "-5 * (3 + 4)");
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