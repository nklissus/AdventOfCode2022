#include <iostream>
#include <fstream>
#include <string>
#include <list>
using namespace std;

int main() {
    string line;
    string line_end = "";
    list<int> totals = {};
    int temp_total = 0;

    ifstream myfile ("input.txt");
    if (myfile.is_open()) {
        while (getline(myfile,line)) {
            if (line != line_end) {
                temp_total += stoi(line); // stoi is "str to int"
            }
            else {
                totals.push_back(temp_total);
                temp_total = 0;
            }
        }
        myfile.close();
    }
    totals.sort();

    int first_most = totals.back();
    cout << "Top elf: " << first_most << "\n";
    totals.pop_back();
    int second_most = totals.back();
    cout << "Second elf: " << second_most << "\n";
    totals.pop_back();
    int third_most = totals.back();
    cout << "Third elf: " << third_most << "\n";
    cout << "The top elves together have " << first_most+second_most+third_most << " calories.\n";
}