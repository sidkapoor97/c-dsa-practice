#include<ctime>
#include<iostream>

template<typename T>
T Add(T val,T val2){
    return val+val2;
};

template<typename T>
T Max(T val,T val2){
    return (val<val2)?val2 : val;
}

int main()
{   
    std::cout<<"5+4="<<Add(5,4)<<"\n";
    std::cout<<"5.44+4.12="<<Add(5,4)<<"\n";
    std::cout<<"Max(5,3)="<<Max(5,3)<<"\n";
    std::cout<<"Max(5.22,8.31)="<<Max(5.22,8.31)<<"\n";
    std::cout<<"Max(A,B)="<<Max('A','B')<<"\n";
    std::cout<<"Max(Dog,Cat)="<<Max("Dog","Cat")<<"\n";


    return 0;
}