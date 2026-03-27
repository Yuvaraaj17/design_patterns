#include <iostream>

using namespace std;

class Character {
    private:
        string name;
        string health;
        string weapon;
        string powerUp;
    public:

        void setName(string name) {
            this->name = name;
        }

        void setHealth(string health) {
            this->health = health;
        }

        void setWeapon(string weapon) {
            this->weapon = weapon;
        }

        void setPowerUp(string powerUp) {
            this->powerUp = powerUp;
        }

        Character* clone(){
            return new Character(*this);
        }

        void printAttribs() {
            cout << "Name:" << this->name << endl;
            cout << "Health:" << this->health << endl;
            cout << "PowerUp:" << this->powerUp << endl;
            cout << "Weapon:" << this->weapon << endl;
        }
};

int main() {

    Character c = Character();

    c.setName("hero 1");
    c.setHealth("100hp");
    c.setPowerUp("speed");
    c.setWeapon("blade");

    c.printAttribs();

    Character *d = c.clone();
    d->setName("hero 2");

    d->printAttribs();
    delete d;

    return 0;
}