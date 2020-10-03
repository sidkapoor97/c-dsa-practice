#include<iostream>
#include<string>
#include<vector>
#include<sstream>

void SolveForX(std::string);
std::vector<std::string> StringVector(std::string theString, char separator);


int main()
{   
    std::cout<<"Enter an equation to solve ";
    std::string equation;
    getline(std::cin, equation);
    SolveForX(equation);
    return 0;
};

std::vector<std::string> StringVector(std::string theString, char separator)
{
    std::vector<std::string> strVector;
    std::stringstream ss(theString);
    std::string sIndivStr;
    while(getline(ss,sIndivStr,separator))
    {
        strVector.push_back(sIndivStr);
    }
    return strVector;
};

void SolveForX(std::string equation)
{
    std::vector<std::string> vecEquation = StringVector(equation, ' ');
    int num1 = std::stoi(vecEquation[2]);
    int num2 = std::stoi(vecEquation[4]);
    int xVal = num2 - num1;
    std::cout<<"x = "<<xVal<<"\n";
};