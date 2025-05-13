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


vector<City> readFile(string filename, int n) {
    vector<City> cities;
    ifstream file(filename);
    string line;
    int counter = 0;

    getline(file, line);

    while (getline(file, line) && counter < n) {
        vector<string> fields = getData(line);

        if (fields.size() < 11) continue;

        City city;
        city.name = fields[1];
        city.country = fields[4];
        city.lat = stod(fields[2]);
        //city.lng = stod(fields[3]);

        city.population = fields[9].empty() ? 0 : stol(fields[9]);
        city.lng = stod(fields[3]);
        /*try {
    		city.population = fields[9].empty() ? 0 : stol(fields[9]);
		} catch (invalid_argument&) {
    		continue;
		}*/

        cities.push_back(city);
        counter++;

    }

    return cities;
}


