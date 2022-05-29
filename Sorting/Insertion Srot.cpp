#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int arr[] = { 1,22,5,3,2 };
	for (int i = 1; i < 5; i++)
	{
		int v = arr[i];
		int j = i;
		while (arr[j - 1] > v && j > 0)
		{
			arr[j] = v;
			j--;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << "\t";
	}

}