#include<iostream>
#include<vector>
#include<iterator>
#include<cmath>

#define PI 3.14159

#define AREA_CIRCLE(radius)(PI*(std::pow(radius,2)))

int main()
{   
    std::cout<<"Circle Area "<<AREA_CIRCLE(5)<<"\n";
    return 0;
}