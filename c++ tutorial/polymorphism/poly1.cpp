#include<iostream>
#include<string>
#include<vector>
#include<cmath>

struct Shape
{
    double length;
    double width;
    Shape(double l=1,double w=1){
        length=l;
        width=w;
    }

    double Area(){return length*width;}
    private:
        int id;
};

struct Circle: Shape{
    Circle(double width=1){
        this->width=width;
    }

    double Area(){ return 3.14158*std::pow(width,2);}
};

int main()
{   
    Shape shape(10,10);
    std::cout<<"Area is "<<shape.Area()<<"\n";
    Circle circle(4);
    std::cout<<"Area is "<<circle.Area()<<"\n";
    Shape rectangle(10,15);
    std::cout<<"Area is "<<rectangle.Area()<<"\n";
    return 0;
}
