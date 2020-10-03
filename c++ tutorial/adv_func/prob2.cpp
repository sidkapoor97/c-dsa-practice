#include<vector>
#include<iostream>
#include<ctime>

int main()
{   
    srand(time(NULL));   
    int count=1000;
    int headCount=0,tailCount=0;
    for(int i=0;i<count;i++)
    {
        if(rand()%2)
            headCount++;
        else
            tailCount++;
    }

    std::cout<<"Num of heads: "<<headCount<<"\n";
    std::cout<<"Num of tails: "<<tailCount<<"\n";
    std::cout<<"\n";
    return 0;
}