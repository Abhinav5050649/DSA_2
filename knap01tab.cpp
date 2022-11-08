#include "bits/stdc++.h"
using namespace std;

int t[5][8];
void init_t()
{
    for (int i = 0 ; i< 5; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
        }
    }
}

void knap_Solve(int n, int W, int wt[], int val[])
{
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < W + 1; j++)
        {
            if (wt[i - 1] <= j)
            {
                t[i][j] = max(val[i - 1] + t[i - 1][j - wt[i - 1]], t[i - 1][j]);
            }
            else{
                t[i][j] = t[i - 1][j];
            }
        }
    }
}

int main()
{
    init_t();
    int wt[] = {1, 3, 4, 5};
    int val[] = {1, 4, 5, 7};
    int W = 7;
    knap_Solve(4, W, wt, val);
    int wts = t[4][7];    
    cout << wts << endl; 
    return 0;
}