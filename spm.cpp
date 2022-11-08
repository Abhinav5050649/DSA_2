#include "bits/stdc++.h"
using namespace std;

//Sequence Pattern Matching

int t[1001][1001];

int lcs(string x, string y, int m, int n)
{
    for (int i= 0 ; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i== 0 || j == 0)
                t[i][j] = 0;
        }
    }

    for (int i= 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (x[i - 1] == y[j - 1])
                t[i][j] = 1 + t[i - 1][j - 1];
            else
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
        }
    }

    return t[m][n];
}

int main()
{
    string alp = "AXY", beta = "ADXCPY";
    int m = alp.length(), n = beta.length();

    if (lcs(alp, beta, m, n) == min(m, n))
        cout << "true\n";
    else
        cout << "false\n";
    return 0;
}