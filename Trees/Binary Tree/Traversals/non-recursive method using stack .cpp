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
node* create()
{
	int x;
	cout << "Enter the Data or (-1 for no Data) : ";
	cin >> x;
	cout << endl;

	if (x == -1)
		return nullptr;

	node* newnode = new node(x);

	cout << "\nThe left child of  " << x << endl << "**********************\n";
	newnode->left = create();
	cout << "\nThe right child of  " << x << endl << "***********************\n";
	newnode->right = create();
	cout << endl;
	return newnode;
}
void preorder(node*root)
{
	stack<node*>s;
	node* temp = root;
	while (!s.empty() || temp)
	{
		while (temp)
		{
			cout << temp->data << "\t";
			s.push(temp);
			temp = temp->left;
		}
		temp = s.top();
		s.pop();
		temp = temp->right;
	}
}
void inorder(node* root)
{
	stack<node*>s;
	node* temp = root;
	while (!s.empty() || temp)
	{
		while (temp)
		{
			s.push(temp);
			temp = temp->left;
		}
		temp = s.top();
		s.pop();

		cout << temp->data << "\t";
		temp = temp->right;
	}
}
void postorder(node* root)
{
	stack<node*>s;
	node* previous = nullptr;
	node* temp = root;
	do
	{
		while (temp)
		{
			s.push(temp);
			temp = temp->left;
		}
		while (!temp && !s.empty())
		{
			temp = s.top();
			if (temp->right == nullptr || temp->right == previous)
			{
				cout << temp->data << "\t";
				s.pop();
				previous = temp;
				temp = nullptr;
			}
			else
				temp = temp->right;
		}
	} while (!s.empty());
}
int main()
{

}