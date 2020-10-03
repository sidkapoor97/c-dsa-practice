#include<stack>
#include<algorithm>
#include<iostream>
#include<string>

bool isOperator(char c);
std::string PrefixToInfix(std::string prefix, std::stack<std::string> s);

int main()
{   
    std::string prefix,infix;
    std::stack<std::string> s;
    std::cout<<"Enter the prefix expression:\n";
    std::cin>>prefix;
    std::cout<<"The Infix Expression is:\n";
    infix=PrefixToInfix(prefix,s);
    std::cout<<infix;
    return 0;
};

bool isOperator(char c)
{
    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
        return true;
    else
        return false;
};

std::string PrefixToInfix(std::string prefix, std::stack<std::string> s)
{
    std::string infix;
    std::reverse(prefix.begin(),prefix.end());
    for(int i=0;i<prefix.length();i++)
    {   
        if(isalpha(prefix[i]))
        {
            std::string st(1,prefix[i]);
            s.push(st);
        }
        else
        {
            std::string operator_1=s.top();
            s.pop();
            std::string operator_2=s.top();
            s.pop();
            std::string expression = '('+operator_1+prefix[i]+operator_2+')';
            s.push(expression);
        }
    }

    while(!(s.empty()))
    {
        infix+=s.top();
        s.pop();
    }
    return infix;
}