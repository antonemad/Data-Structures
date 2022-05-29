#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int arr[] = { 1,22,5,3,2 };
	for (int i = 0; i < 4; i++)
	{
		int min = i;
		for (int j = i + 1; j < 5; j++)
		{
			if (arr[min] > arr[j])
				min = j;
		}
		if (min != i)
			swap(arr[i], arr[min]);
	}

	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << "\t";
	}

}