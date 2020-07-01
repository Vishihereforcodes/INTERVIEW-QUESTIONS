//as we can't search an element in an infinite array so we will reduce our search space. 
#include<iostream>
using namespace std;

int BinarySearch(int *arr ,int start , int end , int num)
{
	while(start <= end)
	{
		mid = start + (end - start)/2 ;
		
		if(arr[mid] == num) 
			return mid ;
		
		else if(arr[mid] > num){
			end = mid - 1 ;
		}
		
		else
			start = mid + 1 ;
	}
	return -1 ;
}

int ReducingInfiniteArray(int *arr , int num)
{
    int start = 0, end = 1;
	
	while(num > arr[end])
	{
		start = end ;
		end *= 2 ;
	}	
	return {start , end }; // Now these start and end values will be used to find the element.
}

