/* https://leetcode.com/problems/maximal-rectangle/

*/

#include<bits/stdc++.h>
#define n 4 
#define m 4
using namespace std;

void NextSmallerToLeft(vector<int>v , vector<int>&left)
{
    int pseudoIndex = -1 ;
    stack<pair<int,int>>s;
    for(int i = 0 ; i < v.size() ; i++)
    {
        if(s.empty())
            left.push_back(pseudoIndex);
        
        else if(!s.empty() && s.top().first < v[i])
            left.push_back(s.top().second);
        
        else if(!s.empty() && s.top().first >= v[i])
        {
            while(!s.empty() && s.top().first >= v[i])
            {
                s.pop();
            }
            
            if(s.empty())
                left.push_back(pseudoIndex);
            else
                left.push_back(s.top().second);
        }
        s.push(make_pair(v[i] , i));
    }
}

void NextSmallerToRight(vector<int>v , vector<int>&right)
{
    int pseudoIndex = n;
    stack<pair<int,int>>s;
    for(int i = v.size() - 1 ; i >= 0 ; i--)
    {
        if(s.empty())
            right.push_back(pseudoIndex);
        
        else if(!s.empty() && s.top().first < v[i])
            right.push_back(s.top().second);
        
        else if(!s.empty() && s.top().first >= v[i])
        {
            while(!s.empty() && s.top().first >= v[i])
            {
                s.pop();
            }
            
            if(s.empty())
                right.push_back(pseudoIndex);
            else
                right.push_back(s.top().second);
        }
        s.push(make_pair(v[i] , i));
    }
    
    reverse(right.begin() , right.end());
}

int MaximumAreaHistogram(vector<int>v)
{
    vector<int>left , right , width , area;
    NextSmallerToLeft(v , left);
    NextSmallerToRight(v , right);
    
    for(int i = 0 ; i < v.size() ; i++)
    {
        width.push_back(right[i] - left[i] - 1);
    }

    for(int i = 0 ; i < v.size() ; i++)
    {
        area.push_back(v[i]*width[i]);
    }

    int maxArea = area[0];
    for(int i = 1 ; i < v.size() ; i++)
    {
        if(area[i] > maxArea)
        {
            maxArea = area[i];
        }
    }
    return maxArea;

}

int MaxAreaRectangleInBinaryMatrix(int arr[n][m])
{
    vector<int>v;

    for(int j = 0 ; j < m ; j++)
    {
        v.push_back(arr[0][j]);
    }

    int MaximumArea = MaximumAreaHistogram(v );

    for(int i = 1 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            if(arr[i][j] == 0)
            {
                v[j] = 0;
            }

            else
            {
                v[j] += arr[i][j];
            }
        }
        MaximumArea = max(MaximumArea , MaximumAreaHistogram(v));
    }
    return MaximumArea;
}

int main()
{
    int arr[n][m];
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            cin>>arr[i][j];
        }
    }

    cout<<MaxAreaRectangleInBinaryMatrix(arr);
}
