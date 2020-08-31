/* (https://www.geeksforgeeks.org/boolean-parenthesization-problem-dp-37/)

*/

#include<bits/stdc++.h>
using namespace std;

int Evaluate(string s , int i , int j , bool isTrue)
{
    // Empty string will be false.
    if(i > j)
        return false;
    
    // If string contains only one element then we will check what we want to evaluate 
    // the whole string to be true if we need true and the string is also true then 
    // return true else false and if we need false and the string is also false then
    // return true else return false.
    if(i == j)
    {
        if(isTrue == true)
            return s[i] == 'T';
        else
            return s[i] == 'F';
    }

    int ans = 0;

    // As our string contains either 'T' , 'F' or operators('^' , '&' , '|') so we have to partition at
    // operator because partitioning at any letter will be of no use . So we are starting partitioning 
    // with i+1(first operator) upto j-1(last operator) and we are incrementing k by 2 to reach next operator.
    for(int k = i+1 ; k <= j-1 ; k += 2)
    {
        int LT = Evaluate(s , i , k-1 , true); // ways to get true from left partition when we need true.
        int LF = Evaluate(s , i , k-1 , false); // ways to get false from left partition when we need false.
        int RT = Evaluate(s , k+1 , j , true); // ways to get true from right partition when we need true.
        int RF = Evaluate(s , i , k-1 , true); // ways to get false from right partition when we need false.

        // to get true from and of two expressions both expressions must be true.
        if(s[k] == '&')
        {
            if(isTrue == true)
                ans += LT * RT ;
            else
                ans += LF*RF + LF*RT + LT*RF;
        }

        // to get true from XOR of two expressions one expression must be true and one must be false.
        else if(s[k] == '^')
        {
            if(isTrue == true)
                ans += LF*RT + LT*RF;
            else
                ans += LT*RT + LF*RF;
        }

        // to get true from OR of two expressions , minimum one expression must be true.
        else if(s[k] == '|')
        {
            if(isTrue == true)
                ans += LT*RT + LT*RF + LF*RT ;
            else
                ans += LF*RF;
        }
    }
    return ans;
}

int main()
{
    string s;
    cin>>s;
    int n = s.size();
    int i = 0 , j = n-1 ;

    cout<<"Number of ways to evaluate the boolean expression true is "<<Evaluate(s , i , j , true);
}
