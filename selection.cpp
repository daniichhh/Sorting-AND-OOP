#include "sorter.h"
vector<City> Sorter::cities;
class SelectionSorter : public Sorter {
public:
    void sort(string key, int n) override {
        for (int i = 0; i < n - 1; i++) {
            int minIdx = i;
            for (int j = i + 1; j < n; j++) {
                if (compare(cities[j], cities[minIdx], key)) {
                    minIdx = j;
                }
            }
            swap(cities[i], cities[minIdx]);
        }
    }
};
