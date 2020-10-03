#include<cstdlib>
#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<sstream>
#include<bits/stdc++.h>

int main()
{   
    // std::vector<std::string> strVec(10);

    // std::string str("I'm a string");
    // strVec[0]=str;

    // std::cout<<str.front()<<" "<<str.back()<<" Length is: "<<str.length() <<"\n";

    // std::string str2(str);
    // std::string str3(str, 4);
    // std::string str4(5, 'x');

    // strVec[1]=str2;
    // strVec[2]=str3;
    // strVec[3]=str4;
    // strVec[4]=str.append(" and you are not");
    // // str+=" and you arent";
    // str.append(str, 15, 20);
    // strVec[5]=str;
    // str.erase(13, str.length() - 1);
    // strVec[6]=str;
    // std::cout<<"Final Str: "<<str<<"\n";
    // // for(auto y:strVec)
    // //     std::cout<<y<<"\n";

    // if(str.find("string") != std::string::npos)
    // {
    //     std::cout<<"First index: "<<str.find("string")<<"\n";
    // }

    // std::cout<<"SubStr: "<<str.substr(6, 6)<<"\n";

    // reverse(str.begin(), str.end());
    // std::cout<<"Reverse: "<<str<<"\n";

    // transform(str2.begin(), str2.end(), str2.begin(), ::toupper);
    // std::cout<<"Upper: "<<str2<<"\n";

    // transform(str3.begin(), str3.end(), str3.begin(), ::tolower);
    // std::cout<<"Upper: "<<str3<<"\n";

    //a-z = 97-122
    // A - Z = 65 - 90

    // char aChar = 'a';
    // int aInt = aChar;
    // std::cout<<"A code: "<<aInt<<"\n";

    // std::string strNum = std::to_string(97);
    // std::cout<<" String "<<strNum<<"\n";
    
    std::cout<<"Enter the string: ";
    std::string inputStr;
    std::cin>>inputStr;
    // std::vector<int> ascii;
    std::string output,temp;
    for(auto y: inputStr)
    {
        // ascii.push_back((int)y);
        temp+=std::to_string((int)(y-' '));
        output+=std::to_string((int)y);
    }

    // for(auto y: ascii) std::cout<<y;
    std::cout<<"Secret String: "<<output<<"\n";
    inputStr="";

    for(int i=0;i<temp.length();i+=2)
    {   
        inputStr+=(char)(std::stoi(temp.substr(i,2))+(char)' ');
    }
    std::cout<<"Original String: "<<inputStr<<"\n";
    return 0;
}