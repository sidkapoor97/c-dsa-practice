#include<ctime>
#include<string>
#include<iostream>
#include<cmath>

class Warrior
{   
    private:
        int attMax;
        int blockMax;
    public:
        std::string name;
        int health;

        Warrior(std::string name, int health, int attMax, int blockMax)
        {
            this->name=name;
            this->health=health;
            this->attMax=attMax;
            this->blockMax=blockMax;
        }
        int Attack(){
            return std::rand()%this->attMax;   
        };
        int Block(){
            return std::rand()%this->blockMax;   
        };
};

class Battle{
    public:
        static void StartFight(Warrior& warrior1, Warrior& warrior2){
            while (true)
            {
                if(Battle::GetAttackResult(warrior1, warrior2).compare("Game Over") == 0){
                    std::cout<<"Game Over\n";
                    break;
                }
                if(Battle::GetAttackResult(warrior2, warrior1).compare("Game Over") == 0){
                    std::cout<<"Game Over\n";
                    break;
                }
            }
                        
        };

        static std::string GetAttackResult(Warrior& warriorA,Warrior& warriorB){
            int warriorAAttk=warriorA.Attack();
            int warriorBAttk=warriorB.Block();
            int damage2WarriorB = ceil(warriorAAttk - warriorBAttk);
            damage2WarriorB = (damage2WarriorB <= 0) ? 0: damage2WarriorB;
            warriorB.health = warriorB.health - damage2WarriorB;

            printf("%s attacks %s and deals %d damage\n", warriorA.name.c_str(), warriorB.name.c_str(), damage2WarriorB);
            printf("%s is down to %d health\n", warriorB.name.c_str(), warriorB.health);
            if(warriorB.health<=0)
            {
                printf("%s has died and %s is victorious\n", warriorA.name.c_str(), warriorB.name.c_str());
                return "Game Over";
            }
            else
                return "Fight Again";
        };
};

int main()
{
    srand(time(NULL));
    Warrior thor("Thor", 100, 30, 15);
    Warrior hulk("Hulk", 135, 25, 10);

    Battle::GetAttackResult(thor, hulk);
    return 0;
}