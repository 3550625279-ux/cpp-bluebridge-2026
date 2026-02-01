#include<iostream>
#include<algorithm>
int find_min(int* p1, int* p2)
{
	int min = *p1;
	for(int *ptr=p1;ptr!=p2;ptr++)
		if(*ptr<min)
			min = *ptr;
	return min;
}

int main()
{
	using namespace std;
	int n, m;
	cin >> n >> m;
	int* arr = new int[n];
	for(int i=0;i<n;i++)
		cin >> arr[i];
	cout << 0 << endl;
	for (int i = 1;i < n;i++)
	{
		cout << find_min(&arr[i-min(m,i)], &arr[i]) << endl;
	}
	delete[] arr;
}