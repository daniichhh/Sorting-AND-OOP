#ifndef BACAFILE_H
#define BACAFILE_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
struct City {
    string name, country;
    double lat, lng;
    long population;
};

vector<string> getData(string dataRaw);
vector<City> readFile(string filename, int n);


#endif // BACAFILE_H
