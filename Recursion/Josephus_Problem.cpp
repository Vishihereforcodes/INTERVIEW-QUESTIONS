/*
Question:- There are n number of soldiers standing in a circle . As they are less in number and are not able to faught with the opposing soldiers . So,
they decided to kill (n-1) soldiers one by one by counting k soldiers . Everytime soldier at kth position is to be killed. Atlast , only one soldier will left.
We have to return the position of that soldier (as he has to commit suicide :P) .

Approach:-
1. Base case:- when we will have only one soldier in our vector then we will return its position as vector is storing positions of the soldiers.
2. Otherwise , we simply delete a soldier at (index + k)th position from vector as we initialised index with 0 . Modulo is to prevent going out of bound.
3. Then ,  recursively delete all n-1 soldiers and return the ans atlast.

*/

#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>v , int k , int index , int &ans)
{
	if(v.size() == 1)
	{
		ans = v[0];
		return ;
	}
	
	index = (index + k) % v.size();
	v.erase(v.begin() + index);
	solve(v , k , index , ans);
}

int main()
{
	int n , k ;
	cout<<"Enter the number of soldiers present in the army:-"<<endl;
	cin>>n;
	cout<<"Enter the count of soldiers, soldier at which is to be killed everytime:-"<<endl;
	cin>>k;
	vector<int>v;
	for(int i = 1 ; i <= n ; i++)
		v.push_back(i);
	k--;
	// As , k is the position of the person to be killed , so to convert that position into index of the vector we did k--.
	int index = 0 , ans = 0;
	solve(v , k , index , ans);
	cout<<"Position of the soldier who has to commit suicide as he is the only one left:- " << endl<<ans ; 
}
