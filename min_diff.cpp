#include "bits/stdc++.h"
using namespace std;

bool t[4][11];
void init_t()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			if (j == 0)
				t[i][j] = false;
			if (i == 0)
				t[i][j] = true;
		}
	}
}

void sub_sum(int arr[], int n, int sum)
{
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < sum + 1; j++)
		{
			if (arr[i - 1] <= j)
			{
				t[i][j] = t[i - 1][j] || t[i - 1][j - arr[i - 1]];
			}
			else
			{
				t[i][j] = t[i - 1][j];
			}
		}
	}

	vector<int> v;
	for (int i = 0; i < sum/2; i++)
	{
		if (t[n - 1][i] == true)
		{
			v.push_back(i);
		}
	}

	int minu = INT_MAX;
	for (int i = 0, ns = v.size(); i < ns; i++)
	{
		minu = min(minu, sum - 2*v[i]);
	}

	cout << minu << endl;
	v.clear();
}

int main()
{
	init_t();
	int arr[] = {1, 2, 7};
	int n = 3, sum = 10;
	sub_sum(arr, n, sum);
	return 0;
}