#pragma once

#include <iostream>
#include  <string>
#include "TStack.h"

using namespace std;

class TCalculator
{
	string expr;
	string postfix;
	TStack<char> st_char;
	TStack<double> st_double;

public:
	TCalculator(string _expr = "") : expr(_expr) {}

	void SetExpr(string _expr) { expr = _expr; }
	
	string GetPostfix() { return postfix; }

	bool CheckExpression(); //�������� ������������

	int Priority(char op); //��������� ��������

	void ToPostfix();

	bool isOperator(char symbol);
	
	double Calc();
};
