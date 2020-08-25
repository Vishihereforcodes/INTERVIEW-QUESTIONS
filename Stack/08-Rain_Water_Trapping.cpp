/* https://leetcode.com/problems/trapping-rain-water/

*/
#include<bits/stdc++.h>
using namespace std;

int MaximumRainWaterTrapped(int *height , int n)
{
    int maxHeightLeft[n] , maxHeightRight[n] , water[n];

    maxHeightLeft[0] = height[0];
    for(int i = 1 ; i < n ; i++)
    {
        maxHeightLeft[i] = max(maxHeightLeft[i-1] , height[i]);
    }

    maxHeightRight[n-1] = height[n-1];
    for(int i = n - 2 ; i >= 0 ; i--)
    {
        maxHeightRight[i] = max(maxHeightRight[i+1] , height[i]);
    }

    for(int i = 0 ; i < n ; i++)
    {
        water[i] = min(maxHeightLeft[i] , maxHeightRight[i]) - height[i];
    }

    int sum = 0 ; 
    for(int  i = 0 ; i < n ; i++)
    {
        sum += water[i];
    }
    return sum;
}

int main()
{
    int n ; 
    cout<<"Enter the number of buildings : "<<endl;
    cin>>n;
    int height[n];
    cout<<"Enter the height of the buildings : "<<endl;
    for(int i = 0 ; i < n ; i++)
    {
        cin>>height[i];
    }

    cout<<"Maximum area of trapped water = " << MaximumRainWaterTrapped(height , n);
}
