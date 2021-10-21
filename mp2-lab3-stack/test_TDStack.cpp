#include <iostream>
#include "TDStack.h"
#include <string>

#define cout std::cout
#define string std::string

void main()
{
	TDStack<int> mas(10);
	
	setlocale(LC_ALL, "");

	try
	{
		for (int i = 0; i < 5; i++)
			mas.St1_Push(i);
	}
	catch (...)
	{
		cout << '\n' << "���� �����" << '\n';
		return;
	}

	try
	{
		for (int i = 0; i < 5; i++)
			mas.St2_Push(2*i);
	}
	catch (...)
	{
		cout << '\n' << "���� �����" << '\n';
		return;
	}
	

	if (mas.IsFull())
		cout << '\n' << "������ ������" << '\n';
	else
		cout << '\n' << "������ �� ������" << '\n';


	try
	{
		cout << '\n' << "���� �1" << '\n';
		for (int i = 0; i < 5; i++)
			cout << mas.St1_Pop() << ' ';
		cout << '\n';
	}
	catch (...)
	{
		cout << '\n' << "���� �1 ����" << '\n';
		return;
	}

	try
	{
		cout << '\n' << "���� �2" << '\n';
		for (int i = 0; i < 5; i++)
			cout << mas.St2_Pop() << ' ';
		cout << '\n';
	}
	catch (...)
	{
		cout << '\n' << "���� �2 ����" << '\n';
		return;
	}

	if (mas.St1_IsEmpty())
		cout << '\n' << "���� �1 ����" << '\n';

	if (mas.St2_IsEmpty())
		cout << '\n' << "���� �2 ����" << '\n';
}