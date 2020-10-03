#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>

std::vector<int> Range(int start,int end, int increment);

int main()
{		
	std::string sQuestion("How much  to invest and interest rate: ");
	std::cout<<sQuestion;
	double nInvestment = 0.0, nInterestRate = 0.0;
	std::cin>>nInvestment >> nInterestRate;
	nInterestRate*=0.01;
	int nTime = 10;
	for(auto y: Range(1,10,1))
	{
		nInvestment+=(nInvestment*nInterestRate);
	}
	std::cout<<"Total amount after "<<nTime<<" years: "<<nInvestment<<"\n"; 
	
	return 0;
}

std::vector<int> Range(int start,int end, int increment)
{
	std::vector<int> vector;
	
	for(int i=start;i<=end;i+=increment)
		vector.push_back(i);
	return vector;
}

