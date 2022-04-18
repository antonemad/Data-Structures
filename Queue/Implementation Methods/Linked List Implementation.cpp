#include<iostream>
using namespace std;
struct node
{
	int data;
	node* next;
};
class Queue
{
	node* front, *rear;
public:
	Queue():front(nullptr),rear(nullptr)
	{}
	bool isEmpty()
	{
		return front == nullptr;
	}
	void EnQueue(int data)
	{
		node* newnode = new node;
		if (!newnode)
		{
			cout << "Memory Error !!\n";
			return;
		}
		newnode->data = data;
		newnode->next = nullptr;
		if (!front)
		{
			front = rear = newnode;
		}
		else
		{
			rear->next = newnode;
			rear = newnode;
		}
	}
	void DeQueue()
	{
		if (isEmpty())
		{
			cout << "Queue is Empty \n";
			return;
		}
		node* temp = front;
		front = front->next;
		delete temp;
	}
	void print()
	{
		if (isEmpty())
		{
			cout << "Queue is Empty \n";
			return;
		}
		node* temp = front;
		while (temp)
		{
			cout << temp->data << "\t";
			temp = temp->next;
		}
		cout << endl;
	}
};
int main()
{
	Queue Q;
	Q.EnQueue(5);
	Q.EnQueue(6);
	Q.EnQueue(7);
	Q.print();
	Q.DeQueue();
	Q.print();
}