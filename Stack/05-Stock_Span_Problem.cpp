/*
    First solve this Question [Nearest Greater to Left](https://github.com/urvashi-code1255/INTERVIEW-QUESTIONS/blob/master/Stack/02-Nearest_Greater_to_Left.cpp)
    
    [Online Stock Span](https://leetcode.com/problems/online-stock-span/)
    
    How to do ?
    
    Just find index of Nearest Greater to Left.Then simply minus index of NGL from indexes of output array.
*/
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
        
        else if(s.top().first > arr[i])
            v.push_back(s.top().second);
        
        else if(s.top().first <= arr[i])
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

/**************************************************************************************************************************************************************************/

class StockSpanner {
    stack<pair<int,int>> s;
    int c;
public:
    StockSpanner() {
        s.push({9999999,0});
        c=1;
    }
    
    int next(int price) {
        int ans;
        
        while(!s.empty() && s.top().first<=price)
            s.pop();
        
        ans = currentIndex - s.top().second;// s.top().second == index of NGL
        
        s.push({price,currentIndex++});
        return ans;
    }
};
