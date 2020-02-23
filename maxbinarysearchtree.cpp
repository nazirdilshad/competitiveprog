#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

long long mod = 1e9 + 7;
int countBST(int n)
{
    long long bst[n];
    bst[0] = 1;
    bst[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        bst[i] = 0;
        for (int j = 0; j < i; j++)
        {
            bst[i] += (((bst[j]) % mod) * ((bst[i - j - 1]) % mod)) % mod;
            bst[i] = bst[i] % mod;
        }
    }
    return bst[n];
}

int main()
{
    int n;
    cin >> n;
    cout << countBST(n);
    return 0;
}
