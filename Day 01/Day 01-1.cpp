#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string line;
    string line_end = "";
    int most_cals = 0;
    int temp_total = 0;

    ifstream myfile ("input.txt");
    if (myfile.is_open()) {
        while (getline(myfile,line)) {
            if (line != line_end) {
                temp_total += stoi(line); // stoi is "str to int"
            }
            else {
                if (temp_total > most_cals) {
                    most_cals = temp_total;
                }
                temp_total = 0;
            }
        }
        myfile.close();
    }
    cout << "The elf carrying the most calories has " << most_cals << " calories.\n";
}