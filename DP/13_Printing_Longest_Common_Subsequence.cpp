// https://www.geeksforgeeks.org/printing-longest-common-subsequence/

#include <iostream>
#include <string>
using namespace std;

string longestCommonSubsequence(string X, string Y, int m, int n)
{
    int DP[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
        DP[i][0] = 0;

    for (int i = 0; i <= n; i++)
        DP[0][i] = 0;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (X[i - 1] == Y[j - 1])
                DP[i][j] = 1 + DP[i - 1][j - 1];
            else
                DP[i][j] = 0;
        }
    }

    int index = DP[m][n];
    char result[index + 1];
    result[index] = '\0';
    
    int i = m, j = n;

    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            result[--index] = X[i - 1];
            i--;
            j--;
        }
        else
        {
            if (DP[i - 1][j] > DP[i][j - 1])
                i--;
            else
                j--;
        }
    }

   cout << result << "\n";
}

int main()
{
    int m, n;
    string X, Y;

    cin >> m >> n;
    cin >> X >> Y;

   longestCommonSubsequence(X, Y, m, n);

    return 0;
}
