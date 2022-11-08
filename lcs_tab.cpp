#include "bits/stdc++.h"
using namespace std;

//Longest Common Subsequence Tabulation

int t[7][9];

int lcs(string X, string Y, int m, int n)
{
	for (int i= 1; i < 7; i++)
	{
		for (int j = 1; j < 9; j++)
		{
			if (X[i - 1] == Y[j - 1])
			{
				t[i][j] = 1 + t[i - 1][j - 1];
			}
			else
			{
				t[i][j] = max(t[i - 1][j], t[i][j - 1]);
			}
		}
	}

	return t[m][n];
}

int main()
{
	string X = "abedgh", Y = "abdefghr";
	int m = 6, n = 8;
	for (int i= 0; i < 7; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (i == 0 || j == 0)
				t[i][j] = 0;
		}
	}

	cout << lcs(X, Y, m, n) << endl;
	return 0;
}