#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<cstdlib>
#include<cstring>

float SolveForX(std::string);

int main()
{   
    std::cout<<"Enter an equation to solve ";
    std::string equation;
    getline(std::cin, equation);
    float ans = SolveForX(equation);
    std::cout<<"The value of x is: "<<ans<<"\n";
    return 0;
};

float SolveForX(std::string equation)
{
    std::stringstream ss(equation);
    std::string indivOp;
    std::vector<std::string> vecOp;
    float result = 0;
    char cSpace = ' ';
    while(getline(ss,indivOp,cSpace))
    {
        vecOp.push_back(indivOp);
    }
    if(isalpha(vecOp[0][0]) && !isalpha(vecOp[1][0]))
    {
        if(vecOp[1][0]=='+')
            result = std::stof(vecOp[4]) - std::stof(vecOp[2]);
        else if(vecOp[1][0]=='-')
            result = std::stof(vecOp[4]) + std::stof(vecOp[2]);
        else if(vecOp[1][0]=='*')
            result = std::stof(vecOp[4]) / std::stof(vecOp[2]);
        else if(vecOp[1][0]=='/')
            result = std::stof(vecOp[4]) * std::stof(vecOp[2]);
    }

    else if(isalpha(vecOp[2][0]) && !isalpha(vecOp[0][0]))
    {
        if(vecOp[1][0]=='+')
            result = std::stof(vecOp[4]) - std::stof(vecOp[0]);
        else if(vecOp[1][0]=='-')
            result = std::stof(vecOp[0]) - std::stof(vecOp[4]);
        else if(vecOp[1][0]=='*')
            result = std::stof(vecOp[4]) / std::stof(vecOp[0]);
        else if(vecOp[1][0]=='/')
            result = std::stof(vecOp[0]) / std::stof(vecOp[4]);
    }
    else
    {
        std::cout<<"Enter a valid equation\n";
    }

    return result;
};