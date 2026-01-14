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


void scanTokens(Token* tokens, const char* input);
