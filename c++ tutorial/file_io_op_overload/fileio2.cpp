#include<iostream>
#include<string>
#include<vector>
#include<sstream>

//Allow working with files
#include<fstream>

int main()
{   
    std::ofstream writeToFile;
    std::ifstream readFromFile;
    std::string textToWrite="";
    std::string textFromFile="";
    writeToFile.open("test.txt", std::ios_base::out | std::ios_base::trunc);

    if(writeToFile.is_open()){
        writeToFile<<"Beginning of file\n";
        std::cout<<"Enter data to write: ";
        getline(std::cin, textToWrite);
        writeToFile<<textToWrite;
        writeToFile.close();
    }

    readFromFile.open("test.txt", std::ios_base::in);
    if(readFromFile.is_open()){
        while(readFromFile.good()){
            getline(readFromFile, textFromFile);
            std::cout<<textFromFile<<"\n";
        }
        readFromFile.close();
    }

    return 0;
}
