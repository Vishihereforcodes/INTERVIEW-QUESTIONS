// Question:- You have to generate all the balanced parentheses with '(' and ')' .

/*
Approach:-
1. Base case:- We will get a balanced parentheses everytime when count of opening and closing parentheses becomes zero.
2. Otherwise, we can always push opening parentheses to our output until its zero.
3. But if our opening parentheses count is less than the closing count then we can include it in our output to make it balanced.
*/

void solve(int open , int close , string op , vector<string>&v)
{
	if(open == 0 && close == 0) 
	{
		v.push_back(op);
		return ;
	}
	
	if(open != 0)
	{
		solve(open-1 , close , op + '(' , v);
	}
	
	if(close > open)
	{
		solve(open , close-1 , op + ')' , v);
	}
}

vector<string> BalancedParentheses(int n)
{
	vector<string>v;
	int open = n , close = n ;
	string op = "" ;
	solve(open , close , op , v);
	return v;
}
