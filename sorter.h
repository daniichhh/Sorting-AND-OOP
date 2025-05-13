#ifndef SORTER_H
#define SORTER_H

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
    bool compare(City a, City b, string key);
};

class BubbleSorter : public Sorter {
public:
    void sort(std::string key, int n) override;
};

class SelectionSorter : public Sorter {
public:
    void sort(std::string key, int n) override;
};

class MergeSorter : public Sorter {
public:
    void sort(std::string key, int n) override;
private:
    void mergeSort(vector<City>& arr, string key, int left, int right);
    void merge(vector<City>& arr, string key, int left, int mid, int right);
};

class QuickSorter : public Sorter {
public:
    void sort(std::string key, int n) override;

private:
    void quickSort(vector<City>& arr, string key, int low, int high);
    int partition(vector<City>& arr, string key, int low, int high);
};
#endif // SORTER_H
