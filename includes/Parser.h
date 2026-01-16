#pragma once
#include "Ast.h"
#include <stdint.h>
#include "Scanner.h"

typedef struct {
  Token *tokens;
  int current;
}Parser;

ASTNode* parse(Token** tokens, Parser* p);
