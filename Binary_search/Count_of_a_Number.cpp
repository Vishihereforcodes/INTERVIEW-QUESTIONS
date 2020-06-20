#include<iostream>
using namespace std;


int FirstOccurance(int *arr , int n ,int num)
{
	int start = 0,end= n-1 ,mid;
	int ans = -1;
	
	while(start<=end)
	{
		mid = start + (end-start)/2;
		if(num == arr[mid])
		{
			ans = mid;
			end = mid - 1 ;
		}
		else if(num > arr[mid])
		    start = mid + 1;
		else
		    end = mid -1;
	}
	return ans;
}

int LastOccurance(int *arr , int n ,int num)
{
	int start = 0,end= n-1 ,mid;
	int ans = -1 ;
	
	while(start<=end)
	{
		mid = start + (end-start)/2;
		
		if(num == arr[mid])
		{
		    ans = mid ;
		    start = mid +1 ;
		}
		else if(num > arr[mid])
		    start = mid + 1;
		else
		    end = mid -1;
	}
	return ans;
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
	
	cout<<"Count of "<<num<<" is = "<< LastOccurance(arr , n ,num) - FirstOccurance(arr , n ,num) + 1;
	
}
