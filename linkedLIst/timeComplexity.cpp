#include<iostream>

using namespace std;

//algo1

void sumOfNumbers1(double n)
{
	double sum=0;
	for(double i=1;i<=n;i++)
	{
		sum+=i;
	}
	
	cout<<"Method 1: Sum of "<<n<<" numbers is "<<sum<<endl;
}

void sumOfNumbers2(double n)
{
	double sum=(n*(n+1))/2;
	cout<<"Method 2: Sum of "<<n<<" numbers is "<<sum<<endl;
}

int main()
{
	double num;
	cout<<"Enter N: "<<endl;
	cin>>num;
	
	sumOfNumbers2(num);
	
	return 0;
}
