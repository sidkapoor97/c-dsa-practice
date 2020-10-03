#include<iostream>

using namespace std;

int main()
{
//	int var=5;
//	
//	int *ip = &var;
//	
//	cout<<"Value is "<<var<<endl;
//	cout<<"Address is "<<ip<<endl;
//	cout<<"Value is "<<*ip<<endl;
//	*ip=10;
//	cout<<"Value is "<<var<<endl;
//	cout<<"Address is "<<ip<<endl;
//	cout<<"Value is "<<*ip<<endl;

// Dynamic Memory Allocation - DMA
	int size;
	int *ptr;
		
	cout<<"Enter number of values to be stored"<<endl;
	cin>>size;
	
	ptr = new int[size];
	cout<<"Enter values to be stored"<<endl;
	for(int i=0;i<size;i++)
		cin>>ptr[i];
	cout<<"Values are"<<endl;
	for(int i=0;i<size;i++)
		cout<<ptr[i]<<" ";
	return 0;
}
