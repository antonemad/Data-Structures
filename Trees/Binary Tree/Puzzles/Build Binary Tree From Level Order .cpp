/*
	Buid Binary Tree From Level order
	input -1 from nullptr
				
*/

#include<iostream>
#include<stack>
#include<queue>
using namespace std;
class node
{
public:
	int data;
	node* left, * right;
	node(int data)
	{
		this->data = data;
		left = right = nullptr;
	}
};

/* Enter the nodes in level order to Build a Binary Tree 
	for no node Enter (-1)
*/

node* levelorderBuild()
{
	int d;
	cout << "Enter Data or (-1 for no Data) : ";
	cin >> d;
	node* root = new node(d);
	queue<node*>q;
	q.push(root);

	while (!q.empty())
	{
		node* current = q.front();
		q.pop();
		int c1, c2;
		cout << "Enter the left child of " << current->data << " : ";
		cin >> c1;
		cout << "Enter the right child of " << current->data << " : ";
		cin >> c2;
		if (c1 != -1)
		{
			current->left = new node(c1);
			q.push(current->left);
		}
		if (c2 != -1)
		{
			current->right = new node(c2);
			q.push(current->right);
		}
	}

	return root;
}
void levelorderprint(node*root)
{
	if (!root)
		return;
	queue<node*>q;
	q.push(root);
	while (!q.empty())
	{
		node* temp = q.front();
		q.pop();
		cout << temp->data << "\t";
		if (temp->left)
			q.push(temp->left);
		if (temp->right)
			q.push(temp->right);
	}
}
void preorder(node* root)
{
	if (root)
	{
		cout << root->data << "\t";
		preorder(root->left);
		preorder(root->right);
	}
}
int main()
{
	node* root = levelorderBuild();
	levelorderprint(root);
	cout << endl;
	preorder(root);
}