#include<iostream>

using namespace std;

int binarySearch(int arr[], int left, int right, int key)
{	
	int mid;
	while(left<=right)
	{
		mid = left + (right-left)/2;
		if(arr[mid]==key)
		{
			return mid;
		}
		else if(arr[mid]<key)
		{
			left=mid+1;
		}
		else
		{
			right=mid-1;
		}
	}
	return -1;
}
int main()
{	
	int arrLen;
	cout<<"Enter the number of elements"<<endl;
	cin>>arrLen;
	int arr[arrLen];
	cout<<"Enter the elements"<<endl;
	for(int i=0;i<arrLen;i++)
	{
		cin>>arr[i];
	}
	int key;
	int left=0;
	int right=arrLen-1;
	
	cout<<"Enter key"<<endl;
	cin>>key;
	int index = binarySearch(arr, left, right, key);
	
	if(index == -1)
	{
		cout<<"No match found"<<endl;
	}
	else
	{
		cout<<"index of key -> "<<index<<endl;	
	}
	return 0;
}
