#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    //Mind your scope!
    string line;
    int sep = 0;
    vector<char> hold = {};
    int contained_pairs = 0;

    ifstream myfile ("input.txt");
    if (myfile.is_open()) {
        while (getline(myfile,line)) {
            hold = {};
            sep = 0;
            int first_low;
            int first_high;
            int second_low;
            int second_high;
            
            //This whole loop is to just pull out the relevant numbers
            while (!line.empty()) {
                char character = line.front();
                if (character == '-' && sep == 0) {
                    first_low = stoi(string{hold.begin(), hold.end()});
                    sep++;
                    hold = {};
                    line.erase(0,1);
                    continue;
                }
                else if (character == ',') {
                    first_high = stoi(string{hold.begin(), hold.end()});
                    sep++;
                    hold = {};
                    line.erase(0,1);
                    continue;
                }
                else if (character == '-' && sep == 2) {
                    second_low = stoi(string{hold.begin(),hold.end()});
                    hold = {};
                    line.erase(0,1);
                    continue;
                }
                hold.push_back(line.front());
                line.erase(0,1);
            }
            second_high = stoi(string{hold.begin(),hold.end()});

            if (first_low <= second_low && first_high >= second_high) {
                contained_pairs++;
            }
            else if (second_low <= first_low && second_high >= first_high) {
                contained_pairs++;
            }           
        }
    }
    cout << "There are " << contained_pairs << " pairs in this input.\n";
}