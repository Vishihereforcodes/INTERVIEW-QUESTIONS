// https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle/0

#include <iostream>
using namespace std;

// Solution 1: Using Recursion
int eggDropPuzzle(int eggs, int floors)
{
    if(floors == 1 || eggs == 1)
        return 1;

    int minimum = INT_MAX;
    for (int k = 1; k <= floors; k++)
    {
        int tempAns = 1 + max(eggDropPuzzle(eggs-1, k-1), eggDropPuzzle(eggs, floors-k));

        minimum = min(tempAns, minimum);
    }
    return minimum;
}

int main()
{
    int t, eggs, floors;
    cin >> t;

    while (t--)
    {
        cin >> eggs >> floors;

        cout << eggDropPuzzle(eggs, floors) << "\n";
    }
}
