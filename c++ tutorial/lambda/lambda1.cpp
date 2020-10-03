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
    int length, start, end;
    std::cout<<"Enter len, start, end of the random vector\n";
    std::cin>>length>>start>>end;
    std::vector<int> randVector = GenerateRandVector(length, start, end);
    std::cout<<"\nOriginal Vector\n";
    for(auto y: randVector) std::cout<<y<<" ";
    std::cout<<"\nSorted Vector\n";
    std::sort(randVector.begin(), randVector.end(), [](int x, int y){return x<y;});
    for(auto y:randVector) std::cout<<y<<" ";
    std::cout<<"\n";
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