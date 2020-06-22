#include<iostream>
using namespace std;

char NextAlphabet(char *arr , int n , int num)
{
	int start = 0 , end = n - 1 , mid ;
	char result;
	
	while(start <= end)
	{
		mid = start + (end - start)/2 ;
		
		if(arr[mid] == num)
			start = mid + 1 ;
		
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
	int n ;
	char num ;
	cout<<"Enter size of the array : "<<endl;
	cin>>n;
	
	cout<<"Enter the elements of sorted character array : "<<endl;
	char arr[n];
	
	for(int i=0;i<n;i++)
	cin>>arr[i];
	
	cout<<"Enter the element whose next character is to be find : "<<endl;
	cin>>num;
	
	cout<<"Next alphabet of entered character = "<< NextAlphabet(arr , n , num);	
}
