#include "Scanner.h"
#include "vec.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

char advance(Pointer* pointer, const char* source) { 
	pointer->current++;
	return source[pointer->current - 1];
}

bool isAtEnd(Pointer* pointer, const char* string) {
  return string[pointer->current] == '\0';
}


char peekNext(Pointer* pointer, const char* source) {
  if (pointer->current + 1 >= strlen(source))
    return '\0';
  
  return source[pointer->current + 1];
}


bool match(Pointer* pointer, char expected, const char* source) {
  if (isAtEnd(pointer, source))
    return false;
  if (source[pointer->current] != expected)
    return false;

  pointer->current++;
  return true;
}

bool isDigit(char c) { return c >= '0' && c <= '9'; }

Pointer *createPointer() { 
	Pointer *pointer = malloc(sizeof(Pointer));
  pointer->start = 0;
  pointer->current = 0;
  return pointer;
}
char *turnToString(TokenType type) {
  switch (type) {
  case TOK_EOF:
    return "TOK_EOF";
  case TOK_NUMBER:
    return "TOK_NUMBER";
  case TOK_PLUS:
    return "TOK_PLUS";
  case TOK_MINUS:
    return "TOK_MINUS";
  case TOK_STAR:
    return "TOK_STAR";
  case TOK_SLASH:
    return "TOK_SLASH";
  case TOK_LPAREN:
    return "TOK_LPAREN";
  case TOK_RPAREN:
    return "TOK_RPAREN";
  default:
    break;
  }
}
char* substring(const char* source, int start, int end) {
  int src_length = strlen(source);
  int length = end - start;
  char *toR = malloc(length + 1);
  strncpy(toR, source + start, length);
  toR[length] = '\0';
  return toR;

}

void addToken(Token** Tokens, TokenType type,  const char* source) { 
  Token temp = {.type = type};
  
  vector_add(Tokens, Token, temp);
}


void addTokenNumber(Token** Tokens, TokenType type, Pointer* pointer, const char* source) {
  char *text = substring(source, pointer->start, pointer->current);
  Token temp = {.type = type, .number = strtod(text, NULL)};
  
  vector_add(Tokens, Token, temp);
}

char peek(Pointer* pointer, const char* source) {
  if (isAtEnd(pointer, source))
    return '\0';
  return source[pointer->current];
}

void number(Token** tokens, Pointer* pointer, const char* source) {
  while (isDigit(peek(pointer, source)))
    advance(pointer, source);

  if (peek(pointer, source) == '.' && isDigit(peekNext(pointer, source))) {
    advance(pointer, source);

    while (isDigit(peek(pointer, source)))
      advance(pointer, source);
  }

  addTokenNumber(tokens, TOK_NUMBER, pointer, source);
}

void ScanToken(Token **result, Pointer * pointer, const char *input) {
  char c = advance(pointer, input);
  switch (c) {
  case '+': addToken(result, TOK_PLUS, input); break;
  case '-': addToken(result, TOK_MINUS, input); break;
  case '*': addToken(result, TOK_STAR, input); break;
  case '/': addToken(result, TOK_SLASH, input); break;
  case '(': addToken(result, TOK_LPAREN, input); break;
  case ')': addToken(result, TOK_RPAREN, input); break;
  case ' ':
    break;
  case '\r':
    break;
  case '\t':
    break;
  case '\n':
    break;
  default:
    if (isDigit(c)) {
      number(result, pointer, input);
    } else {
      printf("Unexpeced\n");
    }
    break;
  }
}

void scanTokens( Token** tokens, Pointer *pointer, const char *input) {
	int inputLength = strlen(input);
  while (!isAtEnd(pointer, input)) {
          pointer->start = pointer->current;
    ScanToken(tokens, pointer, input);
  }
  addToken(tokens, TOK_EOF, input);
}
