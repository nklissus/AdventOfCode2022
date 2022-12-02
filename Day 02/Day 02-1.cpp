#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Weapon {
    public:
        int value;
        string name;
        char beats;
};

int main() {
    string line;
    vector<int> round_totals;

    ifstream myfile ("input.txt");
    if (myfile.is_open()) {
        while (getline(myfile,line)) {
            char my_choice = line[2];
            char their_choice = line[0];

            Weapon my_weapon;
            if (my_choice == 'X'){
                my_weapon.value = 1;
                my_weapon.name = "Rock";
                my_weapon.beats = 'C';
            }
            else if (my_choice == 'Y') {
                my_weapon.value = 2;
                my_weapon.name = "Paper";
                my_weapon.beats = 'A';
            }
            else if (my_choice == 'Z') {
                my_weapon.value = 3;
                my_weapon.name = "Scissors";
                my_weapon.beats = 'B';
            }

            Weapon their_weapon;
            if (their_choice == 'A'){
                their_weapon.value = 1;
                their_weapon.name = "Rock";
            }
            else if (their_choice == 'B') {
                their_weapon.value = 2;
                their_weapon.name = "Paper";
            }
            else if (their_choice == 'C') {
                their_weapon.value = 3;
                their_weapon.name = "Scissors";
            }

            int round_score;
            if (my_weapon.beats == their_choice) {
                round_score = my_weapon.value + 6;
            }
            else if (my_weapon.value == their_weapon.value) {
                round_score = my_weapon.value + 3;
            }
            else {
                round_score = my_weapon.value;
            }
            round_totals.push_back(round_score);
        }
        myfile.close();
    }
    int final_total = 0;
    for (int i = 0; i < round_totals.size(); i++) {
        final_total += round_totals[i];
    }
    cout << "Your total score is: " << final_total << '\n';
}