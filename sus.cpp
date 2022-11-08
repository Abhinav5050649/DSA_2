#include "bits/stdc++.h"
using namespace std;

//Recursive Code for Subset Sum Problem
void ss(int arr[], int n, int target, int sum, vector<int> &ds)
{
	if (n == 0 || target == 0)
	{
		ds.push_back(sum);
		return;
	}

	if (arr[n - 1] <= target)
	{
		ss(arr, n -1, target - arr[n - 1], sum + arr[n - 1], ds);
		ss(arr, n -1, target, sum, ds);
	}
	else
		ss(arr, n -1, target, sum, ds);
}

int main()
{
	int arr[] = {22, 13, 12, 20, 10};
	int n = 5, target = 11, sum = 0;
	vector<int> ds;
	ss(arr, n, target, sum, ds);
	sort(ds.begin(), ds.end());
	for (auto it: ds)
	{
		if (it == target)
		{
			cout << "TRUE\n";
			return 0;
		}
	}
	cout << "FALSE\n";
	return 0;
}