#include "Ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ASTNode* ast_number(double value)
{
	ASTNode* node = malloc(sizeof(ASTNode));
	node->kind = NUMBER;
	node->number = value;
	return node;
}

ASTNode* ast_binary(Operator op, ASTNode* left, ASTNode* right)
{
	ASTNode* node = malloc(sizeof(ASTNode));
	node->kind = BINARY;
	node->binary.op = op;
	node->binary.left = left;
	node->binary.right = right;
	return node;

}

ASTNode* ast_urnary(Operator op, ASTNode* operand)
{
	ASTNode* node = malloc(sizeof(ASTNode));
	node->kind = URNARY;
	node->urnary.op = op;
	node->urnary.operand = operand;
	return node;
}

double evaluate(ASTNode* node)
{
	switch (node->kind)
	{
	case NUMBER:
		return node->number;
	case BINARY:
	{
		double lhs = evaluate(node->binary.left);
		double rhs = evaluate(node->binary.right);
		switch (node->binary.op)
		{
		case OP_ADD:
			return lhs + rhs;
		case OP_SUB:
			return lhs - rhs;
		case OP_MUL:
			return lhs * rhs;
		case OP_DIV:
			return lhs / rhs;
		default:
			return 0;
		}
	}
	case URNARY:
		if (node->urnary.op == OP_NEGATE)
		{
			double v = evaluate(node->urnary.operand);
			return -v;
		}
	default:
		return 0;
	}
}


