#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>

int main()
{	
	// std::string sQuestion("Enter Number 1: ");
	// std::string sNum1, sNum2;
	// std::cout<<sQuestion;
	// getline(std::cin, sNum1);
	// std::cout<<"Enter Number 2: ";
	// getline(std::cin, sNum2);

	// int nNum1 = std::stoi(sNum1);
	// int nNum2 = std::stoi(sNum2);

	// printf("%d + %d = %d\n",nNum1,nNum2, (nNum1+nNum2));
	// printf("%d - %d = %d\n",nNum1,nNum2, (nNum1-nNum2));
	// printf("%d * %d = %d\n",nNum1,nNum2, (nNum1*nNum2));
	// printf("%d / %d = %d\n",nNum1,nNum2, (nNum1/nNum2));

	// km = miles*1.60934
	std::string sQuestion("Enter Miles: ");
	std::string sMiles;
	std::cout<<sQuestion;
	getline(std::cin,sMiles);

	int nMiles = std::stof(sMiles);
	printf("%d miles equals %.4f kilometers\n", nMiles, nMiles*1.60934);
	return 0;
}
