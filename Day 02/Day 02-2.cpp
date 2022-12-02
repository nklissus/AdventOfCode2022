#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class MyWeapon {
    public:
        int value;
        string name;
};

class EnemyWeapon {
    public:
        int value;
        string name;
        MyWeapon beats;
        MyWeapon beat_by;
};

int main() {
    string line;
    vector<int> round_totals;

    ifstream myfile ("input.txt");
    if (myfile.is_open()) {
        while (getline(myfile,line)) {
            char my_choice = line[2];
            char their_choice = line[0];

            MyWeapon rock;
            rock.value = 1;
            rock.name = "Rock";

            MyWeapon paper;
            paper.value = 2;
            paper.name = "Paper";

            MyWeapon scissors;
            scissors.value = 3;
            scissors.name = "Scissors";

            EnemyWeapon their_weapon;
            if (their_choice == 'A'){
                their_weapon.value = 1;
                their_weapon.name = "Rock";
                their_weapon.beat_by = paper;
                their_weapon.beats = scissors;
            }
            else if (their_choice == 'B') {
                their_weapon.value = 2;
                their_weapon.name = "Paper";
                their_weapon.beat_by = scissors;
                their_weapon.beats = rock;
            }
            else if (their_choice == 'C') {
                their_weapon.value = 3;
                their_weapon.name = "Scissors";
                their_weapon.beat_by = rock;
                their_weapon.beats = paper;
            }

            int round_score;
            if (my_choice == 'Z') {
                round_score = their_weapon.beat_by.value + 6;
            }
            else if (my_choice == 'Y') {
                round_score = their_weapon.value + 3;
            }
            else {
                round_score = their_weapon.beats.value;
            }
            round_totals.push_back(round_score);
        }
        myfile.close();
    }
    int final_total = 0;
    for (auto i = 0; i < round_totals.size(); i++) {
        final_total += round_totals[i];
    }
    cout << "Your total score is: " << final_total << '\n';
}