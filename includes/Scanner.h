#pragma once
#include "Ast.h"

typedef enum {
    TOK_EOF,
    TOK_NUMBER,
    TOK_PLUS,
    TOK_MINUS,
    TOK_STAR,
    TOK_SLASH,
    TOK_LPAREN,
    TOK_RPAREN
} TokenType;

typedef struct {
    TokenType type;
    double number;
}Token;

typedef struct {
    const char* src;
    size_t pos;
    Token current;
} Lexer;

void lexer_next(Lexer* l);

ASTNode* parse_expression(Lexer* l);
ASTNode* parse_term(Lexer* l);
ASTNode* parse_factor(Lexer* l);

//void scanTokens(Tokens* tokens, const char* input);
