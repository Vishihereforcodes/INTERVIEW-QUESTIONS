// Floor value of a number is the greatest number smaller than that number in case of integers.

#include<iostream>
using namespace std;

int FloorValue(int *arr , int n , int num)
{
	int start = 0 ,end = n - 1 , mid , result;
	
	while(start <= end)
	{
		mid = start + (end - start)/2 ;
		
		if(arr[mid] == num) // if element is present in array then it is floor value of itself.
		    return mid ;
		
		else if(arr[mid] < num)
		{
			result = mid ;
			start = mid + 1 ; 
		}
		
		else
		    end = mid - 1 ;
	}
	return result ;
}


int main()
{
	int n , num ;
	cout<<"Enter size of the array : "<<endl;
	cin>>n;
	
	cout<<"Enter the elements of sorted array : "<<endl;
	int arr[n];
	
	for(int i=0;i<n;i++)
	cin>>arr[i];
	
	cout<<"Enter the element whose floor value is to be find : "<<endl;
	cin>>num;
	
	cout<<"Floor value of searched element = "<< FloorValue(arr , n , num);	
}
