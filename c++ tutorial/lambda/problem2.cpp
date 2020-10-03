#include<iostream>
#include<vector>
#include<cstdlib>
#include<string>
#include<functional>

int main()
{   
    std::cout<<"How many FIbonacci? ";
    int num;
    std::cin>>num;
    std::vector<int> fibVec;
    // std::function<int(int)> Fib = [&Fib](int n){return n<2?n:Fib(n-1)+Fib(n-2);};
    std::function<int(int)> Fib = [&Fib](int n){return n<2?n:Fib(n-1)+Fib(n-2);};
    
    for(int i=1;i<=num;i++)
        fibVec.push_back(Fib(i));
    for(auto y: fibVec) std::cout<<y<<" ";

    std::cout<<"\n";
    return 0;
}