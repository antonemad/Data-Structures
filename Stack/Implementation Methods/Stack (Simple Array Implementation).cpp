#include<iostream>
using namespace std;
class Stack
{
	int top, capacity, * arr;
public:
	Stack(int n)
	{
		capacity = n;
		top = -1;
		arr = new int[capacity];
	}
	bool isFull()
	{
		return capacity == (top + 1);
	}
	bool isEmpty()
	{
		return top == -1;
	}

	/* Push one Element to the Stack */
	void pushE(int data)
	{
		if (isFull())
		{
			cout << "Stack is Full \n";
			return;
		}
		arr[++top] = data;
	}
	/* Push Elements to the Stack until it is Full */
	void pushF()
	{
		if (isFull())
		{
			cout << "Stack is Full \n";
			return;
		}
		int data;
		cout << "Enter " << capacity - top - 1 << " Elements to the Stack \n";
		while (capacity > (top + 1))
		{
			cin >> data;
			arr[++top] = data;
		}
	}
	/* pop Element from the Stack and return the poped Element */
	int pop()
	{
		if (isEmpty())
		{
			cout << "Stack is Empty \n";
			return 0;
		}
		return arr[top--];
	}

	/* Print the Element of the Stack */
	
	void showdata()
	{
		if (isEmpty())
		{
			cout << "Stack is Empty \n";
			return;
		}
		cout << endl;
		for (int i = top; i > -1; i--)
		{
			cout << arr[i] << endl;
		}
		cout << endl;
	}
};
int main()
{
	Stack s(5);
	s.pushE(5);
	s.pushF();
	s.showdata();
}