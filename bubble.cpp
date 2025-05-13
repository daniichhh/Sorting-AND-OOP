#include "sorter.h"
vector<City> Sorter::cities;
class BubbleSorter : public Sorter {
public:
    void sort(string key, int n) override {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (!compare(cities[j], cities[j + 1], key)) {
                    swap(cities[j], cities[j + 1]);
                }
            }
        }
    }
};
