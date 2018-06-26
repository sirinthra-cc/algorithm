#include<vector>

using namespace std;

int index_of(vector<int> a, int wanted_number){
    int first = 0;
    int last = a.size() - 1;
    int middle;
    while(first < last) {
        middle = (first + last) / 2;
        if(a[middle] < wanted_number) last = middle;
        else first = middle + 1;       
    }
    // if not found - first = index of next greater value
    if(a[first] != wanted_number) return -1;
    return first;
}