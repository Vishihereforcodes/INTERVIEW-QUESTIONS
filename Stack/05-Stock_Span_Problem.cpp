#include<bits/stdc++.h>
using namespace std;

void StockSpan(int *arr , int n)
{
    vector<int>v;
    stack<pair<int,int>>s;
    for(int i = 0 ; i < n ; i++)
    {
        if(s.empty())
            v.push_back(-1);
        
        else if(!s.empty() && s.top().first > arr[i])
            v.push_back(s.top().second);
        
        else if(!s.empty() && s.top().first <= arr[i])
        {
            while(!s.empty() && s.top().first <= arr[i])
            {
                s.pop();
            }
            
            if(s.empty())
                v.push_back(-1);
            else
                v.push_back(s.top().second);
    }
    s.push(make_pair(arr[i] , i));
    }
    
    for(int i = 0 ; i < v.size() ; i++)
    {
        v[i] = i - v[i];
    }

    for(auto i : v)
    cout<<i<<" ";
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0 ; i < n ; i++)
    cin>>arr[i];

    StockSpan(arr , n);

}
