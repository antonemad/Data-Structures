/*
	Implementation of the Stackc using Linked List 
*/
#include<iostream>
using namespace std;
struct node
{
	int data;
	node* next;
};
class stack
{
	node* top;
public:
	stack():top(nullptr){}

	/* Bckward Linked List */
	void push(int n)
	{
		int data;
		cout << "Enter the Data for " << n << " Elements \n";
		for (int i = 0; i < n; i++)
		{
			cin >> data;
			cout << "Element " << i + 1 << " : ";
			node* newnode = new node;
			newnode->data = data;
			newnode->next = top;
			top = newnode;
		}
	}
	bool isEmpty()
	{
		return top == nullptr;
	}
	void pop()
	{
		if (isEmpty())
		{
			cout << "Stack is Empty \n";
			return;
		}
		node* temp = top;
		top = top->next;
		delete temp;
	}
	void showdata()
	{
		node* temp = top;
		cout << "The Elements of the stack \n";
		while (temp)
		{
			cout << temp->data << endl;
			temp = temp->next;
		}
		cout << endl;
	}
};

int main()
{

}