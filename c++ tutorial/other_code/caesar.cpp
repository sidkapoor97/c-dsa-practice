#include<string>
#include<cstdlib>
#include<iostream>
#include<sstream>

std::string CaesarCipher(std::string, int, bool);
std::string CaesarSolution(std::string, int, bool);

int main()
{   
    std::string theString = "Make me secret";
    std::string encryptedStr = CaesarCipher(theString, 5, true);
    std::string decryptedStr = CaesarCipher(encryptedStr, 5, false);
    std::cout<<"Encrypted Str: "<<encryptedStr<<"\n";
    std::cout<<"Decrypted Str: "<<decryptedStr<<"\n";

    encryptedStr = CaesarSolution(theString, 5, true);
    decryptedStr = CaesarSolution(encryptedStr, 5, false);
    std::cout<<"Encrypted Str: "<<encryptedStr<<"\n";
    std::cout<<"Decrypted Str: "<<decryptedStr<<"\n";
    return 0;
};

std::string CaesarCipher(std::string theString, int shift, bool mode)
{
    if(mode)
    {
        // encrypt
        std::string encryptedString;
        for(int i=0;i<theString.length();i++)
        {   
            if(isspace(theString[i]))
                encryptedString+=" ";
            else
                {
                    int nletterVal = (int)theString[i]-shift;
                    if (nletterVal<65)
                    {
                        nletterVal  += 26;
                    }
                    else if (nletterVal < 97 && nletterVal>90)
                    {
                        nletterVal += 26;
                    }
                    encryptedString+=(char)(nletterVal);
                }
        }
        return encryptedString;
    }
    else
    {
        // decreypt
        std::string decryptedString;
        for(int i=0;i<theString.length();i++)
        {   
            if(isspace(theString[i]))
                decryptedString+=" ";
            else
                {
                    int nletterVal = (int)theString[i]+shift;
                    if(nletterVal>90 && nletterVal<97)
                    {
                        nletterVal -= 26;
                    }
                    else if(nletterVal>122)
                    {
                        nletterVal -= 26;
                    }
                    decryptedString+=(char)(nletterVal);
                }
        }
        return decryptedString;
    }
};

std::string CaesarSolution(std::string theString, int key, bool encrypt)
{
    std::string returnString="";
    int charCode = 0;
    char letter;
    if(encrypt) key*= -1;
    for(char& c: theString)
    {
        if(isalpha(c))
        {
            charCode = (int)c;
            charCode+=key;
            if(isupper(c))
            {
                if(charCode > (int)'Z')
                    charCode-=26;
                else if(charCode<(int)'A')
                    charCode+=26;
            }
            else
            {
                if(charCode > (int)'z')
                    charCode-=26;
                else if(charCode<(int)'a')
                    charCode+=26;
            }
            letter = charCode;
            returnString+=letter;
        }
        else
        {
            returnString+=c;
        }
    }
    return returnString;
}