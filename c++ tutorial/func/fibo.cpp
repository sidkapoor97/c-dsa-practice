#include<iostream>

int PrintFibo(int);

int main()
{   
    std::cout<<"Enter fibo till: ";
    int num;
    std::cin>>num;
    int a=1,b=1;
    std::cout<<a<<" ";
    while(b<num)
    {   
        std::cout<<b<<" ";
        b=a+b;
        a=b-a;
    }
    std::cout<<"\n";
    std::cout<<"Fibo Using Recursion, nth Fibo term: "<<PrintFibo(num)<<"\n";
    return 0;
};

int PrintFibo(int n)
{
    if(n<2)
        return n;
    else
        return PrintFibo(n-2) + PrintFibo(n-1);
};
