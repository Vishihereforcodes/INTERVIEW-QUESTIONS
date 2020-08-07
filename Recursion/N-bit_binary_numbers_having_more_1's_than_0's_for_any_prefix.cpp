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
