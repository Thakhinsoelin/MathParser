#pragma once

typedef enum {
	NUMBER,
	BINARY,
	URNARY
}ASTKind;

typedef enum {
	OP_ADD,
	OP_SUB,
	OP_MUL,
	OP_DIV,
	OP_NEGATE // for urnary
}Operator;


typedef struct {
	ASTKind kind;

	union {
		double number;

		struct {
			Operator op;
			struct ASTNode* left;
			struct ASTNode* right;
		}binary;

		struct {
			Operator op;
			struct ASTNode* operand;
		}urnary;
	};
}ASTNode;

ASTNode* ast_number(double value);
ASTNode* ast_binary(Operator op, ASTNode* left, ASTNode* right);
ASTNode* ast_urnary(Operator op, ASTNode* operand);

double evaluate(ASTNode* node);