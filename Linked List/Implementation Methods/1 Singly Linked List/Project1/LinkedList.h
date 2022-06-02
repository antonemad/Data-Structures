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
	~node()
	{
		if (next != nullptr)
			delete next;
		cout << "Deleting Node with Data : " << data << endl;
	}
	friend class LinkedList;
};
class LinkedList
{
	node* first, * last;
public:
	LinkedList()
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
				newnode->next = nullptr;
			}
			else
			{
				last->next = newnode;
				last = newnode;
			}
		}
	}
	void push_front(int data)
	{
		node* newnode = new node(data);
		if (!first)
		{
			first = last = newnode;
		}
		else
		{
			newnode->next = first;
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
			last = newnode;
		}
	}
	bool Search(int data)
	{
		node* temp = first;
		while (temp)
		{
			if (temp->data == data)
				return true;
			temp = temp->next;
		}
		return false;
	}
	void insert(int data, int position)
	{
		if (position < 0)
		{
			cout << "Error Position \n";
			return;
		}

		node* newnode = new node(data);
		if (!newnode)
		{
			cout << "Memory Error !!\n";
			return;
		}
		if (position == 0)
		{
			push_front(data);
			return;
		}

		node* p = first;
		int k = 0;

		while (p && k < position - 1)
		{
			p = p->next;
			k++;
		}

		if (k != position - 1)
		{
			cout << "Error Position \n";
		}
		if (p)
		{
			newnode->next = p->next;
			p->next = newnode;
		}
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
		node* p = temp;
		while (temp->next)
		{
			p = temp;
			temp = temp->next;
		}
		p->next = nullptr;
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
			pop_front();
		int k = 0;
		node* temp = first;
		while (temp && k < position - 1)
		{
			temp = temp->next;
			k++;
		}
		if (k != position - 1 || !temp)
		{
			cout << "position not Exist \n";
			return;
		}
		node* p = temp->next;
		temp->next = p->next;
		p->next = nullptr;
		delete p;

	}
	void DeleteList()
	{
		if (!first)
		{
			cout << "List is Empty \n";
			return;
		}
		node* aux, * it = first;
		while (it)
		{
			aux = it->next;
			delete it;
			it = aux;
		}
		first = nullptr;
	}
	void display()
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
	~LinkedList()
	{
		cout << "Deleting " << first->data << endl << endl;
		if (first != nullptr)
			delete first;
	}

};
