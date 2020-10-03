#include<iostream>
#include<stack>
#include<string>
#include<cstdlib>

bool IsOperator(char c);
std::string PostfixToPrefix(std::string postfix, std::stack<std::string> s);

int main()
{   
    std::string postfix,prefix;
    std::stack<std::string> s;
    std::cout<<"Enter the postfix expression:\n";
    std::cin>>postfix;
    std::cout<<"The prefix expression is:\n";
    prefix=PostfixToPrefix(postfix,s);
    std::cout<<prefix;
    return 0;
};

bool IsOperator(char c)
{
    if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^')
        return true;
    else
        return false;
}

std::string PostfixToPrefix(std::string postfix, std::stack<std::string> s)
{
    std::string prefix;
    for (int i = 0; i < postfix.length(); i++)
    {
        if(isalpha(postfix[i]))
        {
            std::string st(1,postfix[i]);
            s.push(st);
        }
        else if(IsOperator(postfix[i]))
        {
            std::string operator_1=s.top();
            s.pop();
            std::string operator_2=s.top();
            s.pop();
            std::string expression = postfix[i]+operator_2+operator_1;
            s.push(expression);
        }
    }
    while(!(s.empty()))
    {
        prefix+=s.top();
        s.pop();
    }
    return prefix;
}