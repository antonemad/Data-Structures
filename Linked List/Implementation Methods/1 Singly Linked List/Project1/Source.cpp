#include<iostream>
#include"LinkedList.h"
using namespace std;
int main()
{
	LinkedList l;
	l.create(5);
	l.push_back(6);
	l.push_front(0);
	l.display();
}