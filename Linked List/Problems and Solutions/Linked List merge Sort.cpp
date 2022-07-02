#include <iostream>
using namespace std;

struct node 
{
	int data;
	node* next;
	node(int data)
	{
		this->data = data;
		next = nullptr;
	}
};

void insert(node** head,int data)
{
	if (!head)
	{
		(*head)->data = data;
		(*head)->next = nullptr;
		return;
	}
	node* newnode = new node(data);
	newnode->next = *head;
	*head = newnode;
}


node* merge(node* a, node* b)
{
	if (!a)
		return b;
	if (!b)
		return a;
	node* c = nullptr;
	if (a->data < b->data)
	{
		c = a;
		c->next = merge(a->next, b);
	}
	else
	{
		c = b;
		c->next = merge(a, b->next);
	}
	return c;
}

node* middle(node* head)
{
	node* slow = head;
	node* fast = head->next;

	while (fast&&fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

node* mergesort(node* head)
{

	if (!head->next||!head)
		return head;
	

	node* mid = middle(head);
	node* a = head;
	node* b = mid->next;
	mid->next = nullptr;
	a = mergesort(a);
	b = mergesort(b);
	return merge(a, b);
}


void print(node* head)
{
	if (!head)
	{
		cout << "List is Empty \n";
		return;
	}
	node* temp = head;
	while (temp)
	{
		cout << temp->data << "\t";
		temp = temp->next;
	}
	cout << endl;
}


int main()
{
	node* head = nullptr;

	insert(&head, 1);
	insert(&head, 20000);
	insert(&head, 3);
	insert(&head, 400);
	insert(&head, 2);
	insert(&head, -10);
	insert(&head, 15);


	cout << "List Before Sorting \n";
	print(head);

	cout << "Sorted Linked List is: \n";
	head=mergesort(head);
	print(head);

}

