#include<iostream>
using namespace std;
struct node
{
	int data;
	node* next;
};

class Clinkedlist
{
	node* first, * last;
	int count;
public:
	Clinkedlist():first(nullptr),last(nullptr),count(0)
	{}

	void create(int n)
	{
		int d;
		cout << "Enter the data for a " << n << " nodes \n";
		for (int i = 0; i < n; i++)
		{
			node* newnode = new node;
			cout << "nodes " << i + 1 << " : ";
			cin >> d;
			newnode->data = d;
			newnode->next = nullptr;

			if (!first)
			{
				first = last = newnode;
			}
			else
			{
				last->next = newnode;
				last = newnode;
			}
			count++;
		}
		last->next = first;
	}

	/* Insert a Node to a List */
	void inset(int position, int data)
	{
		if (position<1 || position>count + 1)
		{
			cout << "Error Position \n";
			return;
		}

		/* Initial Variables */
		node* newnode = new node;
		node* temp = first;
		int k = 1;

		if (!newnode)
		{
			cout << "Memory Error !!\n";
			return;
		}
		newnode->data = data;

		/* Inset to the first Position */

		if (position == 1)
		{
			if (!first)
			{
				first = last = newnode;
				newnode->next = first;

				count++;
				return;
			}
			while (temp->next != first)
			{
				temp = temp->next;
			}

			newnode->next = first;
			temp->next = newnode;
			first = newnode;

			count++;
			return;
		}

		while (k < position-1 && temp)
		{
			temp = temp->next;
			k++;
		}

		if (temp)
		{
			newnode->next = temp->next;
			temp->next = newnode;
			if (newnode->next == first)
				last = newnode;
			count++;
		}
	}

	/* Deleting a Node from a List */

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

		/* Initial variables */
		node* temp = first, * p{};
		int k = 1;

		if (position == 1)
		{
			if (first->next == first)
			{
				first = last = nullptr;
				delete temp;
				count--;
				return;
			}

			while (temp->next != first)
			{
				temp = temp->next;
			} 
			p = first;
			temp->next = first->next;
			first = first->next;
			delete p;
			count--;
			return;
		}
		while (k < position-1 && temp->next!=first)
		{
			p = temp;
			temp = temp->next;
			k++;
		}

		if (temp && p)
		{
			p->next = temp->next;
			temp->next = nullptr;
			delete temp;

			if (p->next == first)
				last = p;
			count--;
			return;
		}
	}

	/* Dispaly the Data of the List */
	void display()
	{
		if (!first)
		{
			cout << "List is Empty \n";
			return;
		}
		node* temp = first;

		cout << "The Content of the List : ";
		do
		{
			cout << temp->data << "\t";
			temp = temp->next;
		} while (temp != first);
		cout << endl;
	}

	/* Number of Nodes */
	void count_no()
	{
		cout << "Number of Nodes = " << count << endl;
	}

};

int main()
{
	Clinkedlist c;
	c.create(3);
	c.display();
	c.inset(1,0);
	c.inset(5, 4);
	c.inset(10, 10);
	c.display();
	c.Deleten(1);
	c.display();
}