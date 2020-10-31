
#ifndef LAB8_QUICKSELECT_H
#define LAB8_QUICKSELECT_H

#include <iostream>
#include <vector>
using namespace std;

class quickSelect {
public:
    int lomutoPartition(vector<int> &v, int l, int r);

    int lomutoQuickSelect(vector<int> &v, int l, int r, int rank);

    int hoarePartition(vector<int> &v, int l, int r);

    int hoareQuickSelect(vector<int> &v, int l, int r, int rank);

    void hoareQuickSort(vector<int> &v, int l, int r);

    void lomutoQuickSort(vector<int> &v, int l, int r);
};


#endif //LAB8_QUICKSELECT_H
