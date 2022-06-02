#include<iostream>
using namespace std;
class node
{
	int data;
	node* next, * prev;
	node(int data)
	{
		this->data = data;
		next = prev=nullptr;
	}
	~node()
	{
		if (next)
			delete next;
		cout << "Deleting Node with Data " << data << endl;
	}
	friend class DList;
};

class DList
{
	node* first, * last;
public:
	DList()
	{
		first = last = nullptr;
	}
	void create(int n)
	{
		for (int i = 0; i < n; i++)
		{
			int d;
			cout << "Enter node " << i + 1 << endl;
			cin >> d;
			node* newnode = new node(d);
			if (!first)
			{
				first = last = newnode;
			}
			else
			{
				last->next = newnode;
				newnode->prev = last;
				last = newnode;
				last->next = nullptr;
			}
		}
	}
	void push_front(int data)
	{
		node* newnode = new node(data);
		if (!first)
		{
			first =last= newnode;
		}
		else
		{
			newnode->next = first;
			first->prev = newnode;
			first = newnode;
		}
	}
	void push_back(int data)
	{
		node* newnode = new node(data);
		if (!first)
		{
			first = last = newnode;
		}
		else
		{
			last->next = newnode;
			newnode->prev = last;
			last = newnode;
		}
	}
	void insert(int data, int position)
	{
		if (position < 0)
		{
			cout << "Errro Position \n";
			return;
		}

		node* newnode = new node(data);
		if (!newnode)
		{
			cout << "Memory Error \n";
			return;
		}
		if (position == 1)
		{
			push_front(data);
		}
		int k = 0;
		node* temp = first;
		while (temp && k < position - 1)
		{
			temp = temp->next;
			k++;
		}
		if (k != position - 1 || !temp)
		{
			cout << "Error Position \n";
			return;
		}
		newnode->next = temp->next;
		newnode->prev = temp;
		if (temp->next)
			temp->next->prev = newnode;
		if (!newnode->next)
		{
			last = newnode;
		}
		temp->next = newnode;
	}
	void pop_front()
	{
		if (!first)
		{
			cout << "List is empty\n";
			return;
		}
		node* temp = first;
		first = first->next;
		first->prev = nullptr;
		temp->next = nullptr;
		delete temp;
	}
	void pop_back()
	{
		if (!first)
		{
			cout << "List is Empty \n";
			return;
		}
		node* temp = last;
		last = last->prev;
		last->next = nullptr;
		temp->prev = nullptr;
		delete temp;
	}
	void Delete_item(int position)
	{
		if (position < 0)
		{
			cout << "Error Position \n";
			return;
		}
		if (position == 0)
			pop_back();
		int k = 0;
		node* temp = first;
		while (temp && k < position)
		{
			temp = temp->next;
			k++;
		}
		if (!temp || k != position )
		{
			cout << "Error Position \n";
			return;
		}
		node* p = temp->prev;
		p->next = temp->next;

		if (temp->next)
			temp->next->prev = p;
		else
			last = temp;

		temp->prev = nullptr;
		temp->next = nullptr;
		delete temp;

	}
	void display()
	{
		if (!first)
		{
			cout << "list is Empty \n";
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
	void display_back()
	{
		if (!first)
		{
			cout << "List is Empty \n";
			return;
		}
		node* temp = last;
		while (temp)
		{
			cout << temp->data << "\t";
			temp = temp->prev;
		}
		cout << endl;
	}
	~DList()
	{
		if (first != nullptr)
		{
			delete first;
			first = nullptr;
		}
	}
};