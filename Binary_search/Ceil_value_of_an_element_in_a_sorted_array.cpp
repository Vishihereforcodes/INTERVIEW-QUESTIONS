// Ceil value of a number is the smallest number greater than that number in case of integers.

#include<iostream>
using namespace std;

int CeilValue(int *arr , int n , int num)
{
	int start = 0 , end = n - 1 , mid , result;
	
	while(start <= end)
	{
		mid = start + (end - start)/2 ;
		
		if(arr[mid] == num) // if element is present in array then it is ceil value of itself.
			return arr[mid] ;
		
		else if(arr[mid] > num){
			result = arr[mid];
			end = mid - 1 ;
		}
		
		else
			start = mid + 1 ;
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
	
	cout<<"Enter the element whose ceil value is to be find : "<<endl;
	cin>>num;
	
	cout<<"Ceil value of searched element = "<< CeilValue(arr , n , num);	
}
