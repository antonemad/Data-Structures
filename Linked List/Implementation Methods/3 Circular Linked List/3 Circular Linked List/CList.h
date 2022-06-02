#include<iostream>
using namespace std;
class node
{
	int data;
	node* next;
	node(int data)
	{
		this->data = data;
		next = nullptr;
	}
	friend class CList;
};
class CList
{
	node* first, * last;
public:
	CList()
	{
		first = last = nullptr;
	}
	void create(int n)
	{
		int d;
		for (int i = 0; i < n; i++)
		{
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
				last = newnode;
			}
			newnode->next = first;

		}
	}
	
	void push_fornt(int data)
	{
		node* newnode = new node(data);
		if (!first)
		{
			first = last = newnode;
			return;
		}
		node* p = first;
		
		newnode->next = first;
		first = newnode;
		last->next = first;
	}
	void push_back(int data)
	{
		node* newnode = new node(data);
		if (!first)
		{
			first = last = newnode;
			return;
		}
		last->next = newnode;
		newnode->next = first;
		last = newnode;
	}

	void insert(int data, int position)
	{
		if (position < 0)
		{
			cout << "Error Position \n";
			return;
		}
		if (position == 1)
		{
			push_fornt(data);
			return;
		}

		node* newnode = new node(data);
		int k = 0;
		node* temp = first;
		while (k < position - 1 && temp->next != first)
		{
			temp = temp->next;
			k++;
		}
		if (k != position - 1)
		{
			cout << "Error Position \n";
			return;
		}

		if (temp->next == first)
		{
			push_back(data);
			return;
		}
		
		newnode->next = temp->next;
		temp->next = newnode;
		
	}

	void pop_front()
	{
		if (!first)
		{
			cout << "List is Empty \n";
			return;
		}
		node* temp = first;
		first = first->next;
		last->next = first;
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
		node* temp = first;

		while (temp->next != last)
		{
			temp = temp->next;
		}
		last = temp;
		temp = last->next;
		last->next = first;
		delete temp;
	}
	void Delete_item(int position)
	{
		if (position < 0)
		{
			cout << "Error Position \n";
			return;
		}
		if (!first)
		{
			cout << "List is Empty \n";
			return;
		}
		if (position == 0)
		{
			pop_front();
			return;
		}
		node* temp = first;
		node* p = temp;
		int k = 0;
		while (k < position && temp->next != first)
		{
			p = temp;
			temp = temp->next;
			k++;
		}
		if (k != position)
		{
			cout << "Error Position \n";
			return;
		}
		if (temp->next == first)
		{
			pop_back();
			return;
		}
		p->next = temp->next;
		temp->next = nullptr;
		delete temp;
	}

	void display()
	{
		if (!first)
		{
			cout << "List is Empty \n";
			return;
		}
		node* temp = first;
		do
		{
			cout << temp->data << "\t";
			temp = temp->next;
		} while (temp != first);
		cout << endl;
	}

	void DeleteList()
	{
		node* aux, * it=first;
		last->next = nullptr;
		while (it)
		{
			aux = it->next;
			delete it;
			it = aux;
		}
		first = nullptr;
	}
};

