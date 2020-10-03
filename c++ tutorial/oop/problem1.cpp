#include<ctime>
#include<string>
#include<iostream>

class Warrior
{
    private:
        std::string name;
        int health;
        int damage;
        int block;
    public: 
        //constructor
        Warrior(std::string, int, int, int);
        Warrior();

        //getters
        std::string GetName(){return name;}
        int GetHealth(){return health;}
        int GetDamage(){return damage;}
        int GetBlock(){return block;}

        //setters
        void SetHealth(int health){this->health=health;}

        //print function
        void ToString();
        
};
Warrior::Warrior(std::string name,int health,int damage,int block)
{
    this->name=name;
    this->health=health;
    this->damage=damage;
    this->block=block;
};

Warrior::Warrior()
{
    this->name="";
    this->health=0;
    this->damage=0;
    this->block=0;
};

class Battle: public Warrior{
    public:
        void StartFight(Warrior,Warrior);
};

void Battle::StartFight(Warrior player1, Warrior player2)
{       
    std::string name1=player1.GetName();
    std::string name2=player2.GetName();

    int health1=player1.GetHealth();
    int health2=player2.GetHealth();

    int damage1=player1.GetDamage();
    int damage2=player2.GetDamage();

    int block1=player1.GetBlock();
    int block2=player2.GetBlock();

    while(health1>0 && health2>0)
    {   
        int randDamage1=rand()%damage1;
        int randDamage2=rand()%damage2;

        health2-=randDamage1;
        // if(health2<0 || health1<0)
        //     break;
        std::cout<<name1<<" attacks "<<name2<<" and deals "<<randDamage1<<"\n";
        std::cout<<name2<<" is down to "<<health2<<"\n";

        if(health2<0 || health1<0)
            break;

        health1-=randDamage2;
        std::cout<<name2<<" attacks "<<name1<<" and deals "<<randDamage2<<"damage.\n";
        std::cout<<name1<<" is down to "<<health1<<"\n";

    };

    if(health1<=0)
        std::cout<<name1<<" has died and "<<name2<<" is Victorious.\n";
    else
        std::cout<<name2<<" has died and "<<name1<<" is Victorious.\n";
};
void Warrior::ToString()
{
    std::cout<<"name: "<<this->name<<"\n";
    std::cout<<"health: "<<this->health<<"\n";
    std::cout<<"damage: "<<this->damage<<"\n";
    std::cout<<"block: "<<this->block<<"\n";
};

int main()
{       
    srand(time(NULL));
    Warrior thor("Thor",100,2,15);
    Warrior hulk("Hulk",135,25,10);

    Battle battle;
    battle.StartFight(thor, hulk);
    
    return 0;
}