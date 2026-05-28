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
    SoulMark getSoulMark(){ return Tattoo;};
};

int main() {
    cout << "BOOTING...........\n";
    cout << "HEROS JOURNEY\n";
    cout << "\n";

    //creating character
    Hero* myHero = new Hero();

    string choose;

    //Guild asignment
    cout << "You walk into town and see the guilded village. A village filled with guilds one can join. A true hero needs the finest of guilds u think and 4 catch your eye: \n";
    cout << "1- Arthurs super guild for supers \n 2- Guilded guild for the difted guilders \n 3- Syndromes super villain to hire guild \n 4- ONLY THE BEST SUPER HEROES ENTER THIS GUILD (definetly not a scheme trust me bro)";
    cout << "Which guid will u choose (1,2,3,4)? ";
    cin >> choose;
    string guildName;
    if(choose == "1") guildName = "Arthurs super guild for supers";
    else if(choose == "2") guildName = "Guilded guild for the gilded guilders";
    else if(choose == "3") guildName = "Syndromes super villain guild";
    else guildName = "ONLY THE BEST SUPER HEROES";
    Guild* adventuresG = new Guild(guildName);
    myHero->joinGuild(adventuresG);

    //soulmark assignment
    cout << "You keep walking through the village and see that they are tattoing soul marks. Seems fun you think but its preetty expensive\n will you get a soulmark (y or n)?";
    cin >> choose;
    if (choose == "y"){ myHero->getSoulMark().Inscribed();}else{cout << "Lets not be finantially irresponsible";};

    //Sword assignment
    cout << "U walk through the forest. Guess the guild asigned u your first job. Oh whats this? an Xcalibur on the ground?\n will you pick it up (y or n)?";
    cin >> choose;
    Sword* mySword = nullptr;
    if(choose == "y"){    
        mySword = new Sword("Xcalibur", 8, 4);
        myHero->equipWeapon(mySword);
    };
    
    cout << "Oh no u encounter an evil wareworl! \n warewolf attacks with its giant claws\n -8 health";
    Stats hStats;
    Stats* myStats = new Stats();
    *myStats = hStats;
    myStats->setHP(12);
    
    cout << "\n Lets drink a potion\n";

    // we put potion in curly braces to create a local scope for potion, this way potion only lives locally so when its destroyed, hero isnt
    {
        Potion* myPotion = new Potion(4);
        myHero->usePotion(myPotion);
        myStats->setHP(16);
        delete myPotion;
    }                                    
 
    cout << "Eyy lest goooo. Now time to attack!\n hero attacks";
    myHero->attack();
 
    cout << "ey that was epic. Weit wha- WATCH OUTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT\n\n";
    cout << myHero->getId() << "Recibes lethal blow \n u ded\n\n";
    cout << "Deleting Hero...\n";
    delete myHero;  // ~Hero() runs:
    myHero = nullptr;

    cout<< "Is everything.... still here?\n\n";
    cout << adventuresG->getName() << "Is online\n";
    if(mySword) cout << mySword->getName() << " is held by heroes corpse.\n";
    else cout << "Hero died barehanded. Mad respect bro\n";
 
    cout << "Welp time to delete ig";
    if(mySword) delete mySword;
    delete adventuresG;

    cout << "Babie thanks for playing";
    return 0;
}
    
};
