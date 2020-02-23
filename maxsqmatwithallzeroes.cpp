#include <bits/stdc++.h>
using namespace std;
int findMaxSquareWithAllZeros(int **arr, int row, int col)
{
    int n = row, m = col;
    int **b = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        b[i] = new int[m + 1];
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            b[i][j] = 0;
        }
    }
    int max_sum = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (arr[i - 1][j - 1] == 1)
            {
                continue;
            }
            else
            {
                b[i][j] = min(b[i - 1][j], min(b[i - 1][j - 1], b[i][j - 1])) + 1;
                if (b[i][j] > max_sum)
                {
                    max_sum = b[i][j];
                }
            }
        }
    }

    delete b;

    return max_sum;
}

int main()
{
    int **arr, n, m, i, j;
    cin >> n >> m;
    arr = new int *[n];
    for (i = 0; i < n; i++)
    {
        arr[i] = new int[m];
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << findMaxSquareWithAllZeros(arr, n, m) << endl;
    delete arr;
    return 0;
}