#include <iostream>
#include <string>
using namespace std;

class GameObject{
    string id;
    public:
    GameObject(){ id = "";};
    string getID(){
        return id;
    };
};
class Stats{
    int hp;
    public:
    Stats(){hp = 20;};
    int getHP(){return hp;};
    void setHP(int health){hp = health;};
};
class SoulMark{
    public: 
    void Inscribed(){
        cout << "Wow, now you have a sweet tat\n it looks like this: \n";
    };
};

class Guild{
    string name;
    public:
    Guild(string guildName){
        name = guildName;
        cout << "Yeyyy u just joined the guild " << name <<"\n";
    };
};

class Hero: public GameObject{
    Stats background;
    SoulMark Tattoo;
};

int main() {
    cout << "Game starting...\n";

    Guild myGuild("Knights of HUZZAA");

    Hero hero;
    
    cout << "Done!\n";
    return 0;
}
