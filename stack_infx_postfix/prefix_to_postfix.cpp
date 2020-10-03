#include<iostream>
#include<string>
#include<cstdlib>
#include<stack>

bool IsOperator(char c);
std::string PrefixToPostfix(std::string prefix, std::stack<std::string> s);

int main()
{   
    std::string prefix,postfix;
    std::stack<std::string> s;
    std::cout<<"Enter the prefix expression:\n";
    std::cin>>prefix;
    std::cout<<"The postfix expression is:\n";
    postfix=PrefixToPostfix(prefix,s);
    std::cout<<postfix;
    return 0;
};

bool IsOperator(char c)
{
    if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^')
        return true;
    else
        return false;
};

std::string PrefixToPostfix(std::string prefix, std::stack<std::string> s)
{
    std::string postfix;
    for(int i=prefix.length()-1;i>=0;i--)
    {
        if(isalpha(prefix[i]))
        {
            std::string st(1,prefix[i]);
            s.push(st);
        }
        else if(IsOperator(prefix[i]))
        {
            std::string operator_1=s.top();
            s.pop();
            std::string operator_2=s.top();
            s.pop();
            std::string expression = operator_1+operator_2+prefix[i];
            s.push(expression);
        }
    }
    return s.top();
}