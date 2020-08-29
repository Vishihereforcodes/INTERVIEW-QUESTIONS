/* UnBounded Knapsack.

Question:- We are given a knapsack and we have an array of items with price of each item and we have a max capacity of knapsack . We have to find the maximum profit after 
including the items in the knapsack (ONE ITEM CAN BE ADDED MORE THAN ONCE).

Approach:-


*/

#include <iostream>
using namespace std;

int knapsack(int value[], int weight[], int capacity, int N)
{
    int DP[N + 1][capacity + 1];

    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= capacity; j++)
        {
            if (i == 0 || j == 0)
                DP[i][j] = 0;

            else if (weight[i - 1] <= j)
                DP[i][j] = max(value[i - 1] + DP[i][j-weight[i-1]],DP[i-1][j]);
            else
                DP[i][j] = DP[i-1][j];
        }
    }
    return DP[N][capacity];
}

int main()
{
    int T, N, capacity;
    cin >> T;

    while (T--)
    {
        cin >> N >> capacity;
        int value[N], weight[N];

        for (int i = 0; i < N; i++)
            cin >> value[i];

        for (int i = 0; i < N; i++)
            cin >> weight[i];

        cout << knapsack(value, weight, capacity, N) << "\n";
    }

    return 0;
}
