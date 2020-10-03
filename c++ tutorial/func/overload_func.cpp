#include<iostream>
#include<cmath>

double Area(double radius);
double Area(double height, double width);

int main()
{   
    std::cout<<"c for Circle and r for rectangle: ";
    char areaType;
    std::cin>>areaType;
    switch (areaType)
    {
    case 'c':
        std::cout<<"Enter radius: ";
        double radius;
        std::cin>>radius;
        std::cout<<"Area = "<<Area(radius)<<"\n";
        break;
    case 'r':
        std::cout<<"Enter height and width: ";
        double height, width;
        std::cin>>height>>width;
        std::cout<<"Area = "<<Area(height, width)<<"\n";
        break;
    
    default:
        std::cout<<"Enter c or r\n";
        break;
    }
    return 0;
}

double Area(double radius)
{
    return 3.14159 * std::pow(radius, 2);
};

double Area(double height, double width)
{
    return height*width;
}