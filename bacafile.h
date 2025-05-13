#ifndef BACAFILE_H
#define BACAFILE_H
#include <string>
#include <vector>
using namespace std;

struct City {
    string name, country;
    double lat, lng;
    long population;
};

vector<City> readFile(string filename, int k);
vector<City> getData((string dataRaw);


#endif // BACAFILE_H
