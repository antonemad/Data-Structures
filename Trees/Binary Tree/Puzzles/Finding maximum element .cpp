/*
	Finding the maximum Value in a Binary Tree using : 
		(1) Recursion 
		(2) Level Order
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

// Build Tree 
node* create()
{
	int x;
	cout << "Enter the Value of the node or (-1 for no Node) : ";
	cin >> x;
	if (x == -1)
		return nullptr;
	node* newnode = new node(x);
	cout << "\nLeft Child of " << x << endl;
	newnode->left = create();
	cout << "\nRight Child of " << x << endl;
	newnode->right = create();
	return newnode;
}

// Finding maximum Value Using Recursion 

int findMaxR(node* root)
{
	int root_value, left_value, right_value;
	int maxv = INT_MIN;
	if (root)
	{
		root_value = root->data;
		left_value = findMaxR(root->left);
		right_value = findMaxR(root->right);

		if (left_value > right_value)
			maxv = left_value;
		else
			maxv = right_value;
		if (root_value > maxv)
			maxv = root_value;
	}
	return maxv;
}

// Finding maximum Value Using Level Order

int findmax(node* root)
{
	int maxv = INT_MIN;
	node* temp;
	queue<node*>q;
	q.push(root);
	while (!q.empty())
	{
		temp = q.front();
		q.pop();
		if (temp->data > maxv)
			maxv = temp->data;
		if (temp->left)
			q.push(temp->left);
		if (temp->right)
			q.push(temp->right);
	}
	return maxv;
}
int main()
{
	node* root = create();
	cout << "\nMaximum Value 1 : " << findMaxR(root) << endl;
	cout << "Maximum Value 2 : " << findmax(root) << endl;
}	