#include<iostream>
using namespace std;

int binarySearchInDecreasingSortedArray(int *arr , int n ,int num)
{
	int start = 0,end= n-1 ,mid;
	
	while(start<=end)
	{
		mid = start + (end-start)/2;
		if(num == arr[mid])
		    return mid;
		else if(num < arr[mid])
		    start = mid + 1;
		else
		    end = mid -1;
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
	
	cout<<"Index of the searched element is = "<< binarySearchInDecreasingSortedArray(arr , n ,num);
	
}
