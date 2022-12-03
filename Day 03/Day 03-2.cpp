#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string line;
    int counter = 1;
    vector<string> triplet = {};
    vector<vector<string>> groups = {};
    string badges = "";

    ifstream myfile ("input.txt");
    if (myfile.is_open()) {
        while (getline(myfile,line)) {
            if (counter == 3) {
                triplet.push_back(line);
                groups.push_back(triplet);
                triplet = {};
                counter = 1;
                continue;
            }
            triplet.push_back(line);
            counter++;
        }
        myfile.close();
    }

    for (int i =0; i < groups.size(); i++) {
        string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        for (int j = 0; j < alphabet.size(); j++) {
            if (groups[i][0].find(alphabet[j]) != string::npos) {
                if (groups[i][1].find(alphabet[j]) != string::npos) {
                    if (groups[i][2].find(alphabet[j]) != string::npos){
                        badges += alphabet[j];
                    }
                }
            }
        }
    }
    int priority_sum = 0;

    for (int i = 0; i < badges.size(); i++) {
        if (islower ((int) badges[i]) == 0 ) {
                priority_sum += (int) badges[i]-38;
            }
        else {
                priority_sum += (int) badges[i]-96;
            }
    }
    cout << "Your total badge priority is: " << priority_sum << '\n';
}