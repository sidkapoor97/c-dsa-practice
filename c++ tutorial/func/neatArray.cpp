#include<iostream>

void PrintArray(int arr[], int arrSize);
void PrintDashes(int n);
int countDigit(int);

int main()
{       
    int arr[]={1,8,2,10,8,2,1,8,2,1,8,2,1,8,2};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    PrintArray(arr,arrSize);
    return 0;
};

int countDigit(int n)
{
    if(n==0)
        return 0;
    else
        return 1+countDigit(n/10);
}

void PrintDashes(int n)
{
    for(int i=0;i<=n;i++)
        std::cout<<"-";
};

void PrintArray(int arr[],int arrSize)
{   
    int maxDigit;
    for(int i=0;i<arrSize;i++)
    {
        if(countDigit(arr[i])>maxDigit)
            maxDigit = countDigit(arr[i]);
        if(countDigit(i)>maxDigit)
            maxDigit = countDigit(i);
    }
    PrintDashes(8*arrSize);
    std::cout<<"\n|";
    for(int i=0;i<arrSize;i++)
    {
        std::cout<<"   ";
        if(countDigit(i)<maxDigit)
            std::cout<<" ";
        std::cout<<i;
        std::cout<<"   |";
    }
    std::cout<<"\n";
    PrintDashes(8*arrSize);
    std::cout<<"\n|";
    for(int i=0;i<arrSize;i++)
    {
        std::cout<<"   ";
        if(countDigit(arr[i])<maxDigit)
            std::cout<<" ";
        std::cout<<arr[i];
        std::cout<<"   |";
    }
};

