#include<iostream>

void isPrime(int);

int main()
{   
    std::cout<<"Enter n: ";
    int n,maxPrime;
    std::cin>>n;
    isPrime(n);
    std::cout<<"Generate primes upto: ";
    std::cin>>maxPrime;
    for(int i =2;i<=maxPrime;i++)
    {
        bool flag=true;
        for(int j=2;j<=i/2;j++)
            if(i%j==0)
                flag=false;
        if(flag)
            std::cout<<i<<" is prime\n";
    };

    return 0;
};
void isPrime(int n)
{   
    bool flag;
    for(int i =2;i<=n/2;i++)
    {
        flag=true;
        for(int j=2;j<=i/2;j++)
            if(i%j==0)
                flag=false;
    };
    if(flag)
        std::cout<<n<<" is prime\n";
    else
    {
        std::cout<<n<<" is not prime\n";
    }
    
}