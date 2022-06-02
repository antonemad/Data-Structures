#include<iostream>
#include"DList.h"
using namespace std;
int main()
{
	DList dl;
	dl.create(5);
	dl.push_back(6);
	dl.push_front(0);

	dl.display();
	dl.pop_back();
	dl.pop_front();
	dl.display();
	dl.Delete_item(3);
	dl.display();
}