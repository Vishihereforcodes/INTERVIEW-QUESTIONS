#include<bits/stdc++.h>
using namespace std;

int Cost(int *arr , int i , int j)
{
    if(i >= j)
        return 0;
    
    int Minimum = INT_MAX;

    for(int k = i ; k <= j-1 ; k++)
    {
        int tempAns = Cost(arr , i , k) + Cost(arr , k+1 , j) + arr[i-1]*arr[k]*arr[j];

        if(tempAns < Minimum)
            Minimum = tempAns;
    }
    return Minimum;
    
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    // order of matrix at index i will be arr[i-1]*arr[i].
    for(int i = 0 ; i < n ; i++)
    {
        cin>>arr[i];
    }
    int i = 1 , j = n-1 ;
    cout<<"Minimum cost of matrix chain multiplication is "<<Cost(arr , i , j);
}
