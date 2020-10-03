#include<iostream>

using namespace std;

void merge(int arr[],int l,int m,int r)
{
	int i=l;
	int j=m+1;
	int k=l;
	
	int temp[r+1];
	
	while(i<=m && j<=r)
	{
		//left ele < right ele
		if(arr[i]<=arr[j])
		{
			temp[k]=arr[i];
			i++;
		}
		//right ele < left ele
		else
		{
			temp[k]=arr[j];
			j++;
		}
		k++;
	}
	
	while(i<=m)
	{	
		//right array is empty and left is entirely sorted
		temp[k]=arr[i];
		i++;
		k++;
	}
	
	while(j<=r)
	{	
		//left array is empty and right is entirely sorted
		temp[k]=arr[j];
		j++;
		k++;
	}
	
	//copy the temp array to the actual array
	for(int p=l;p<=r;p++)
	{
		arr[p]=temp[p];
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

void mergeSort(int arr[], int l, int r)
{
	if(l<r)
	{
		int m=(l+r)/2;
		mergeSort(arr ,l ,m );
		mergeSort(arr ,m+1 ,r );
		merge(arr,l,m,r);
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
	mergeSort(myArr, 0, arrLen-1);
	printArray(myArr, arrLen);
	return 0;
}
