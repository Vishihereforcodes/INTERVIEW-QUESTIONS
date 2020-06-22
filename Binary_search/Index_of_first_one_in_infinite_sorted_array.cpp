#include<iostream>
using namespace std;

int FirstOccurance(int *arr ,int start , int end , int num)
{
	while(start <= end)
	{
		mid = start + (end - start)/2 ;
		
		if(arr[mid] == num) 
		{	
		    ans = mid ;
		    end = mid - 1;
		}
		
		else if(arr[mid] > num)
			end = mid - 1 ;
		
		else
			start = mid + 1 ;
	}
	return ans ;
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

