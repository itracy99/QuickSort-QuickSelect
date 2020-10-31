
#include "quickSelect.h"

int quickSelect::lomutoPartition(vector<int> &v, int l, int r) {
    int p = v[l];
    int s = l;
    for(int i = s+1; i<= r; i++){
        if(v[i] < p){
            s++;
            swap(v[s], v[i]);
        }
    }
    swap(v[l], v[s]);
    return s;
}

int quickSelect::lomutoQuickSelect(vector<int> &v, int l, int r, int rank) {
    if( l <= r){
        int s = lomutoPartition(v, l, r);
        if(s == rank-1){
            return v[s];
        }else if(s > rank -1){
            return lomutoQuickSelect(v, l , s-1, rank);
        }else{
            return lomutoQuickSelect(v, s+1, r, rank);
        }
    }else{
        //should never get here
        throw runtime_error("lomutoQuickSelect");
    }
}

int quickSelect::hoarePartition(vector<int> &v, int l, int r) {
    int p = v[l];
    int i = l;
    int j = r+1;
    do{
        do{
            i++;
        }while (v[i]<p);
        do{
            j--;
        }while(v[j]>p);
        swap(v[i], v[j]);
    }while(i<j);

    swap(v[i], v[j]);
    swap(v[l], v[j]);

    return j;
}

int quickSelect::hoareQuickSelect(vector<int> &v, int l, int r, int rank) {
    if( l <= r){
        int s = hoarePartition(v, l, r);
        if(s == rank-1){
            return v[s];
        }else if(s > rank -1){
            return hoareQuickSelect(v, l , s-1, rank);
        }else{
            return hoareQuickSelect(v, s+1, r, rank);
        }
    }else{
        //should never get here
        throw runtime_error("hoareQuickSelect");
    }
}

void quickSelect::lomutoQuickSort(vector<int> &v, int l, int r) {
    if(l<r){
        int s = lomutoPartition(v, l, r);
        lomutoQuickSort(v, l, s-1);
        lomutoQuickSort(v, s+1, r);
    }
}

void quickSelect::hoareQuickSort(vector<int> &v, int l, int r) {
    if(l<r){
        int s = hoarePartition(v, l, r);
        hoareQuickSort(v, l, s-1);
        hoareQuickSort(v, s+1, r);
    }
}