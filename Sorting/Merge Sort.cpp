// merge sort using vectors

#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>& arr, int s, int e)
{
	int i = s;
	int m = (s + e) / 2;
	int j = m + 1;
	vector<int>temp;
	while (i <= m && j <= e)
	{
		if (arr[i] < arr[j])
		{
			temp.push_back(arr[i++]);
		}
		else
			temp.push_back(arr[j++]);
	}
	while (i <= m)
		temp.push_back(arr[i++]);

	while (j <= e)
		temp.push_back(arr[j++]);

	int k = 0;
	for (int i = s; i <= e; i++)
		arr[i] = temp[k++];
}
void mergesort(vector<int>& arr, int s, int e)
{
	if (s >= e)
		return;
	int mid = (s + e) / 2;
	mergesort(arr, s, mid);
	mergesort(arr, mid + 1, e);
	merge(arr, s, e);
}
int main()
{

}