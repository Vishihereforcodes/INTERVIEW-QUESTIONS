// Question 2 :- Given a sorted array but we dont know its ascending or descendingly sorted  . We have to search an element.

#include<iostream>
using namespace std;

int OrderAgnosticSearch(int *arr , int n ,int num)
{
	int start = 0,end= n-1 ,mid;
	
	bool isAscending = arr[start] < arr[end] ; // to check array is ascending or descending .
	
	while(start<=end)
	{
		mid = start + (end-start)/2;
		if(num == arr[mid])
		    return mid;
		
		if(isAscending)
		{
			if(num > arr[mid])
		        start = mid + 1;
		    else
		        end = mid -1;
		}
		else
		{
			if(num < arr[mid])
		        start = mid + 1;
		    else
		        end = mid -1;
		}
		
	}
	return -1;
}
int main(){
	
	int n , num;
	cout<<"Enter size of the array : "<<endl;
	cin>>n;
	int arr[n];
	
	for(int i=0;i<n;i++)
	cin>>arr[i];
	
	cout<<"Enter the element to search : "<<endl;
	cin>>num;
	
	cout<<"Index of the searched element is = "<< OrderAgnosticSearch(arr , n ,num);
	
}
