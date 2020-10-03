#include<iostream>
#include<random>
#include<vector>
#include<cstdlib>
#include<ctime>

std::vector<int> GenerateRandomVector(int, int, int);

int main()
{       
    int start, end, length;
    std::cout<<"Enter length, start and end: ";
    std::cin>>length>>start>>end;
    std::vector<int> vecVals = GenerateRandomVector(length, start, end);

    for(auto y: vecVals) std::cout<<y<<" ";
    std::cout<<"\n";
    return 0;
}

std::vector<int> GenerateRandomVector(int length, int start, int end)
{
    srand(time(NULL));
    std::vector<int> randVector;
    while(length!=0)
    {
        randVector.push_back(rand()%(end-start+1) + start);
        length-=1;
    }

    return randVector;
}