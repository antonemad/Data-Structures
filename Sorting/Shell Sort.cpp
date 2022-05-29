#include<iostream>
using namespace std;
int main()
{
	int arr[] = {23,29,15,19,31,7,9,5,2};
	int n = 9;
	for (int inc = n / 2; inc > 0; inc /= 2)
	{
		for (int i = inc; i < n; i++)
		{
			int j = i;
			int v = arr[i];
			while (arr[j - inc] > v && j >= inc)
			{
				arr[j] = arr[j - inc];
				j -= inc;
			}
			arr[j] = v;
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}

}