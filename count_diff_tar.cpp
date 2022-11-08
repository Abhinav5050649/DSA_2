#include "bits/stdc++.h"
using namespace std;

int t[5][5];
void init_t()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (j == 0)
				t[i][j] = 0;
			if (i == 0)
				t[i][j] = 1;
		}
	}
}

int count_sub_sums(int arr[], int n, int sum)
{
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < sum +1; j++)
		{
			if (arr[i - 1] <= j)
			{
				t[i][j] = t[i  -1][j] + t[i][j];
			}
			else
			{
				t[i][j] = t[i - 1][j];
			}
		}
	}
	return t[n][sum];
}

int main()
{
	int arr[] = {1, 1, 2, 3};
	int diff = 1, sum = 0;
	for (int i = 0 ; i < 4; i++)
	{
		sum += arr[i];
	}	
	init_t();
	int s1 = (sum + diff)/2, n = 4;
	cout << count_sub_sums(arr, n, s1) << endl;
	return 0;
}