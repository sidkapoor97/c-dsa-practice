#include<vector>
#include<iostream>
#include<ctime>

std::vector<char> GetHAndTList(std::vector<char>,int);
int GetNumberOfMatches(std::vector<char>,char);

int main()
{   
    std::vector<char> possibleValues{'H','T'};
    std::vector<char> hAndTList = GetHAndTList(possibleValues, 100);
    std::cout<<"Num of Heads: "<<GetNumberOfMatches(hAndTList,'H')<<"\n";
    std::cout<<"Num of Tails: "<<GetNumberOfMatches(hAndTList,'T')<<"\n";
    return 0;
}

std::vector<char> GetHAndTList(std::vector<char> possibleValues,int numberValuesToGen)
{
    srand(time(NULL));
    std::vector<char> hAndTList;
    for(int i=0;i<numberValuesToGen;i++)
    {
        int randIndex = rand()%2;
        hAndTList.push_back(possibleValues[randIndex]);
    }
    return hAndTList;
};

int GetNumberOfMatches(std::vector<char> list, char valToFind)
{
    int numOfMatches=0;
    for(char c:list)
    {
        if(c==valToFind)
            numOfMatches++;
    }
    return numOfMatches;
}