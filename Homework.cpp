#include <iostream>
#include <string>
using namespace std;

class GameObject{
    protected:
    string id;
    public:
    GameObject(){ id = "";};
    virtual ~GameObject(){}; // deletes characters
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
        void killGuild() {
        cout << "U disbanded from "<< name << "\n" << "its okey it wasnt that cool anyways" << "\n";
        name  = "";
    };
    string getName(){ return name; };
};

class Weapon {
    protected:
    string name;
    int baseDamage;
    public:
    Weapon(){
        name = "Fists";
        baseDamage = 1;
    };
    virtual ~Weapon() {
        cout <<  name << " dropped on the ground.\n";
    }
    virtual void attack(){
        cout << "RAAAAAA U HIT!!!!";
    };
    string getName(){return name;};
    int getBD(){return baseDamage;};
};

class Sword : public Weapon {
    int sharpness;
public:
    Sword(string sword, int dmg, int sharp){
        name = sword;
        baseDamage = dmg;
        sharpness = sharp;
    };
    void attack() override {
        cout << "RAAAA U HIT \n" << name << " dealt " << (baseDamage + sharpness) << " damage";
    };
};

class Potion{
    int hp; //health points
    public:
    Potion(int heal){
        hp = heal;
        cout << "U got potion. It heals "<< hp << "hp\n";
    };
    void drink(){
        cout << "Cool u just drank the potion. It tastes like sardines and pinaple";
    };
    int getHeal(){return hp;};
};

class Hero: public GameObject{
    Stats background;
    SoulMark Tattoo;
    Guild* guild;
    Weapon* weapon;
    public:
    Hero(){
        guild = nullptr;
        weapon = nullptr;
        cout << "Pick a name for your hero: ";
        cin >> id;
        cout << id << " is alive!\n";
    };
    ~Hero() override { //overides ~GameObject method and destroys hero
        cout << "killing " << id << "...\n";
    };
    void equipWeapon(Weapon* w){
        weapon = w;
        cout << id << " equipt " << w->getName() << "\n";
    };
    void joinGuild(Guild* g){
        guild = g;
        cout << id << "joines the guild: " << g->getName() << "\n";
    };
    void attack(){
        if (weapon) {
            weapon->attack();
        } else {
            cout << id << " attacks bare handed. It did no damage\n";
        };
    };
    void usePotion(Potion* p){
        p->drink();
        int newHP = background.getHP() + p->getHeal();
        if (newHP > 20){
            newHP = 20;
            background.setHP(newHP);
            cout << "You are now at full health";
        } else{
            background.setHP(newHP);
            cout << id << " health restored to " << newHP << "hp\n";
        };
    };
    string getId(){
        return(id);
    };
    
};
