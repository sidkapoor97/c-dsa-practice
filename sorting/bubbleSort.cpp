#include<iostream>

using namespace std;

void swap(int* a,int* b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
};

void bubbleSort(int arr[],int length)
{
	int i,j;
	
	for(int i=0;i<length;i++)
	{
		for(int j=0;j<length-1-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap(&arr[j],&arr[j+1]);
			}
		}
	}	
};

void printArray(int arr[], int length)
{	
	cout<<"The elements are->"<<endl;
	for(int i=0;i<length;i++)
	{
		cout<<arr[i]<<endl;
	}
};

int main()
{	
	int arrLen;
	cout<<"Enter the length of the array"<<endl;
	cin>>arrLen;
	int arr[arrLen];
	cout<<"Enter the elements"<<endl;
	for(int i=0;i<arrLen;i++)
	{
		cin>>arr[i];
	}
	
	cout<<"Original Array -> "<<endl;
	printArray(arr, arrLen);
	cout<<"Modified Array (Using bubble sort)-> "<<endl;
	bubbleSort(arr, arrLen);
	printArray(arr, arrLen);
	return 0;
}
