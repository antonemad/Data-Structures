#include<iostream>
#include"CList.h"
using namespace std;
int main()
{
	CList cl;
	cl.create(5);
	cl.push_fornt(0);
	cl.push_back(6);
	cl.display();
	cl.pop_back();
	cl.pop_front();
	cl.display();
	cl.insert(6, 5);
	cl.display();
	cl.pop_front();
	cl.display();
	cl.Delete_item(4);
	cl.display();
	cl.DeleteList();
	cl.display();
}