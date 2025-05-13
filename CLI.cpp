#include <iostream>
#include <string>
#include <vector>
#include "sorter.h"
#include "bacafile.h"
using namespace std;

int main() {
    string files = "worldcities.csv";


    while (true) {
        string command;
        cout << " . / citysort ";
        getline(cin, command);

        if (command == "exit") break;

        string part;
        bool insideMust = false, insideOpt = false;
        vector<string> must, optional;

        for (char c : command) {
            if (c == '<') {
                insideMust = true;
                part.clear();
            } else if (c == '>') {
                insideMust = false;
                must.push_back(part);
                part.clear();
            } else if (c == '[') {
                insideOpt = true;
                part.clear();
            } else if (c == ']') {
                insideOpt = false;
                optional.push_back(part);
                part.clear();
            } else if (insideMust || insideOpt) {
                part += c;
            }
        }

        string algo = must[0];
        string key = must[1];
        int n = 10;
        bool reverse = false;

        for (string opt : optional) {
            if (opt == "-r") {
                reverse = true;
            } else if (opt.substr(0, 2) == "-n ") {
                string numStr = opt.substr(3);
                n = stoi(numStr);
            } else {
                continue;
            }
        }

        //Sorter::sort(algo, key, n); ini tergantung algoritma sorternya sih

        if (reverse) {
            for (int i = n - 1; i >= 0; i--) {
                City& city = cities[i];
                cout << cities[i].name << endl;
            }
        } else {
            for (int i = 0; i < n; i++) {
                cout << cities[i].name << endl;
            }
        }
    }

    return 0;
}
