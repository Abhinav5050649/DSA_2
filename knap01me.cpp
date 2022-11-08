#include "bits/stdc++.h"
using namespace std;

int t[5][8];

void init_t()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            t[i][j] = -1;
        }
    }
}

int knap_mem(int wt[], int val[], int n, int W)
{
    if (n == 0 || W == 0)
    {
        return 0;
    }

    if (t[n][W] != -1)
    {
        return t[n][W];
    }

    if (wt[n - 1] <= W)
    {
        t[n][W] = max(val[n - 1] + knap_mem(wt, val, n - 1, W - wt[n - 1]), knap_mem(wt, val, n - 1, W));
        return t[n][W];
    }
    else
    {
        t[n][W] = knap_mem(wt, val, n - 1, W);
        return t[n][W];
    }
}

int main()
{
    init_t();
    int val[] = {1, 4, 5, 7};
    int wt[] = {1, 3, 4, 5};
    int n = 4, W = 7;
    int ans = knap_mem(wt, val, n, W);    
    cout << ans << endl;
    return 0;
}