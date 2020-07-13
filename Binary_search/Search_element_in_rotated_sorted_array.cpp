// arrays present in left of minimum element and right of minimum element are sorted. 
// so finding index of minimum element and then searching in its left and right
#include<iostream>
using namespace std;

int IndexOfMinElement(int *arr , int n)
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
		
		else if(arr[mid] >= arr[start]) // checking for minimum element in unsorted part of array.
		    start = mid + 1 ;
		
		else if(arr[mid] <= arr[end])
		    end = mid -1 ;
	}
}

int BinarySearch(int *arr , int start ,int end , int num , int n)
{
	while(start <= end)
	{
		int mid = start + (end - start)/2 ;
		
		if(arr[mid] == num)
		    return mid ;
		else if(arr[mid] > num)
		    end = mid - 1 ;
		else
		    start = mid + 1 ;
	}
	return -1 ;
}
int main()
{
	int n , num , minIndex , ans1 , ans2 ;
	cout<<"Enter size of the array : "<<endl;
	cin>>n;
	
	cout<<"Enter the elements of rotated sorted array : "<<endl;
	int arr[n];
	
	for(int i=0;i<n;i++)
	cin>>arr[i];
	
	cout<<"Enter the element to search : "<<endl;
	cin>>num;
	
	minIndex = IndexOfMinElement(arr , n) ;
	ans1 = BinarySearch(arr , 0 , minIndex - 1 , num , n);
	ans2 = BinarySearch(arr , minIndex , n - 1 , num , n) ;
	
	if ( ans1 > -1)
	cout<<"Index of searched element = "<< ans1;
	else if(ans2 > -1)
	cout<<"Index of searched element = "<< ans2;
	
}
