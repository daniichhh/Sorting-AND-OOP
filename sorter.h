#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "bacafile.h"
using namespace std;

class Sorter {
public:
    static vector<City> cities;
    virtual void sort(string key, int n) = 0;

protected:
    bool compare(City a, City b, string key) {
        if (key == "name") return a.name < b.name;
        if (key == "country") return a.country < b.country;
        if (key == "lat") return a.lat < b.lat;
        if (key == "lng") return a.lng < b.lng;
        if (key == "population") return a.population < b.population;
        return false;
    }
};



// ------------------- Bubble Sort -------------------


// ------------------- Selection Sort -------------------


// ------------------- Merge Sort -------------------


// ------------------- Quick Sort -------------------
