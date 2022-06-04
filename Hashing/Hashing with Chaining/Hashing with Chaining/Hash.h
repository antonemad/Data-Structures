#include<iostream>
#include<cmath>
using namespace std;

class node
{
	int value;
	node* next;
	node(int value)
	{
		this->value = value;
		next = nullptr;
	}
	friend class Hash;
	~node()
	{}
};

class Hash
{
	int cs;
	int ts;
	node** table;

	int hashFn(int value)
	{
		return abs(value) % ts;
	}

	void rehash()
	{
		node** oldtable = table;
		int oldts = ts;
		cs = 0;
		ts *= 2;

		table = new node * [ts];
		if (!table)
		{
			cout << "Allocation Failed \n";
			return;
		}

		for (int i = 0; i < ts; i++)
			table[i] = nullptr;

		for (int i = 0; i < oldts; i++)
		{
			node* temp = oldtable[i];
			while (temp)
			{
				int v = temp->value;
				insert(v);
				temp = temp->next;
			}
			if (oldtable[i] != NULL)
				delete oldtable[i];
		}
		delete[]oldtable;
	}

public:
	//Constructor
	Hash(int default_size=7)
	{
		cs = 0;
		ts = default_size;
		table = new node*[ts];
		for (int i = 0; i < ts; i++)
		{
			table[i] = nullptr;
		}
	}


	//insert an Element at the head of Hash Table 
	void insert(int value)
	{
		int idx = hashFn(value);

		node* newnode = new node(value);
		if (!newnode)
		{
			cout << "Memory Error \n";
			return;
		}

		newnode->next = table[idx];
		table[idx] = newnode;
		cs++;

		float load_factor = cs / float(ts);
		if (load_factor > 0.75)
			rehash();

	}


	// Search for an Element in the Hash Table
	void search(int data)
	{
		int idx = hashFn(data);
		node* temp = table[idx];
		while (temp)
		{
			if (temp->value == data)
			{
				cout << data << " in the table at index " << idx << endl;
				return;
			}
			temp = temp->next;
		}
		cout << data << "  not exist in the table \n";
	}

	// Delete an item at a particula List in the Hash Table
	void Delete_item(int data)
	{
		int idx = hashFn(data);
		node* temp = table[idx];
		node* prev = nullptr;
		if (!temp)
		{
			cout << "this list is Empty\n\n";
			return;
		}
		if (temp->value == data)
		{
			table[idx] = temp->next;
			delete temp;
			cs--;
			return;
		}

		while (temp->next && temp->value != data)
		{
			prev = temp;
			temp = temp->next;
		}

		if (prev && temp->value == data)
		{
			prev->next = temp->next;
			delete temp;
			cs--;
			return;
		}
		cout << "Not in the List \n\n";
	}

	// Rmove all the Elements from the Table 
	// and resize the Table 
	void clear_table()
	{
		for (int i = 0; i < ts; i++)
		{
			node* temp = table[i];
			while (temp)
			{
				node* aux = temp;
				temp = temp->next;
				delete aux;
			}
			table[i] = temp;
		}
		cs = 0;
		ts = 7;
	}

	//Dispaly all teh Elements in the table 
	void print()
	{
		if (!table)
		{
			cout << "Hash Table is Empty \n";
			return;
		}

		for (int i = 0; i < ts; i++)
		{
			cout << "Bucket " << i << " ";
			node* temp = table[i];
			while (temp)
			{
				cout << " -->  " << temp->value;
				temp = temp->next;
			}
			cout << endl;
		}
		cout << endl << endl;
	}

	~Hash()
	{}
};





