#ifndef EXPRESSION_EVAL_H
#define EXPRESSION_EVAL_H

#include <stack>
#include <string>
using namespace std;

int precedence(char op);
int applyOp(int a, int b, char op);
extern int evaluate(string tokens);

#endif
