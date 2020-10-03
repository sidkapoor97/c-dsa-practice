#include<iostream>
#include<cmath>

class Shape{
protected:
    double height;
    double width;
public:
    Shape(double length){
        height=length;
        width=length;
    }
    Shape(double h, double w){
        height=h;
        width=w;
    }
    virtual double Area(){
        return height*width;
    }
};

class Circle: public Shape{
public:
    Circle(double w): Shape(w){
        
    }
    double Area(){
        return 3.14159*std::pow((width/2),2);
    }
};

void ShowArea(Shape& shape){
    std::cout<<"Area is: "<<shape.Area()<<"\n";
}

int main()
{   
    Shape square(10);
    ShowArea(square);
    Shape rectangle(10,15);
    ShowArea(rectangle);
    Circle circle(10);
    ShowArea(circle);
    return 0;
}