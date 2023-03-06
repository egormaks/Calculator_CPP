#ifndef EXPRESSION_EVAL_H
#define EXPRESSION_EVAL_H

#include <stack>
using namespace std;

int precedence(char op);
int applyOp(int a, int b, char op);
int evaluate(string tokens);

#endif
