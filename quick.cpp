#include "sorter.h"
vector<City> Sorter::cities;
class QuickSorter : public Sorter {
public:
    void sort(string key, int n) override {
        quickSort(cities, key, 0, n - 1);
    }

private:
    void quickSort(vector<City>& arr, string key, int low, int high) {
        if (low < high) {
            int pi = partition(arr, key, low, high);
            quickSort(arr, key, low, pi - 1);
            quickSort(arr, key, pi + 1, high);
        }
    }

    int partition(vector<City>& arr, string key, int low, int high) {
        City pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (compare(arr[j], pivot, key)) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return i + 1;
    }
};
