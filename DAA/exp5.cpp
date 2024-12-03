#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

const int MAX = 100;
int dp[MAX][MAX];

int matrixChainMemoised(int p[], int i, int j)
{
    if (i == j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    dp[i][j] = INT_MAX;
    for (int k = i; k < j; k++)
        dp[i][j] = min(dp[i][j], matrixChainMemoised(p, i, k) + matrixChainMemoised(p, k + 1, j) + p[i - 1] * p[k] * p[j]);

    return dp[i][j];
}

int MatrixChainOrder(int p[], int n)
{
    int i = 1, j = n - 1;
    return matrixChainMemoised(p, i, j);
}

int main()
{
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    memset(dp, -1, sizeof(dp));
    cout << "Minimum number of multiplications is " << MatrixChainOrder(arr, n) << endl;
    return 0;
}