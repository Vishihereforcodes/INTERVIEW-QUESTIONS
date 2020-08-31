/* (https://www.geeksforgeeks.org/palindrome-partitioning-dp-17/)

*/

#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

int DP[1001][1001];

bool isPalindrome(string s)
{
    if(i >= j)
        return true;
    
    while(i < j)
    {
        if(s[i] != s[j])
            return false;
        i++; j--;
    }
    return true;
}

// Solution1 :- Recursive..
int Partitions(string s , int i , int j)
{
    // if string is empty or of only one element then its already a palindrome.
    if(i >= j)
        return 0;
    
    if(isPalindrome(s))
        return 0;
    
    int minimum = INT_MAX;
    for(int k = i ; k <= j-1 ; k++)
    {
        int tempAns = 1 + Partitions(s , i , k) + Partitions(s , k+1 , j);

        if(tempAns < minimum)
            minimum = tempAns;

    }
    return minimum;
}

// Solution2 :- Recursion + Memoization..
int Partitions(string s , int i , int j)
{
    // if string is empty or of only one element then its already a palindrome.
    if(i >= j)
        return 0;
    
    if(isPalindrome(s , i , j))
        return 0;
    
    if(DP[i][j] != -1)
        return DP[i][j];
    
    int minimum = INT_MAX;
    for(int k = i ; k <= j-1 ; k++)
    {
        int tempAns = 1 + Partitions(s , i , k) + Partitions(s , k+1 , j);

        if(tempAns < minimum)
            minimum = tempAns;

    }
    return DP[i][j] = minimum;
}

int main()
{
    string s;
    cin>>s;

    int n = s.size();
    int i = 0 , j = n - 1;
    cout<<"Minimum no of partitions to split the given string into palindromes is "<<Partitions(s , i , j);
}
