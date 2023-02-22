#include <iostream>
#include <windows.h>
#include <stack>
#include <string>

using namespace std;

int priority(char a)
{
	if (a == '^')
		return 3;
	if (a == '*' || a == '/')
		return 2;
	if (a == '+' || a == '-')
		return 1;
	return 0;
}

string makePostfix(string function)
{
	string postfix = "";
	stack <char> s;
	for (int i = 0; i < function.length(); i++)
	{
		if (function[i] != '+' && function[i] != '-' && function[i] != '*' && function[i] != '/' && function[i] != '(' && function[i] != ')' && function[i] != '^')
			postfix += function[i];
		else if (function[i] == '(')
			s.push('(');
		else if (function[i] == ')')
		{
			while (s.top() != '(')
			{
				postfix += s.top();
				s.pop();
			}
			s.pop();
		}
		else
		{
			while (!s.empty() && priority(function[i]) <= priority(s.top()))
			{
				postfix += s.top();
				s.pop();
			}
			s.push(function[i]);
		}
	}
	while (!s.empty())
	{
		postfix += s.top();
		s.pop();
	}
	return postfix;
}

int main()
{
	setlocale(LC_ALL, "RU");
	string postfix;
	string function = "";
	while (true)
	{
		cout << "Введите выражение (Чтобы выйти введите \"exit\"): ";
		cin >> function;
		if (function != "exit")
		{
			postfix = makePostfix(function);
			cout << "Выражение в постфиксном виде: " << postfix << endl;
		}
		else
			break;
	}
}