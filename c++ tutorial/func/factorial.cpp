#include<cmath>
#include<iostream>

int GetFactorial(int);

int main()
{   
    std::cout<<GetFactorial(5)<<"\n";
    return 0;
}

int GetFactorial(int n)
{
    if(n<=1)
        return 1;
    else
        return n*GetFactorial(n-1);
}