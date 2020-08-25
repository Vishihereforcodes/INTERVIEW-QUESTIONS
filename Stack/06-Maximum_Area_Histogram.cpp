/* https://leetcode.com/problems/largest-rectangle-in-histogram/

*/

#include<bits/stdc++.h>
using namespace std;

void NextSmallerToLeft(int *arr , int n , vector<int>&left)
{
    int pseudoIndex = -1 ;
    stack<pair<int,int>>s;
    for(int i = 0 ; i < n ; i++)
    {
        if(s.empty())
            left.push_back(pseudoIndex);
        
        else if(!s.empty() && s.top().first < arr[i])
            left.push_back(s.top().second);
        
        else if(!s.empty() && s.top().first >= arr[i])
        {
            while(!s.empty() && s.top().first >= arr[i])
            {
                s.pop();
            }
            
            if(s.empty())
                left.push_back(pseudoIndex);
            else
                left.push_back(s.top().second);
        }
        s.push(make_pair(arr[i] , i));
    }
}

void NextSmallerToRight(int *arr , int n , vector<int>&right)
{
    int pseudoIndex = n;
    stack<pair<int,int>>s;
    for(int i = n - 1 ; i >= 0 ; i--)
    {
        if(s.empty())
            right.push_back(pseudoIndex);
        
        else if(!s.empty() && s.top().first < arr[i])
            right.push_back(s.top().second);
        
        else if(!s.empty() && s.top().first >= arr[i])
        {
            while(!s.empty() && s.top().first >= arr[i])
            {
                s.pop();
            }
            
            if(s.empty())
                right.push_back(pseudoIndex);
            else
                right.push_back(s.top().second);
        }
        s.push(make_pair(arr[i] , i));
    }
    
    reverse(right.begin() , right.end());
}

int MaximumAreaHistogram(int *arr , int n)
{
    vector<int>left , right , width , area;
    NextSmallerToLeft(arr , n , left);
    NextSmallerToRight(arr , n , right);
    
    for(int i = 0 ; i < n ; i++)
    {
        width.push_back(right[i] - left[i] - 1);
    }

    for(int i = 0 ; i < n ; i++)
    {
        area.push_back(arr[i]*width[i]);
    }

    int maxArea = area[0];
    for(int i = 1 ; i < n ; i++)
    {
        if(area[i] > maxArea)
        {
            maxArea = area[i];
        }
    }
    return maxArea;

}

int main()
{
    int n ;
    cin>>n;
    int arr[n];
    for(int i = 0 ; i < n ; i++)
    {
        cin>>arr[i];
    }

    cout<<MaximumAreaHistogram(arr , n);
}
