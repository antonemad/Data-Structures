#include<iostream>
#include<stack>
#include<queue>
using namespace std;
class node
{
public:
	int data;
	node* left, * right;
	node(int d)
	{
		this->data = d;
		this->left = NULL;
		this->right = NULL;
	}
};
node*create()
{
	int x;
	cout << "Enter the Data or (-1 for no Data) : ";
	cin >> x;
	cout << endl;

	if (x == -1)
		return nullptr;

	node* newnode = new node(x);

	cout << "\nThe left child of  " << x <<endl<<"**********************\n";
	newnode->left = create();
	cout << "\nThe right child of  " << x << endl<<"***********************\n";
	newnode->right = create();
	cout << endl;
	return newnode;
}
void preorder(node*root)
{
	if (!root)
		return;
	cout << root->data << "\t";
	preorder(root->left);
	preorder(root->right);
}
void inorder(node*root)
{
	if (root)
	{
		inorder(root->left);
		cout << root->data << "\t";
		inorder(root->right);
	}
}
void postorder(node* root)
{
	if (root)
	{
		inorder(root->left);
		inorder(root->right);
		cout << root->data << "\t";
	}
}
void levelorder(node* root)
{
	node* temp;
	queue<node*>q;
	if (!root)
		return;
	q.push(root);
	while (!q.empty())
	{
		temp = q.front();
		q.pop();
		cout << temp->data << "\t";
		if (temp->left)
			q.push(temp);
		if (temp->right)
			q.push(temp);
	}
}
int main()
{
	node* root = create();
	preorder(root);
	inorder(root);
	postorder(root);
	levelorder(root);
}