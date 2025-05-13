#include "bacafile.h"

vector<string> getData(string dataRaw) {
    vector<string> result;
    string field;
    bool insideQuotes = false;

    for (char c : dataRaw) {
        if (c == '"') {
            insideQuotes = !insideQuotes;
        } else if (c == ',' && !insideQuotes) {
            result.push_back(field);
            field.clear();
        } else {
            field += c;
        }
    }

    result.push_back(field);
    return result;
}

bool isNumeric(const string& str) {
    return !str.empty() && all_of(str.begin(), str.end(), ::isdigit);
}

vector<City> readFile(string filename, int k) {
    vector<City> cities;
    ifstream file(filename);
    string line;
    int counter = 0;

    getline(file, line); // header

    while (getline(file, line) && counter < k) {
        vector<string> fields = getData(line);
        if (fields.size() < 10) continue;

        City city;
        city.name = fields[1];
        city.country = fields[4];
        city.lat = stod(fields[2]);
        city.lng = stod(fields[3]);

        if (isNumeric(fields[9])) {
            city.population = stol(fields[9]);
        } else {
            city.population = 0;
        }

        cities.push_back(city);
        counter++;
    }

    return cities;
}
