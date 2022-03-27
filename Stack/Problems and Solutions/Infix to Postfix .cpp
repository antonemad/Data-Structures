#include<iostream>
#include<stack>
#include<string>
using namespace std;
int prec(char c)
{
	if (c == '^')
		return 3;
	else if (c == '*' || c == '/')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}
void infixToPostfix(string s)
{
	stack<char>st;
	string ns;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')
			ns += s[i];
		else if (s[i] == '(')
			st.push(s[i]);
		else if (s[i] == ')')
		{
			while (st.top()!='('&&!st.empty())
			{
				ns += st.top();
				st.pop();
			}
			if (st.top() == '(')
				st.pop();
		}
		else
		{
			while (!st.empty() && prec(s[i]) <= prec(st.top()))
			{
				ns += st.top();
				st.pop();
			}
			st.push(s[i]);
		}
	}

	while (!st.empty())
	{
		ns += st.top();
		st.pop();
	}
	cout <<"The Postfix Expression : "<< ns << endl;
}
int main()
{
	string exp;
	cout << "Enter the Infix Expression : ";
	cin >> exp;
	infixToPostfix(exp);
}