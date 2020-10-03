#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>

void calcWordNum(std::string theString,float arr[]);

int main()
{   
    std::ofstream writeToFile;
    std::string textToWrite;

    float data[2];
    writeToFile.open("prob.txt", std::ios_base::trunc | std::ios_base::out);

    if(writeToFile.is_open()){
        std::string beginString = "Begining of the file";
        writeToFile<<beginString<<" ";
        calcWordNum(beginString, data);
        writeToFile<<"| WordCount: "<<data[0]<<"| Avg. Word Length: "<<data[1]<<"\n";
        std::string input;

        do
        {
            std::cout<<"Enter exit to exit else any key to continue: ";
            getline(std::cin, input);
            if(input != "exit")
            {
            writeToFile<<input<<" ";
            calcWordNum(input, data);
            writeToFile<<"| WordCount: "<<data[0]<<"| Avg. Word Length: "<<data[1]<<"\n";
            }
        } while (input!="exit");
        
    }
    return 0;
}

void calcWordNum(std::string theString,float data[])
{
    std::stringstream ss(theString);
    std::string cSpace = " ";
    std::string IndivChar;
    std::vector<std::string> vecLetter;
    while(getline(ss,IndivChar,cSpace[0])){
        vecLetter.push_back(IndivChar);
    }

    data[0] = vecLetter.size();
    int letterCount = 0;
    for(int i=0;i<vecLetter.size();i++)
    {
        letterCount+=vecLetter[i].length();
    }
    data[1]=letterCount/data[0];
}