/* (https://www.geeksforgeeks.org/palindrome-partitioning-dp-17/)

*/

#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s)
{
    if(s=="")
        return false;
    string rev = s;
    reverse(s.begin(),s.end());
   
    return s == rev;
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

int main()
{
    string s;
    cin>>s;

    int n = s.size();
    int i = 0 , j = n - 1;
    cout<<"Minimum no of partitions to split the given string into palindromes is "<<Partitions(s , i , j);
}
