#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "chronometer.h"
#include "quickSelect.h"
using namespace std;


vector<int> readFile(string filename){
    vector<int> v;
   ifstream file;
   if(!file.fail()) {
       file.open(filename);
       while (!file.eof()) {
           string temp;
           stringstream tempss;
           int itemp;
           getline(file, temp);
           tempss << temp;
           tempss >> itemp;
           v.push_back(itemp);
       }
   }else{
       cout << "File doesn't exist." << endl;
   }
   file.close();
    return v;

}

int main() {
    cout << "Please enter the file name: " << endl;
    string filename;
    cin >> filename;
    vector<int> v = readFile(filename);
    Chronometer c;
    quickSelect qs;
    int size = v.size();
    int choice;
    cout << "Enter 1 if you wish to quickSelect and 2 if you wish to quickSort" << endl;
    cin >> choice;
    if(choice == 1) {
        int input;
        cout << "Please enter the rank: " << endl;
        cin >> input;
        while (input > 0) {
            c.start();
            qs.hoareQuickSelect(v, 0, size - 1, input);
            c.pause();
            cout << "Hoare Quick Select time: " << c.time() << endl;

            c.reset();

            c.start();
            qs.lomutoQuickSelect(v, 0, size - 1, input);
            c.pause();
            cout << "Lomuto Quick Select time: " << c.time() << endl << endl;


            cout << "To exit please enter 0 or a negative number." << endl;
            cout << "Please enter another rank: " << endl;
            cin >> input;
        }
    }else if(choice == 2){
        int in;
        cout << "Enter 1 for Lomuto and 2 for Hoare." << endl;
        cin >> in;
        if(in == 1){
            c.start();
            qs.lomutoQuickSort(v, 0, size);
            c.pause();
            cout << "Lomuto Quick Sort time: " << c.time() << endl << endl;
        }else if(in == 2){
            c.start();
            qs.hoareQuickSort(v, 0, size);
            c.pause();
            cout << "Hoare Quick Sort time: " << c.time() << endl << endl;
        }
    }else{
        cout << "GoodBye!" << endl;
    }
    cout << "GoodBye!" << endl;
    return 0;
}

