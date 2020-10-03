#include<iostream>
#include<string>
#include<vector>
#include<sstream>

class Box{
public:
    double length;
    double width;
    double breadth;
    std::string boxString;
    Box(){
        length=1;
        width=1;
        breadth=1;
    }
    Box(double l,double w, double b){
        length=l;
        width=w;
        breadth=b;
    }
    Box& operator ++(){
        length++;
        width++;
        breadth++;
        return *this;
    }
    operator const char*(){
        std::ostringstream boxStream;
        boxStream<<"Box: "<<length<<", "<<width<<", "<<breadth;
        boxString = boxStream.str();
        return boxString.c_str();
    }

    //Binary Operator Overloading
    Box operator +(const Box& Box2){
        Box boxSum;
        boxSum.length=length+Box2.length;
        boxSum.width=width+Box2.width;
        boxSum.breadth=breadth+Box2.breadth;
        return boxSum;
    }

    //subscript operator
    double operator [](int x){
        if(x==0)
            return length;
        else if(x==1)
            return width;
        else if(x==2)
            return breadth;
        else
            return 0;
    }

    bool operator ==(const Box& Box2){
        return ((length == Box2.length) && (width == Box2.width) && (breadth == Box2.breadth));
    }

    bool operator <(const Box& Box2){
        double thisSize=length + width + breadth;
        double box2Size = Box2.length + Box2.width + Box2.breadth;
        if(thisSize<box2Size)
            return true;
        else
            return false;
    }

    bool operator >(const Box& Box2){
        double thisSize=length + width + breadth;
        double box2Size = Box2.length + Box2.width + Box2.breadth;
        if(thisSize>box2Size)
            return true;
        else
            return false;
    }

    void operator =(const Box& boxToCopy){
        length=boxToCopy.length;
        width=boxToCopy.width;
        breadth=boxToCopy.breadth;
    }
};

int main()
{   
    Box box1(10,10,10);
    ++box1;
    std::cout<<box1<<"\n";
    Box box2(5,5,5);
    std::cout<<"box1 + box2 = "<<box1+box2<<"\n";
    std::cout<<"Box Length: "<<box1[0]<<"\n";
    std::cout<<std::boolalpha;
    std::cout<<"Are boxes equal?? "<<(box1==box2)<<"\n";
    std::cout<<"Is box box1<box2"<<(box1 < box2)<<"\n";
    std::cout<<"Is box box1>box2"<<(box1 > box2)<<"\n";
    box1=box2;
    std::cout<<box1<<"\n";
    return 0;
}