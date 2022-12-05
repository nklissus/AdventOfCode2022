#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    //Mind your scope!
    string line;
    vector<char> hold = {};
    bool preamble = true;
    vector<string> stacks = {"","","","","","","","",""};
    vector<int> count = {};
    string from_target = "";
    string to_target = "";

    ifstream myfile ("input.txt");
    if (myfile.is_open()) {
        while (getline(myfile,line)) {
            if (preamble == true) {
                if (line == "") {
                    preamble = false;
                    continue;
                }
                for (int i = 0; i < line.length(); i++) {
                    if (line[i] == ']') {
                        stacks[(i+2)/4-1] = line[i-1] + stacks[(i+2)/4-1];
                    }
                }
                continue;
            }
            
            //Erase 'move '
            line.erase(0,5);
            //This loop is to pull out the first number
            while (!line.empty()) {                
                char character = line.front();
                if (character == ' ') {
                    count.push_back(stoi(string{hold.begin(), hold.end()}));
                    hold = {};
                    line.erase(0,1);
                    break;
                }
                hold.push_back(line.front());
                line.erase(0,1);
            }
            //Erase 'from '
            line.erase(0,5);

            while (!line.empty()) {                
                char character = line.front();
                if (character == ' ') {
                    from_target += string{hold.begin(), hold.end()};
                    hold = {};
                    line.erase(0,1);
                    break;
                }
                hold.push_back(line.front());
                line.erase(0,1);
            }
            //Erase 'to '
            line.erase(0,3);

            while (!line.empty()) {                
                hold.push_back(line.front());
                line.erase(0,1);
            }
            to_target += string{hold.begin(), hold.end()};
            hold = {};
        }

        for (int i = 0; i < count.size(); i++) {
            string temp_string = stacks[(int)from_target[i]-'0'-1] + "";
            string temp_containers = temp_string.substr(stacks[(int)from_target[i]-'0'-1].length()-count[i], count[i]);
            stacks[(int)to_target[i]-'0'-1] += temp_containers;
            stacks[(int)from_target[i]-'0'-1].erase(stacks[(int)from_target[i]-'0'-1].length()-count[i], string::npos);
        }
    }
    string containers = "";
    for (int i = 0; i < stacks.size(); i++) {
        containers += stacks[i].back();
    }
    cout << "The top crates are: " << containers << ".\n";
}