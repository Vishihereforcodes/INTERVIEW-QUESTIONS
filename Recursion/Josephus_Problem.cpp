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
