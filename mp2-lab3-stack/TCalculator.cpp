
#include <iostream>
#include <string>
#include "TCalculator.h"

using namespace std;

bool TCalculator::CheckExpression()
{

	int size = expr.size();
	TStack<char> st1(size);

	for (int i = 0; i < size; i++)
	{
		if (expr[i] == '(')
			st1.Push('(');
		try
		{
			if (expr[i] == ')')
				st1.Pop();
		}
		catch (...)
		{
			cout << "')' more than '(' " << '\n';
			return 0;
		}
	}

	if (!st1.IsEmpty())
	{
		cout << "'(' more than ')' " << '\n';
		return 0;
	}
	cout << "The expression is correct" << '\n';
	return 1;
}

bool TCalculator::isOperator(char symbol)
{
	char operators[] = { '+', '-', '*', '/', '^' };
	int size = 5;

	for (int i = 0; i < size; i++)
		if (symbol == operators[i])
			return true;

	return false;	
}

int TCalculator::Priority(char op)
{
	switch (op)
	{
	case '(':
		return 0;
	case '+':
		return 1;
	case '-':
		return 1;
	case '*':
		return 2;
	case '/':
		return 2;
	case '^':
		return 3;
	}
}

void TCalculator::ToPostfix()
{
	string infix = '(' + expr + ')';
	postfix = "";

	st_char.Clear();

	for (int i = 0; i < infix.size(); i++)
	{
		if (infix[i] == ' ')
			continue;

		if (infix[i] <= '9' && infix[i] >= '0')
		{
			postfix += infix[i];
			postfix += ' ';
			continue;
		}

		if (infix[i] == '(')
		{
			st_char.Push('(');
			continue;
		}			

		if (infix[i] == ')')
		{
			while (st_char.Top() != '(')
			{
				try
				{
					postfix += st_char.Pop();
					postfix += " ";
				}
				catch (string ex)
				{
					cout << ex;
				}
			}

			try
			{
				st_char.Pop();
			}
			catch (string ex)
			{
				cout << ex;
			}
			continue;
		}

		if (isOperator(infix[i]))
		{
			while (Priority(st_char.Top()) > Priority(infix[i]))
			{
				try
				{
					postfix += st_char.Pop();
					postfix += " ";
				}
				catch (string ex)
				{
					cout << ex;
				}
			}

			try
			{
				st_char.Push(infix[i]);
			}
			catch (string ex)
			{
				cout << ex;
			}
		}
	}
}

double TCalculator::Calc()
{
	double a, b;
	
	for (int i = 0; i < postfix.size(); i++)
	{
		if (postfix[i] <= '9' && postfix[i] >= '0')
		{
			st_double.Push(stod(&postfix[i]));
			continue;
		}

		if (postfix[i] != ' ')
		{
			b = st_double.Pop();
			a = st_double.Pop();

			switch (postfix[i])
			{
			case '+':
				st_double.Push(a + b);
				break;
			case '-':
				st_double.Push(a - b);
				break;
			case '*':
				st_double.Push(a * b);
				break;
			case '/':
				st_double.Push(a / b);
				break;
				}
			}
	}
	
	return st_double.Pop();
}


//���������: ( = 0, + = - = 1, *, ^
	//1. ����� ��������� �������� (�), ���������� � �� ����������
	//� ���, ������� ������ �� ������� ����� (b):
	//	1.1 ���� (a <= b) - ���������� b � ������
	//	1.2 ���� a>b - �������� a � ����
	//	1.3 '(' ������ ������������ � ����, ��� ��������
	//	1.4 ) ����������� ��� �������� �� ����� �� (
	//  (� ����� � ���� ��� ��������� ����� ����������� � () )
	//2. ����� ������ �������������� � ������
	//+ ( + * ( - ) ) * ^ -
	//2 + (1+2*(4 - 2))*4^2 - 5
	//2 1 2 4 2 - * + 4 2 ^ +
	//
