#include <iostream>
#include <string>
using namespace std;

class GameObject {
protected:
    string id;
public:
    GameObject() { id = ""; }
    string getId() { return id; }
};

class Stats {
    int hp;
    int level;
public:
    Stats() : hp(20), level(1) {}
    int  getHP()    { return hp; }
    void setHP(int v)    { hp = v; }
    int  getLevel() { return level; }
    void setLevel(int v) { level = v; }
};

class SoulMark {
    bool marked;
public:
    SoulMark() : marked(false) {}
    bool getMarked()           { return marked; }
    void setMarked(bool state) { marked = state; }
};

class Guild {
    string name;
public:
    Guild(string guildName) : name(guildName) {
        cout << "Yeyyy u just joined the guild " << name << "\n";
    }
    string getName() { return name; }
};

class Weapon {
protected:
    string name;
    int baseDamage;
public:
    Weapon(string n, int dmg) : name(n), baseDamage(dmg) {}
    virtual ~Weapon() {
        cout << name << " dropped on the ground.\n";
    }
    string getName()   { return name; }
    int    getDamage() { return baseDamage; }
    virtual void attack() const {
        cout << "O NOES! U LOST " << baseDamage << " HP\n";
    }
};

class Sword : public Weapon {
    int sharpness;
public:
    Sword(string n, int dmg, int sharp)
        : Weapon(n, dmg), sharpness(sharp) {}
    void attack() const override {
        cout << name << " HIT AND DEALT " << (baseDamage + sharpness) << " DAMAGE. WOWZA\n";
    }
};

class Potion {
    int healthP;
public:
    Potion(int heal) : healthP(heal) {
        cout << "U BOUGHT A POTION. IT HEALS " << heal << " HP\n";
    }
    int getHeal() { return healthP; }
};

class Hero : public GameObject {
    Stats    background;
    SoulMark Tattoo;
    Guild*   guild;
    Weapon*  weapon;
public:
    Hero() : guild(nullptr), weapon(nullptr) {
        cout << "Pick a name for your hero: ";
        cin >> id;
        cout << id << " IS AWAKE AND ALIVE\n";
    }
    ~Hero() override {
        cout << id << " IS DEAD. CLEANING UP...\n";
    }
    void joinGuild(Guild* g)    { guild  = g; cout << id << " joined " << g->getName() << "\n"; }
    void equipWeapon(Weapon* w) { weapon = w; cout << id << " equipped " << w->getName() << "\n"; }
    void usePotion(Potion* p) {
        int newHP = background.getHP() + p->getHeal();
        if (newHP > 20) { newHP = 20; }
        background.setHP(newHP);
        cout << "HP restored to " << newHP << "\n";
    }
    void attack() {
        if (weapon) weapon->attack();
        else cout << id << " attacks barehanded!\n";
    }
    Stats&    getStats()    { return background; }
    SoulMark& getSoulMark() { return Tattoo; }
    void report() {
        cout << "\n=== STATUS: " << id << " ===\n";
        cout << "  HP    : " << background.getHP()    << "\n";
        cout << "  Level : " << background.getLevel() << "\n";
        cout << "  Marked: " << Tattoo.getMarked()    << "\n";
        cout << "  Guild : " << (guild  ? guild->getName()  : "(none)") << "\n";
        cout << "  Weapon: " << (weapon ? weapon->getName() : "(none)") << "\n\n";
    }
};

int main() {
    Guild* myGuild = new Guild("Knights of HUZZAA");
    Hero*  hero    = new Hero();
    Sword* sword   = new Sword("Excalibur", 15, 8);

    hero->joinGuild(myGuild);
    hero->equipWeapon(sword);
    hero->getSoulMark().setMarked(true);
    hero->getStats().setLevel(5);

    Potion* p = new Potion(10);
    hero->usePotion(p);
    delete p;

    hero->report();
    hero->attack();

    delete hero;

    cout << "\nGuild still alive: " << myGuild->getName() << "\n";
    cout << "Sword still exists: " << sword->getName()   << "\n";

    delete sword;
    delete myGuild;
    return 0;
}
