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

    /*
    //print modified vector
    std::vector<int> evenVecValues;
    std::copy_if(randVector.begin(),randVector.end(), std::back_inserter(evenVecValues),[](int x){return (x%2==0);});
    std::cout<<"\nModified Vector\n";
    */

   //sum of every element
   int sum=0;
   int product=1;
    std::for_each(randVector.begin(), randVector.end(), [&](int x){return sum+=x;});
    std::for_each(randVector.begin(), randVector.end(), [&](int x){return product*=x;});

    // for(auto y:evenVecValues) std::cout<<y<<" ";
    std::cout<<"\nSUM = "<<sum<<"\n";
    std::cout<<"\nProduct = "<<product<<"\n";
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