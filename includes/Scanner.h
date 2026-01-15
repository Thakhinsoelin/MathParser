#pragma once
#define TO_STR(x) #x
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

char *turnToString(TokenType type);

typedef struct {
    TokenType type;
    double number;
}Token;

typedef struct{
  int start;
  int current;
}Pointer;

Pointer *createPointer();

void scanTokens(Token* tokens, Pointer* pointer, const char* input);
