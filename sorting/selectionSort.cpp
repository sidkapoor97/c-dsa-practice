#include<iostream>

using namespace std;

void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

//elements are swapped
void selectionSort(int arr[], int length)
{		
	int min;
	for(int i=0;i<length-1;i++)
	{	
		min=i;
		for(int j=i+1;j<length;j++)
		{	
			//< -> ASC, > -> DESC
			if(arr[j]<arr[i])
			{
				min=j;
			}
		}
		if(min!=i)
		{
			swap(arr[min],arr[i]);
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
	cout<<"Modified Array -> "<<endl;
	selectionSort(arr, arrLen);
	printArray(arr, arrLen);
	return 0;
}
