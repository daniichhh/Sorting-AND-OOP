#include "sorter.h"

void QuickSorter::sort(string key, int n) {
    quickSort(cities, key, 0, n - 1);
}

void QuickSorter::quickSort(vector<City>& arr, string key, int low, int high) {
    if (low < high) {
        int pi = partition(arr, key, low, high);
        quickSort(arr, key, low, pi - 1);
        quickSort(arr, key, pi + 1, high);
    }
}

int QuickSorter::partition(vector<City>& arr, string key, int low, int high) {
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
