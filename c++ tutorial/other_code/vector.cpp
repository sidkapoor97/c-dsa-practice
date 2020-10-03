#include<cstdlib>
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<cstring>

using namespace std;

int main()
{	
//	std::vector <int> vecRandNums(2);
//	
//	vecRandNums[0]=10;
//	vecRandNums[1]=20;
//	vecRandNums.push_back(30);
//	
//	std::cout<<"Last index: "<<vecRandNums[vecRandNums.size()-1]<<endl;
		
	//string to vector
	// std::string sSentence = "This is a random string";
	// std:: vector<std::string> vecWords;
	// std::stringstream ss(sSentence);
	// std::string sIndivStr;
	// char cSpace = ' ';

	

	// while (getline(ss, sIndivStr, cSpace))
	// {	
	// 	vecWords.push_back(sIndivStr);
	// }
	
	// for(int i=0;i<vecWords.size(); i++)
	// {
	// 	std::cout<< vecWords[i]<<"\n";
	// }
	
	double dbNum1 = 0;
	double dbNum2 = 0;
	std::string sCalc = "";
	std::vector<std::string> vecsCalc;

	std::cout<<"Enter Calculation (ex: 5 + 6): ";
	getline(std::cin, sCalc);
	std::stringstream ss(sCalc);
	std::string sIndivStr;
	char cSpace = ' ';

	while(getline(ss,sIndivStr, cSpace))
	{
		vecsCalc.push_back(sIndivStr);
	}

	dbNum1 = std::stoi(vecsCalc[0]);
	dbNum2 = std::stoi(vecsCalc[2]);

	std::string operation = vecsCalc[1];
	std::string plus(1, '+');
	std::string minus(1, '-');
	std::string multiply(1, '*');
	std::string divide(1, '/');

	if(operation == plus)
	{
		printf("%.1f + %.1f = %.1f\n",dbNum1,dbNum2,dbNum1+dbNum2);
	}
	else if(operation == minus)
	{
		printf("%.1f - %.1f = %.1f\n",dbNum1,dbNum2,dbNum1-dbNum2);
	}
	else if(operation == multiply)
	{
		printf("%.1f * %.1f = %.1f\n",dbNum1,dbNum2,dbNum1*dbNum2);
	}
	else if(operation == divide)
	{
		printf("%.1f / %.1f = %.1f\n",dbNum1,dbNum2,dbNum1/dbNum2);
	}
	else
	{
		printf("Enter a valid operation\n");
	}
	

}
