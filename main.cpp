//Lab 26|COMSC 210|Ismael Hadi
#include <iostream>
#include <chrono>
#include <set>
#include <list>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
using namespace chrono;
const string S = "TEST_CODE";
const int RUN_NUM = 15;

//function protypes for functions that add elements for every container type
void add_item(vector<string> &v, const string &s);
void add_item(list<string> &l, const string &s);
void add_item(set<string> &se, const string &s);

//read time calculator function that works for all three data types
template <typename Container>
int readTime(Container &c);

//sort functions for vectors and lists, respectively
void sort_c(vector<string> &v);
void sort_c(list<string> &l);

//sort time function that works for vectors and lists
template <typename Container>
int sortTime(Container &c);

//function protypes for indivual middle insertion functions
void insert_c(vector<string> &v);
void insert_c(list<string> &l);
void insert_c(set<string> &se);

//data type indepent timer for insertion
template <typename Container>
int insertTime(Container &c);

//function prototypes for middle element deletion for each type
void delete_c(vector<string> &v);
void delete_c(list<string> &l);
void delete_c(set<string> &se);

//middle element deletion timer prototype, data type independent
template <typename Container>
int deleteTime(Container &c);

int main() {
    list<string> myList;
    set<string> mySet;
    vector<string> myVec;
  

    //Output table for timers
    const int W1 = 12;
    const int W = 14;
    long long arr[4][3] = {
        {readTime(myVec), readTime(myList), readTime(mySet)},
    };
    list<string> sortList = myList;
    vector<string> sortVec = myVec;
    list<string> insertList = myList;
    vector<string> insertVec = myVec;
    set<string> insertSet = mySet;
    list<string> deleteList = myList;
    vector<string> deleteVec = myVec;
    set<string> deleteSet = mySet;
    arr[1][0] = sortTime(sortVec);
    arr[1][1] = sortTime(sortList);
    arr[1][2] = -1;
    
    arr[2][0] = insertTime(insertVec);
    arr[2][1] = insertTime(insertList);
    arr[2][2] = insertTime(insertSet);

    arr[3][0] = deleteTime(deleteVec);
    arr[3][1] = deleteTime(deleteList);
    arr[3][2] = deleteTime(deleteSet);

    long long narr[2][4][3];
    for (int i = 0; i < RUN_NUM; i++) {
        list<string> myList;
        set<string> mySet;
        vector<string> myVec;
        long long arr[4][3] = {
            {readTime(myVec), readTime(myList), readTime(mySet)},
            };
        list<string> sortList = myList;
        vector<string> sortVec = myVec;
        list<string> insertList = myList;
        vector<string> insertVec = myVec;
        set<string> insertSet = mySet;
        list<string> deleteList = myList;
        vector<string> deleteVec = myVec;
        set<string> deleteSet = mySet;
        arr[1][0] = sortTime(sortVec);
        arr[1][1] = sortTime(sortList);
        arr[1][2] = -1;
        
        arr[2][0] = insertTime(insertVec);
        arr[2][1] = insertTime(insertList);
        arr[2][2] = insertTime(insertSet);

        arr[3][0] = deleteTime(deleteVec);
        arr[3][1] = deleteTime(deleteList);
        arr[3][2] = deleteTime(deleteSet);

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; i++) {
                narr[0][i][j] = arr[i][j];
                narr[i][i][j] += arr[i][j]; 
            }
        }
    }
    
    

    cout << left << setw(W1) << "" << right << setw(W) << "Vector" << setw(W) << "List" << setw(W) << "Set" << endl;
    cout << left << setw(W1) << "Read time:" << right << setw(W) << arr[0][1] << setw(W) << arr[0][2] << setw(W) << arr[0][3]<< endl;
    cout << left << setw(W1) << "Sort time:" << right << setw(W) << arr[1][1] << setw(W) << arr[1][2] << setw(W) << arr[1][3] << endl;
    cout << left << setw(W1) << "Insert time:" << right << setw(W) << arr[2][1] << setw(W) << arr[2][2] << setw(W) << arr[2][3] << endl;
    cout << left << setw(W1) << "Delete time:" << right << setw(W) << arr[3][1] << setw(W) << arr[3][2] << setw(W) << arr[3][3] << endl;
    return 0;
}

//functions that add elements for every container type
void add_item(vector<string> &v, const string &s) {
    v.push_back(s);
}

void add_item(list<string> &l, const string &s) {
    l.push_back(s);
}

void add_item(set<string> &se, const string &s) {
    se.insert(s);
}

//read time calculator function that works for all three data types
template <typename Container>
int readTime(Container &c) {
    ifstream fin("codes.txt");
    string line;
    auto start = high_resolution_clock::now();
    while (getline(fin, line)) {
        add_item(c,line);
    }
    auto end = high_resolution_clock::now();
    fin.close();
    auto duration = duration_cast<nanoseconds>(end-start);
    return (int)duration.count();
}

//sort functions for vectors and lists, respectively

//selection sort borrowed from zybooks
void sort_c(vector<string> &v) {
    for (int i = 0; i < (v.size()-1); i++) {
        int idxSmallest = i;
        for (int j = i+1; j < v.size(); j++) {
            if (v[j] < v[idxSmallest]) {
                idxSmallest = j;
            }
        }
        string temp = v[i];
        v[i] = v[idxSmallest];
        v[idxSmallest] = temp;
    }
}
void sort_c(list<string> &l) {
    l.sort();
}

//sort time function that works for vectors and lists
template <typename Container>
int sortTime(Container &c) {
    ifstream fin("codes.txt");
    string line;
    auto start = high_resolution_clock::now();
    sort_c(c);
    auto end = high_resolution_clock::now();
    fin.close();
    auto duration = duration_cast<nanoseconds>(end-start);
    return (int)duration.count();
}

//functions for individual middle insertion
void insert_c(vector<string> &v) {
    v.insert(v.begin() + v.size()/2, S);
}
void insert_c(list<string> &l) {
    auto it = l.begin();
    advance(it, l.size()/2);
    l.insert(it, S);
}
void insert_c(set<string> &se) {
    se.insert(S);
}

//data type indepent timer for insertion
template <typename Container>
int insertTime(Container &c) {
    ifstream fin("codes.txt");
    string line;
    auto start = high_resolution_clock::now();
    insert_c(c);
    auto end = high_resolution_clock::now();
    fin.close();
    auto duration = duration_cast<nanoseconds>(end-start);
    return (int)duration.count();
}

//functions for middle element deletion for each type
void delete_c(vector<string> &v) {
    v.erase(v.begin()+v.size()/2);
}
void delete_c(list<string> &l) {
    auto it = l.begin();
    advance(it, l.size()/2);
    l.erase(it);
}
void delete_c(set<string> &se) { 
    auto it = se.begin();
    advance(it, se.size()/2);
    se.erase(it);
}

//middle element deletion timer, data type independent
template <typename Container>
int deleteTime(Container &c) {
    ifstream fin("codes.txt");
    string line;
    auto start = high_resolution_clock::now();
    delete_c(c);
    auto end = high_resolution_clock::now();
    fin.close();
    auto duration = duration_cast<nanoseconds>(end-start);
    return (int)duration.count();
}
