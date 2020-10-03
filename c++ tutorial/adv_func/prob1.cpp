#include<vector>
#include<functional>
#include<iostream>
#include<cmath>

std::vector<int> ChangeList(std::vector<int> listNum, std::function<bool(int)>);
bool IsItOdd(int);

int main()
{   
    std::vector<int> listOfNums {1,2,3,4,5};
    std::vector<int> OddNums = ChangeList(listOfNums, IsItOdd);
    for(auto y: OddNums) std::cout<<y<<" ";
    std::cout<<"\n";
    return 0;
}

std::vector<int> ChangeList(std::vector<int> listOfNums, std::function<bool(int)> IsItOdd)
{
    std::vector<int> OddList;
    for(int i=0; i<listOfNums.size() ;i++)
    {
        if(IsItOdd(listOfNums[i]))
            OddList.push_back(listOfNums[i]);
    }
    return OddList;
}

std::vector<int> OddList(std::vector<int> listNum)
{
    std::vector<int> oddList;
    for(int i=0;i<listNum.size();i++)
    {
        if(listNum[i]%2==1)
            oddList.push_back(listNum[i]);
    }
    return oddList;
};

bool IsItOdd(int n)
{
    return n%2;
}