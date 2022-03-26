/* Implementation of a Singly Linked List */

#include<iostream>
using namespace std;
struct node
{
	int data;
	node* next;
};


class linkedlist
{
	node* first, * last;
	int count;
public:
	linkedlist():first(nullptr),last(nullptr),count(0)
	{}
	/* Create Linked List */
	void create(int n)
	{
		int d;
		cout << "Enter the Data for " << n << " Nodes\n";
		for (int i = 0; i < n; i++)
		{
			node* newnode = new node;
			cout << "Enter the Node "<<i+1<<" :  ";
			cin >> d;
			newnode->data = d;
			newnode->next = nullptr;
			if (!first)
			{
				first = last = newnode;
			}
			last->next = newnode;
			last = newnode;
			count++;
		}
	}

	 /* Insert to the Linked list */
	void insert(int position,int d)
	{
		int k = 1;
		node *newnode = new node;
		if (!newnode)
		{
			cout << "Memory Error !!!\n";
			return;
		}
		if (position < 1 || position>count + 1)
		{
			cout << "Error Position !!! \n";
			return;
		}

		newnode->data = d;

		if (position == 1)
		{
			newnode->next = first;
			first = newnode;
			count++;
			return;
		}
		node* p = first;
		while (p && k < position - 1)
		{
			p = p->next;
			k++;
		}
		if (p)
		{
			newnode->next = p->next;
			p->next = newnode;
		}
		count++;
	}

	/* Deleting a node From a Linked List */
	void Deleten(int position)
	{
		if (!first)
		{
			cout << "List is Empty \n";
			return;
		}

		/* Initial variables */
		node* temp = first;
		int k = 1;

		if (position<1 || position>count)
		{
			cout << "Error Position \n";
			return;
		}
		if (position == 1)
		{
			if (first->next == nullptr)
			{
				first = last = nullptr;
			}
			else
				first = first->next;

			delete temp;
			count--;
			return;
		}

		node* p = nullptr;
		while (k < position && temp)
		{
			p = temp;
			temp = temp->next;
			k++;
		}
		
		if (temp && p)
		{
			p->next = temp->next;
			
			if (p->next == nullptr)
				last = p;

			delete temp;
			count--;

			return;
		}
	}

	/* Deleting all the Nodes from a Linked List */

	void DeleteF()
	{
		node* temp = first;
		node* p;
		while (temp)
		{
			p = temp->next;
			delete temp;
			temp = p;
		}
		first = nullptr;
		count = 0;
		return;
	}

	/* Number of Nodes in the Linked List */
	void countno()
	{
		cout << "Number of nodes = " << count << endl;
	}

	/* Print The Content of the Linked List */
	void showdata()
	{
		if (!first)
		{
			cout << "List is Empty \n";
			return;
		}
		node* temp = first;
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
	linkedlist l;
	l.create(5);
	l.countno();
	l.showdata();
	l.insert(5, 10);
	l.insert(7, 17);
	l.insert(1, 0);
	l.showdata();
	l.countno();
	cout << "\nStart Deleting \n\n";
	l.Deleten(1);
	l.Deleten(5);
	l.showdata();
	l.countno();
	l.DeleteF();
	l.countno();
	l.showdata();
}