/*
	Dynamic Array Implementation to the Stack 
	using Growable strategy (Double the Capacity of the Array)
*/

#include<iostream>
using namespace std;
class Stack
{
	int top, capacity, * arr;
public:
	Stack()
	{
		top = -1;
		capacity = 1;
		arr = new int[capacity];
	}
	bool isFull()
	{
		return capacity == top + 1;
	}
	bool isEmpty()
	{
		return top == -1;
	}

	//Double the capacity of the Stack 
	void DoubleStack()
	{
		int* m = new int;
		capacity *= 2;
		if (arr)
		{
			m = (int*)realloc(arr, capacity * sizeof(int));
			if (m)
				arr = m;
		}
	}

	// push one Element to the Stack 
	void push(int data)
	{
		if (isFull())
			DoubleStack();
		arr[++top] = data;

	}

	// Push Number of Elements to the Stack 
	void pushn(int n)
	{
		int data;
		cout << "Enter " << n << " Elements to the Stack \n";
		while (n)
		{
			if (isFull())
				DoubleStack();
			cin >> data;
			arr[++top] = data;
			n--;
		}	
	}

	// pop and return poped Element from the Stack 
	int pop()
	{
		if (isEmpty())
		{
			cout << "Stack is Empty \n";
			return 0;
		}
		return arr[top--];
	}
	void showdata()
	{
		if (isEmpty())
		{
			cout << "Stack is Empty \n";
			return;
		}
		cout << endl;
		cout << "The Elements of the Stack \n";
		for (int i = top; i > -1; i--)
		{
			cout << arr[i] << "\n";
		}
		cout << endl;
	}
	void size()
	{
		cout << "Number of Elements of the Stack = " << top+1 << endl;
	}
};
int main()
{
	Stack s;
	s.push(5);
	s.showdata();
	s.pushn(4);
	s.showdata();
	s.size();
	cout << s.pop();
	s.size();
}