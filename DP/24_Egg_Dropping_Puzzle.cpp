/* (https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle/0)

Question:- We are given no of eggs and no of floors . We have to find the threshold floor .
Threshold floor is the first possible floor from which if we will throw the egg , it will not break.

*/

#include <iostream>
using namespace std;

// Solution 1: Using Recursion
int eggDropPuzzle(int eggs, int floors)
{
    // If there is only one floor then at worst case it will be the only threshold floor if egg will not break throwing from it.
    // If there is only one egg then in worst case
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
