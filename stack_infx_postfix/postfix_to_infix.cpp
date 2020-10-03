#include<stack>
#include<iostream>
#include<string>
#include<algorithm>

bool isOperator(char c);
std::string ModifiedReplace(std::string epxresion);
std::string PostfixToInfix(std::string postfix,std::stack<std::string> s);

int main()
{   
    std::string postfix, infix;
    std::stack<std::string> s;
    std::cout<<"Enter the postfix expression:\n";
    std::cin>>postfix;
    std::cout<<"The infix expression is:\n";
    infix=PostfixToInfix(postfix,s);
    std::cout<<infix;
    return 0;
};

bool isOperator(char c)
{
    if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^')
        return true;
    else
        return false;
};

std::string ModifiedReplace(std::string expression)
{   
    std::string finalString="";
    for(int i=0;i<expression.length();i++)
    {
        if(expression[i]=='(')
            finalString+=')';
        else if(expression[i]==')')
            finalString+='(';
        else
            finalString+=expression[i];
    }
    return finalString;
};

std::string PostfixToInfix(std::string postfix,std::stack<std::string> s)
{
    std::string infix;
    for(int i=0;i<postfix.length();i++)
    {
        if(isalpha(postfix[i]))
        {
            std::string st(1,postfix[i]);
            s.push(st);
        }
        else if(isOperator(postfix[i]))
        {
            std::string operator_1 = s.top();
            s.pop();
            std::string operator_2 = s.top();
            s.pop();
            std::string expression = '('+operator_1+postfix[i]+operator_2+')';
            s.push(expression);
        }
    }
    while (!(s.empty()))
    {
        infix+=s.top();
        s.pop();
    }
    std::reverse(infix.begin(),infix.end());
    infix=ModifiedReplace(infix);
    return infix;
}