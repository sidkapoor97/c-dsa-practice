#include<iostream>

using namespace std;

//elements are shifted and not swapped
void insertionSort(int arr[], int length)
{	
	int key, j;
	for(int i=1;i<length;i++)
	{
		key=arr[i];
		j=i-1;
		while(j>=0 && arr[j]>key)
		{
			arr[j+1]=arr[j];
			j--;
		}
		
		arr[j+1]=key;
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
	int arr[arrLen];
	cout<<"Enter the elements"<<endl;
	for(int i=0;i<arrLen;i++)
	{
		cin>>arr[i];
	}
	
	cout<<"Original Array -> "<<endl;
	printArray(arr, arrLen);
	cout<<"Sorted Array (Using insertion sort)-> "<<endl;
	insertionSort(arr, arrLen);
	printArray(arr, arrLen);
	return 0;
}
