#include<iostream>
#include"Hash.h"
#include<vector>
using namespace std;
int main()
{
	Hash h;
	h.insert(5);
	h.insert(10);
	h.insert(15);
	h.insert(20);
	h.insert(25);
	h.insert(5);
	h.insert(88);
	h.insert(30);
	h.insert(60);
	h.print();
	h.Delete_item(60);
	h.Delete_item(30);
	h.print();
}