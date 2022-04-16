/* Implementation of a Doubly Linked List */

#include<iostream>
using namespace std;

struct node
{
	int data;
	node* prev;
	node* next;
};

class DLinkedList
{
	node* first, * last;
	int count;
public:
	DLinkedList():first(nullptr),last(nullptr),count(0)
	{}
	void create(int n)
	{
		node* newnode = new node;
		cout << "Enter the Data for " << n << " Nodes\n";
		for (int i = 0; i < n; i++)
		{
			int d;
			cout << "Node " << i + 1 << " : ";
			cin >> d;
			newnode->data = d;
			newnode->next = nullptr;
			if (!first)
			{
				first = last = newnode;
				newnode->prev = nullptr;
			}
			else
			{
				last->next = newnode;
				newnode->prev = last;
				last = newnode;
				last->next = nullptr;
			}
			count++;
		}
	}

	/* Insert a Node to a Doubly Linked List */

	void insert(int position, int data)
	{
		if (position<1 || position>count + 1)
		{
			cout << "Error Position !!\n";
			return;
		}
		/* initial variables */
		node* newnode = new node;
		node* temp = first;
		int k = 1;

		if (!newnode)
		{
			cout << "Memory Error !! \n";
			return;
		}
		newnode->data = data;

		if (position == 1)
		{
			newnode->next = first;
			newnode->prev = nullptr;
			if (first)
			{
				first->prev = newnode;
			}
			first = newnode;

			if (!last)
			{
				last = first;
			}
			count++;
			return;
		}

		while (k < position - 1 && temp)
		{
			k++;
			temp = temp->next;
		}

		if (temp)
		{
			newnode->next = temp->next;
			newnode->prev = temp;

			if (temp->next)
				temp->next->prev = newnode;
			if (!newnode->next)
				last = newnode;

			temp->next = newnode;
			count++;
		}
	}

	/* Deleting node from the List */

	void Deleten(int position)
	{
		if (!first)
		{
			cout << "List is Empty \n";
			return;
		}
		if (position<1 || position>count)
		{
			cout << "Error Position \n";
			return;
		}

		/* initial variables */
		node* temp = first;
		int k = 1;

		if (position == 1)
		{
			if (!first->next)
			{
				first = nullptr;
				delete temp;
				count--;
				return;
			}

			first = first->next;
			first->prev = nullptr;
			delete temp;
			count--;
			return;
		}

		while (k < position && temp)
		{
			k++;
			temp = temp->next;
		}
		if (temp)
		{
			temp->prev->next = temp->next;

			if (temp->next)
				temp->next->prev = temp->prev;
			else
				last = temp->prev; 

			delete temp;
			count--;
		}
	}

	/* Display Data of the List */

	void display()
	{
		if (!first)
		{
			cout << "List is Empty \n";
			return;
		}
		node* temp = first;

		cout << "The Content of the Nodes \n";
		while (temp)
		{
			cout << temp->data << "\t";
			temp = temp->next;
		}
		cout << endl;
	}

	/* Print Data Backward */

	void displayB()
	{
		if (!first)
		{
			cout << "List is Empty \n";
			return;
		}
		node* temp = last;

		cout << "The content of the Nodes in reverse Order \n";
		while (temp)
		{
			cout << temp->data << "\t";
			temp = temp->prev;
		}
		cout << endl;
	}

	/* print Number of Nodes */
	void countno()
	{
		cout << "Number of Nodes = " << count << endl;
	}
};
int main()
{
	DLinkedList dl;
	dl.create(1);
	dl.Deleten(2);
	dl.Deleten(1);
	dl.countno();
	dl.insert(2, 2);
	dl.insert(1, 1);
	dl.insert(2, 2);
	dl.insert(3, 3);
	dl.display();
	dl.displayB();
	dl.countno();
}