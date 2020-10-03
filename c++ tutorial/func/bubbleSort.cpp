#include<iostream>
#include<random>
#include<vector>
#include<cstdlib>
#include<ctime>

std::vector<int> GenerateRandomVector(int, int, int);

void BubbleSort(std::vector<int>& theVec);

int main()
{       
    int start, end, length;
    std::cout<<"Enter length, start and end: ";
    std::cin>>length>>start>>end;
    std::vector<int> vecVals = GenerateRandomVector(length, start, end);

    std::cout<<"\nUnsorted pseudo-random vector\n";
    for(auto y: vecVals) std::cout<<y<<" ";
    std::cout<<"\nAfter Sorting\n";
    BubbleSort(vecVals);
    for(auto y: vecVals) std::cout<<y<<" ";
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
};

void BubbleSort(std::vector<int>& theVec)
{
    int i = theVec.size() - 1;
    while ( i>=1 )
    {
        int j=0;
        while(j<i)
        {
            if(theVec[j]>=theVec[j+1])
                {
                    int temp=theVec[j];
                    theVec[j]=theVec[j+1];
                    theVec[j+1]=temp;
                }
            j++;
        }
        i--;
    }
}