#include "sorter.h"

void SelectionSorter::sort(string key, int n){
        for (int i = 0; i < n - 1; i++) {
            int minIdx = i;
            for (int j = i + 1; j < n; j++) {
                if (compare(cities[j], cities[minIdx], key)) {
                    minIdx = j;
                }
            }
            swap(cities[i], cities[minIdx]);
        }
    };
