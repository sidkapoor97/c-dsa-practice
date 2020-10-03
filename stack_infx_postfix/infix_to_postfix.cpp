#include<iostream>
#include<stack>
#include<string>
#include<vector>

int precedence(char c);
std::string InfixToPostfix(std::stack<char> s,std::string infix);
bool isOperator(char c);
void printStack(std::stack<char> s);

int main()
{   
    std::string infix;
    std::string postfix;
    std::cout<<"Enter an infix expression:\n";
    std::cin>>infix;
    std::stack <char> s;
    std::cout<<"The postfix expression is:\n";
    postfix=InfixToPostfix(s,infix);
    std::cout<<postfix<<"\n";
    return 0;
};

int precedence(char c)
{
    if(c=='+' || c=='-')
        return 1;
    else if(c=='*' || c=='/')
        return 2;
    else if(c=='^')
        return 3;
    else
        return -1;
};

bool isOperator(char c)
{
    if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^')
        return true;
    else
        return false;
};

void printStack(std::stack<char> s)
{   
    std::cout<<"\n-------------------\n";
    while (!(s.empty()))
    {
        std::cout<<s.top()<<" ";
        s.pop();
    }
    std::cout<<"\n-------------------\n";
};

std::string InfixToPostfix(std::stack<char> s,std::string infix)
{
    std::string postfix;
    for(int i=0;i<infix.length();i++)
    {
        if(isalpha(infix[i]))
            postfix+=infix[i];
        else if(infix[i]=='(')
            s.push(infix[i]);
        else if(infix[i]==')')
        {
            while (s.top()!='(' || s.empty())
            {
                postfix+=(s.top());
                s.pop();
            }
            s.pop();
        }
        else if(isOperator(infix[i]))
        {
            if(s.empty())
                s.push(infix[i]);
            else
            {
                if(precedence(infix[i])>precedence(s.top()))
                    s.push(infix[i]);
                else if(precedence(infix[i])==precedence(infix[i]) && (infix[i]=='^'))
                    s.push(infix[i]);
                else
                {
                    while(!(s.empty()) && (precedence(infix[i])<=precedence(s.top())))
                    {
                        postfix+=(s.top());
                        s.pop();
                    }
                    s.push(infix[i]);
                }
            }
        }
    }
    while (!(s.empty()))
    {   
        if(s.top()!='(')
            postfix+=(s.top());
        s.pop();
    }
    return postfix;
}