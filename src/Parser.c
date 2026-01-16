#pragma once
#include "Parser.h"
#include "Ast.h"
#include "Scanner.h"
// Forward declarations
ASTNode *expression(Parser *p);
ASTNode *term(Parser *p);
ASTNode *factor(Parser *p);
ASTNode *primary(Parser *p);
// Helper to get the current token
Token peekP(Parser *p) { return p->tokens[p->current]; }

// Helper to consume and return the current token
Token advanceP(Parser *p) {
  if (peekP(p).type != TOK_EOF)
    p->current++;
  return p->tokens[p->current - 1];
}

ASTNode* primary(Parser* p) { 
    Token t = advanceP(p);
  if (t.type == TOK_NUMBER) {
      return ast_number(t.number);
  }

  if (t.type == TOK_LPAREN) {
    ASTNode *node = expression(p);
    advanceP(p);
    return node;
  }
  return NULL;
}

ASTNode *factor(Parser *p) { 
    if (peekP(p).type == TOK_MINUS) {
    advanceP(p);
      ASTNode *operand = factor(p);
    return ast_urnary(OP_NEGATE, operand);
  }
    return primary(p);

}

ASTNode* term(Parser* p) {
  ASTNode *node = factor(p);
  while (peekP(p).type == TOK_STAR || peekP(p).type == TOK_SLASH) {
    Token op = advanceP(p);
    ASTNode *right = factor(p);
    Operator operator = (op.type == TOK_STAR) ? OP_MUL : OP_DIV;
    node = ast_binary(operator, node, right);
  }
  return node;
}

ASTNode *expression(Parser *p) { 
    ASTNode *node = term(p);
  while (peekP(p).type == TOK_PLUS || peekP(p).type == TOK_MINUS) {
    TokenType op = advanceP(p).type;
    ASTNode *right = term(p);
    Operator operator = (op == TOK_PLUS) ? OP_ADD : OP_SUB;
    node = ast_binary(operator, node, right);
  }
  return node;
}

ASTNode* parse(Token* tokens, Parser* p) {
  p->tokens = tokens;
  p->current = 0;
  return expression(p);
}
