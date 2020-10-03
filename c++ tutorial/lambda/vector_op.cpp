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
    // int length, start, end;
    // std::cout<<"Enter len, start, end of the random vector\n";
    // std::cin>>length>>start>>end;

    //random vector generated
    // std::vector<int> randVector = GenerateRandVector(length, start, end);
    // std::cout<<"\nOriginal Vector\n";
    // for(auto y: randVector) std::cout<<y<<" ";
    // std::cout<<"\n";

    std::vector<int> vec1={1,2,3,4,5};
    std::vector<int> vec2={5,4,3,2,1};
    std::vector<int> vec3(5);

    std::transform(vec1.begin(), vec1.end(), vec2.begin(), vec3.begin(), [](int x, int y){return x+y;});

    for(auto y: vec3) std::cout<<y<<" ";


    


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