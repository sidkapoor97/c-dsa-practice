#include<iostream>

using namespace std;

void swap(int* a,int* b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
};

int partition(int arr[],int s,int e)
{
	int pivot=arr[e];
	int pIndex=s;
	
	for(int i=s;i<e;i++)
	{
		if(arr[i]<=pivot)
		{
			swap(&arr[pIndex],&arr[i]);
			pIndex++;
		}
	}
	
	swap(arr[e], arr[pIndex]);
	
	return pIndex;
};

void quickSort(int arr[],int s,int e)
{
	if(s<e)
	{
		int p=partition(arr,s,e);
		quickSort(arr,s,p-1);
		quickSort(arr,p+1,e);
	}
}



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
	int myArr[arrLen];
	cout<<"Enter the elements"<<endl;
	for(int i=0;i<arrLen;i++)
	{
		cin>>myArr[i];
	}
	
	cout<<"Original Array -> "<<endl;
	printArray(myArr, arrLen);
	cout<<"Modified Array using merge sort-> "<<endl;
	quickSort(myArr, 0, arrLen-1);
	printArray(myArr, arrLen);
	return 0;
}
