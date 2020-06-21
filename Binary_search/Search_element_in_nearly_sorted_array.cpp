// Nearly sorted array is the array in which the element which supposed to be at ith position in sorted array may be present at i-1 or (i+1)th index also.

#include<iostream>
using namespace std;

int SearchingInNearlySortedArray(int *arr , int n , int num)
{
	int start = 0 , end  = n - 1 , mid ;
	 
	while(start <= end)
	{
		mid  = start + (end - start)/2 ;
		
		if(arr[mid] == num)
		    return mid ;
		
		else if(mid - 1 >= start && arr[mid-1] == num)
		    return mid - 1 ;
		
		else if(mid + 1 <= end && arr[mid+1] == num)
		    return mid + 1 ;
		
		else if(arr[mid] < num)
		    start = mid + 1 ;
		
		else
		    end = mid - 1 ; 
	}
	return -1 ;
}

int main()
{
	int n , num ;
	cout<<"Enter size of the array : "<<endl;
	cin>>n;
	
	cout<<"Enter the elements in nearly sorted array : "<<endl;
	int arr[n];
	
	for(int i=0;i<n;i++)
	cin>>arr[i];
	
	cout<<"Enter the element to search : "<<endl;
	cin>>num;
	
	cout<<"Index of searched element = "<< SearchingInNearlySortedArray(arr , n , num);	
}
