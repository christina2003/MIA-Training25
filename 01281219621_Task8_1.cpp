#include <iostream>
using namespace std;

//class of characters with main attributes
class Character {
protected:
    float health;
    int energy;

public:
    //constructor
    Character(float h, int e) : health(h), energy(e) {}

    //setters and getters
    void set_health(float h) {
        health = h;
    }

    float get_health() const {
        return health;
    }

    void set_energy(int e) {
        energy = e;
    }

    int get_energy() const {
        return energy;
    }
};

//variables used in functions
int weapon;
int damage;
int shield;

//function to check validity of choosen weapon or shield
int get_valid_input(int min, int max) {
    int choice;
    while (true) {
        cin >> choice;
        if (choice >= min && choice <= max) {
            return choice;
        } else {
            cout << "Invalid choice. Please enter a number between " << min << " and " << max << ": ";
        }
    }
}

//objects
Character batman(100, 500);
Character joker(100, 500);

//function to choose weapon by user
int batman_weapon() {
    cout << "Batman, choose the number of a weapon you want: 1.Batarang 2.Grapple Gun 3.Explosive Gel 4.Batclaw: ";
    return get_valid_input(1, 4);
}

//function to set the damage and energy reduction based on the choosen weapon
void batman_attack() {
    switch (weapon) {
        case 1:
            batman.set_energy(batman.get_energy() - 50);
            damage = 11;
            break;
        case 2:
            batman.set_energy(batman.get_energy() - 88);
            damage = 18;
            break;
        case 3:
            batman.set_energy(batman.get_energy() - 92);
            damage = 10;
            break;
        default:
            batman.set_energy(batman.get_energy() - 120);
            damage = 20;
            break;

    }
}

//function to choose shield by user
int joker_shield() {
    cout << "Joker, choose the number of a shield you want: 1.Trick Shield 2.Rubber Chicken: ";
    return get_valid_input(1, 2);
}

//function to set the damage and energy reduction based on the choosen shield
void joker_defend() {
    switch (shield) {
        case 1:
            joker.set_energy(joker.get_energy() - 15);
            joker.set_health(joker.get_health() - (damage * 0.32));
            break;
        default:
            joker.set_energy(joker.get_energy() - 40);
            joker.set_health(joker.get_health() - (damage * 0.80));
            break;

    }
}

//function to choose weapon by user
int joker_weapon() {
    cout << "Joker, choose the number of a weapon you want: 1.Joy Buzzer 2.Laughing Gas 3.Acid Flower: ";
    return get_valid_input(1, 3);
}

//function to set the damage and energy reduction based on the choosen weapon
void joker_attack() {
    switch (weapon) {
        case 1:
            joker.set_energy(joker.get_energy() - 40);
            damage = 8;
            break;
        case 2:
            joker.set_energy(joker.get_energy() - 56);
            damage = 13;
            break;
        default:
            joker.set_energy(joker.get_energy() - 100);
            damage = 22;
            break;

    }
}

//function to choose shield by user
int batman_shield() {
    cout << "Batman, choose the number of a shield you want: 1.Cape Glide 2.Smoke Pellet: ";
    return get_valid_input(1, 2);
}

//function to set the damage and energy reduction based on the choosen shield
void batman_defend() {
    switch (shield) {
        case 1:
            batman.set_energy(batman.get_energy() - 20);
            batman.set_health(batman.get_health() - (damage * 0.40));
            break;
        default:
            batman.set_energy(batman.get_energy() - 50);
            batman.set_health(batman.get_health() - (damage * 0.90));

    }
}

int main() {

    //check the energy and healt of joker and batman to continue the game
    while (batman.get_health() > 0 && batman.get_energy() > 0 && joker.get_health() > 0 && joker.get_energy() > 0 ) {

        // Batman's turn
        weapon = batman_weapon();
        batman_attack();
        shield = joker_shield();
        joker_defend();

        if (joker.get_health() <= 0 || joker.get_energy() <= 0) {
            cout << "Batman wins!" << endl;
            break;
        }

        // Joker's turn
        weapon = joker_weapon();
        joker_attack();
        shield = batman_shield();
        batman_defend();

        if (batman.get_health() <= 0 || batman.get_energy() <= 0 ) {
            cout << "Joker wins!" << endl;
            break;
        }

        // Display the remaining health and energy
        cout << "Batman's Health: " << batman.get_health() << ", Energy: " << batman.get_energy() << endl;
        cout << "Joker's Health: " << joker.get_health() << ", Energy: " << joker.get_energy() << endl;
        cout << endl;
    }

    return 0;
}
