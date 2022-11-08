#include "bits/stdc++.h"
using namespace std;

// Longest Common Subsequence (Memoization)
int t[7][9];
int lcs(string X, string Y, int m, int n)
{
	if (m == 0 || n == 0)
	{
		return 0;
	}

	if (t[m][n] != -1)
	{
		return t[m][n];
	}

	if (X[m - 1] == Y[n - 1])
	{
		t[m][n] = 1 + lcs(X, Y, m - 1, n - 1);
		return t[m][n];
	}
	else
	{
		t[m][n] = max(lcs(X, Y, m - 1, n), lcs(X, Y, m, n - 1));
		return t[m][n];
	}
}

int main()
{
	string X = "abcdef", Y = "abdefghr";
	int m = X.length(), n = Y.length();
	memset(t, -1, sizeof(t));

	cout << lcs(X, Y, m, n) << endl;
	return 0;
}