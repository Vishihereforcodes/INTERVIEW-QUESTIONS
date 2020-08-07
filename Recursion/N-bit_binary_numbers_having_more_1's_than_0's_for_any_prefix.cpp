// Question:- Print all N-bit binary numbers having more 1's than 0's for any prefix.

/*
Approach:-
1. Base case:- whenever our input size becomes zero we get a binary number satisfying our conditions.
2. Otherwise , we can add 1 anytime in our output binary number until we reach its size.
3. But , we can add 0 in our output binary number only when we have already more ones in our binary number than zeroes.
*/

#include<bits/stdc++.h>
using namespace std;

void solve(int ones , int zeroes , int n , string op)
{
	if(n == 0)
	{
		cout<<op<<" ";
		return ;
	}
	
	string op1 = op ;
	op1 += '1';
	solve(ones + 1 , zeroes , n-1 , op1 );
	
	if(ones > zeroes)
	{
		string op2 = op;
		op2 += '0';
		solve(ones , zeroes+1 , n-1 , op2);
	}
}
int main()
{
	int n;
	cout<<"Enter the length of binary numbers:-"<<endl;
	cin>>n;
	string op = "";
	int ones = 0 , zeroes = 0 ;
	solve(ones , zeroes , n , op);
}
