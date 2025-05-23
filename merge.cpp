#include "sorter.h"

void MergeSorter::sort(string key, int n) {
    mergeSort(cities, key, 0, n - 1);
}

void MergeSorter::mergeSort(vector<City>& arr, string key, int left, int right) {
    if (left >= right) return;
    int mid = (left + right) / 2;
    mergeSort(arr, key, left, mid);
    mergeSort(arr, key, mid + 1, right);
    merge(arr, key, left, mid, right);
}

void MergeSorter::merge(vector<City>& arr, string key, int left, int mid, int right) {
    vector<City> temp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right) {
        if (compare(arr[i], arr[j], key)) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
        }
    }

    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= right) temp.push_back(arr[j++]);

    for (int k = 0; k < temp.size(); k++) {
        arr[left + k] = temp[k];
    }
}
