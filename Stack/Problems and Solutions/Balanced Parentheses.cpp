#include<iostream>
#include<stack>
#include<string>
using namespace std;
bool arepair(char open, char close)
{
	if (open == '(' && close == ')')
		return true;
	if (open == '{' && close == '}')
		return true;
	if (open == '[' && close == ']')
		return true;
	return false;
}
bool areBalanced(string exp)
{
	stack<char>s;
	for (int i = 0; i < exp.length(); i++)
	{
		if (exp[i] == '(' || exp[i] == ')' || exp[i] == '{' || exp[i] == '}' || exp[i] == '[' || exp[i] == ']')
		{
			if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
			{
				s.push(exp[i]);
			}
			else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
			{
				if (s.empty() || !arepair(s.top(), exp[i]))
					return false;
				else
					s.pop();
			}
		}
	}
	return s.empty() ? true : false;
}
int main()
{
	string exp;
	cout << "Enter an Expression : ";
	cin >>  exp;
	if (areBalanced(exp))
		cout << "Balanced \n";
	else
		cout << "not Balanced\n";
}