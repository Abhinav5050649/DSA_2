#include "bits/stdc++.h"
using namespace std;

//Minimum number of insertions to make a string palindrome

int t[1001][1001];

int insert_pal(string X, string Y, int m, int n)
{
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i == 0 || j == 0)
				t[i][j] = 0;
		}
	}

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
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
	string X = "aebcbda", Y = X;
	reverse(Y.begin(), Y.end());
	cout << X.length() - insert_pal(X, Y, X.length(), Y.length()) << endl;
	return 0;
}