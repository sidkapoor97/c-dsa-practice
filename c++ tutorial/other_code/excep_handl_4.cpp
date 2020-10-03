#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include<ctime>

std::vector<int> Range(int start,int end, int increment);

void DrawPineTree(int size);

int main()
{	
	
	srand(time(NULL));
    int secretNum = std::rand() % 11;
    int guess = -1;
    while (secretNum!=guess)
    {
        std::cout<<"Guess the number: ";
        std::cin>>guess;

        if(guess>secretNum) std::cout<<"Too Big\n";
        if(guess<secretNum) std::cout<<"Too Small\n";
    }
    
    
    std::cout<<"You guessed it!!"<<"\n";
    
	return 0;
}

std::vector<int> Range(int start,int end, int increment)
{
	std::vector<int> vector;
	
	for(int i=start;i<=end;i+=increment)
		vector.push_back(i);
	return vector;
};

void DrawPineTree(int size)
{
    for(int i=size-1;i>=0;i--)
    {
        for (int k = i; k >=0; k--)
            std::cout<<" ";
        
        for(int j=2*size-1-2*i;j>=1;j--)
            std::cout<<"#";
        std::cout<<"\n";
    }

    for(int i=0;i<size;i++)
        std::cout<<" ";
    std::cout<<"#\n";
};

