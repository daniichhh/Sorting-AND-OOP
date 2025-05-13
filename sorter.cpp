#include "sorter.h"

vector<City> Sorter::cities;

bool Sorter::compare(City a, City b, string key) {
    if (key == "name") return a.name < b.name;
    if (key == "country") return a.country < b.country;
    if (key == "lat") return a.lat < b.lat;
    if (key == "lng") return a.lng < b.lng;
    if (key == "population") return a.population < b.population;
    return false;
}
