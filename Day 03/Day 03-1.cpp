#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string line;
    vector<char> repeat_items;

    ifstream myfile ("input.txt");
    if (myfile.is_open()) {
        while (getline(myfile,line)) {

            // Strings seem way easier to deal with than char vectors here
            string first_half = line.substr(0, line.length()/2);

            //Utilize 'find' here wich gives us a bool telling us if the target is found in the string or whatever
            for (int i = line.length()/2; i < line.length(); i++) {
                if (find(first_half.begin(), first_half.end(), line[i]) != first_half.end()) {
                    repeat_items.push_back(line[i]);
                    break;
                }
            }            
        }
        myfile.close();
    }

    int priority_sum = 0;

    for (int i = 0; i < repeat_items.size(); i++) {
        if (islower ((int) repeat_items[i]) == 0 ) {
                priority_sum += (int) repeat_items[i]-38;
            }
        else {
                priority_sum += (int) repeat_items[i]-96;
            }
    }
    cout << "Your total priority is: " << priority_sum << '\n';
}