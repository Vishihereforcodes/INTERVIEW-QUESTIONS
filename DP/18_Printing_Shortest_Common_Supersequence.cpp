/* (https://leetcode.com/problems/shortest-common-supersequence/)

Question:- Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences.  If multiple answers exist, you may return any of them.

Approach:-
As we know , to get shortest common supersequence we have to include a particular letter only once if it is present in both strings so to include the common letter once we have to
subtract the longest common supersequence from the total length of both strings .

1. initialisation:- when any of the two strings is empty then empty subsequence will be common whose size will be zero.
2. Code:- If letters at particular index of the matrix is equal then will include that length of longest subsequence will be one greater than the length at one minus that index
else will not include that length and length will be the maximum of one less in the index.

using these steps we will get length of longest common subsequence and substracting it from total length of both strings we will get our shortest common supersequence length.

*/

class Solution
{
public:
    string shortestCommonSupersequence(string str1, string str2)
    {
        int n = str1.size(), m = str2.size();
        int DP[n + 1][m + 1];

        for (int i = 0; i <= n; i++)
            DP[i][0] = 0;

        for (int i = 0; i <= m; i++)
            DP[0][i] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                    DP[i][j] = 1 + DP[i - 1][j - 1];
                else
                    DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
            }
        }

        string result;

        int i = n, j = m;
        while (i > 0 && j > 0)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                result.push_back(str1[i - 1]);
                i--;
                j--;
            }
            else
            {
                if (DP[i - 1][j] > DP[i][j - 1])
                    result.push_back(str1[--i]);
                else
                    result.push_back(str2[--j]);
            }
        }

        while (i > 0)
            result.push_back(str1[--i]);

        while(j > 0)
            result.push_back(str2[--j]);

        reverse(result.begin(), result.end());
        return result;
    }
};
