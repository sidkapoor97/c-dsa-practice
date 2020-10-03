#include<iostream>
#include<vector>
#include<numeric>
#include<string>

class Animal
{
    private:
        std::string name;
        double height;
        double weight;
        static int numOfAnimals;
    public:
        // Getters
        std::string GetName(){ return name;}
        double GetHeight(){ return height;}
        double GetWeight(){ return weight;}

        // Setters
        void SetName(std::string name){this->name = name;}
        void SetHeight(int height){this->height = height;}
        void SetWeight(int weight){this->weight = weight;}

        void SetAll(std::string, double, double);

        //Constructors
        Animal(std::string, double, double);
        Animal();

        //Deconstructors -> release memory, computer Resources
        ~Animal();

        static int GetNumOfAnimals(){ return numOfAnimals;}
        void ToString();
};

int Animal::numOfAnimals = 0;
void Animal::SetAll(std::string name, double height, double weight)
{
    this->name=name;
    this->height=height;
    this->weight=weight;
    Animal::numOfAnimals+=1;
};

Animal::Animal(std::string name,double height, double weight)
{
    this->name=name;
    this->height=height;
    this->weight=weight;
    Animal::numOfAnimals++;
};

Animal::Animal()
{
    this->name="";
    this->height=0;
    this->weight=0;
    Animal::numOfAnimals++;
};

Animal::~Animal()
{
    std::cout<<"Animal "<<this->name<<" destroyed.\n";
};

void Animal::ToString(){
    std::cout<<this->name<<" is "<<this->height<<" cms. tall and "<<this->weight<<" kgs heavy.\n";
};

class Dog:public Animal
{
    private:
        std::string sound="Woof";
    public:
        void MakeSound(){
            std::cout<<"The Dog "<<this->GetName()<<" says "<<this->sound<<"\n";
        };
        Dog(std::string, double, double, std::string);
        Dog(): Animal(){};
        void ToString();
};

Dog::Dog(std::string name, double height, double weight, std::string sound): Animal(name, height, weight)
{
    this->sound=sound;
} 

void Dog::ToString()
{
    std::cout<<this->GetName()<<" is "<<this->GetHeight()<<" cms. tall and "<<this->GetWeight()<<" kgs heavy and says "<<this->sound<<"\n";
};
int main()
{   
    Animal fred;
    fred.ToString();
    fred.SetHeight(33);
    fred.SetWeight(10);
    fred.SetName("freddy");
    fred.ToString();
    Animal tom("tom",36,15);
    tom.ToString();
    Dog Spot("Spot",38,16,"Wooooooof");
    Spot.ToString();

    std::cout<<"Number of Animals: "<<Animal::GetNumOfAnimals()<<"\n";

    return 0;
}
