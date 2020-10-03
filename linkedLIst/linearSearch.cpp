#include<iostream>
using namespace std;

void linearSearch(int a[], int n,int arrLen)
{	
	int temp=-1;
	
	for(int i=0;i<arrLen;i++)
	{
		if(a[i]==n)
		{
			cout<<"Element found at position: "<<i+1<<endl;
			temp=0;
			break;
		}
	}
	if(temp==-1)
	{
		cout<<"No element found"<<endl;
	}
}


int main()
{		
	int arrLen;
	cout<<"Enter the length of the array"<<endl;
	cin>>arrLen;
	int arr[arrLen];
	cout<<"Enter the elements one by one"<<endl;
	for(int i=0;i<arrLen;i++)
	{
		cin>>arr[i];
	}
	cout<<"please enter an element to search"<<endl;
	int num;
	cin>>num;
	linearSearch(arr, num, arrLen);
	return 0;
}
