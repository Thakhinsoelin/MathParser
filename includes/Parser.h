#pragma once
#include "Ast.h"
#include <stdint.h>
#include "Scanner.h"

typedef struct {
    const char* src;
    size_t pos;
    Token current;
} Lexer;

void lexer_next(Lexer* l);

ASTNode* parse_expression(Lexer* l);
ASTNode* parse_term(Lexer* l);
ASTNode* parse_factor(Lexer* l);

