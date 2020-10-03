#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>

int Precedence(char c);
std::string ModifiedReplace(std::string epxresion);
bool isOperator(char c);
void printStack(std::stack<char> s);
std::string InfixToPrefix(std::stack<char> s,std::string infix);

int main()
{       
    std::string infix, prefix;
    std::stack<char> s;
    std::cout<<"Enter the infix expression:\n";
    std::cin>>infix;
    std::cout<<"The prefix expression is:\n";
    prefix=InfixToPrefix(s,infix);
    std::cout<<prefix<<"\n";
    return 0;
};

int Precedence(char c)
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

std::string InfixToPrefix(std::stack<char> s, std::string infix)
{
    std::string prefix;
    std::reverse(infix.begin(),infix.end());
    infix = ModifiedReplace(infix);
    for(int i=0;i<infix.length();i++)
    {
        if(isalpha(infix[i]))
            prefix+=infix[i];
        else if(infix[i]=='(')
            s.push(infix[i]);
        else if(infix[i]==')')
        {
            while((s.top()!='(') && (!s.empty()))
            {
                prefix+=s.top();
                s.pop();
            }
            if(s.top()=='(')
                s.pop();
        }
        else if(isOperator(infix[i]))
        {
            if(s.empty())
                s.push(infix[i]);
            else
            {
                if(Precedence(infix[i])>Precedence(s.top()))
                    s.push(infix[i]);
                else if((Precedence(infix[i])==Precedence(s.top())) && infix[i]=='^')
                {
                    while((Precedence(infix[i])==Precedence(s.top())) && infix[i]=='^')
                    {
                        prefix+=s.top();
                        s.pop();
                    }
                    s.push(infix[i]);
                }
                else if(Precedence(infix[i])==Precedence(s.top()))
                    s.push(infix[i]);
                else
                {
                    while (!(s.empty()) && (Precedence(infix[i])<Precedence(s.top())))
                    {
                        prefix+=s.top();
                        s.pop();
                    }
                    s.push(infix[i]);
                }
            }
        }
    }
    while (!(s.empty()))
    {
        prefix+=s.top();
        s.pop();
    }
    std::reverse(prefix.begin(),prefix.end());
    return prefix;
}