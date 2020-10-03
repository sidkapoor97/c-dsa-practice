#include<cstdlib>
#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<cmath>
#include<ctime>
#include<algorithm>

std::vector<int> GenerateRandVector(int, int, int);

int main()
{      
    // ask for input
    int length, start, end;
    std::cout<<"Enter len, start, end of the random vector\n";
    std::cin>>length>>start>>end;

    //random vector generated
    std::vector<int> randVector = GenerateRandVector(length, start, end);
    std::cout<<"\nOriginal Vector\n";
    for(auto y: randVector) std::cout<<y<<" ";
    std::cout<<"\n";
    int divisor;
    std::cout<<"Enter a divisor: ";
    std::cin>>divisor;
    std::vector<int> divVecVals;
    std::copy_if(randVector.begin(), randVector.end(), std::back_inserter(divVecVals), [divisor](int x){return (x%divisor==0);});
    for(auto y: divVecVals) std::cout<<y<<" ";


    // for(auto y:evenVecValues) std::cout<<y<<" ";
    return 0;
}

std::vector<int> GenerateRandVector(int length, int start, int end)
{
    srand(time(NULL));
    std::vector<int> randVector;
    while(length>0)
    {
        randVector.push_back(rand()%(end-start+1)+start);
        length--;
    }
    return randVector;
}