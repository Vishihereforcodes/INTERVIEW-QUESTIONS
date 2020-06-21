#include<iostream>
using namespace std;

int Count(int *arr , int n)
{
	int start = 0 , end = n - 1 , mid ;
	
	while(start <= end)
	{
		if(arr[start] <= arr[end]) // already sorted.
		    return start;
		    
		mid = start + (end - start)/2 ;
		int prev = (mid + n - 1) % n ; // to avoid going out of bound.
		int next = (mid + 1) % n ;
		
		if(arr[mid] <= arr[prev] && arr[mid] <= arr[next]) // check if its a pivot.
		    return mid ;
		
		else if(arr[mid] >= arr[start]) // checking for unsorted part of array.
		    start = mid + 1 ;
		
		else if(arr[mid] <= arr[end])
		    end = mid -1 ;
	}
}

int main()
{
	int n ;
	cout<<"Enter size of the array : "<<endl;
	cin>>n;
	
	cout<<"Enter the elements of rotated sorted array : "<<endl;
	int arr[n];
	
	for(int i=0;i<n;i++)
	cin>>arr[i];
	
	cout<<"Number of times the array is rotated is = "<< Count(arr , n);
}
