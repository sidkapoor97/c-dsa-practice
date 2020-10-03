#include<iostream>
#include<cmath>

class Shape{
public:
    virtual double Area() = 0;
};

class Circle: public Shape{
protected:
    double width;
public:
    Circle(double w){
        width=w;
    }
    double Area() override{
        return 3.14159*std::pow((width/2),2);
    }
};

class Rectangle: public Shape{
protected:
    double height,width;
public:
    Rectangle(double h,double w){
        height=h;
        width=w;
    }
    double Area() override{
        return width*height;
    }
};

void ShowArea(Shape& shape){
    std::cout<<"Area is: "<<shape.Area()<<"\n";
};

int main()
{   
    Rectangle rectangle(10,15);
    ShowArea(rectangle);
    Circle circle(10);
    ShowArea(circle);
    return 0;
};