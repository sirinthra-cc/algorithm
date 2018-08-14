#include <unordered_map>
#include <iostream>
using namespace std;
int main() {
    unordered_map<int,int> my_unordered_map;
    for(int i=0;i<1000;i++) {
        my_unordered_map[i*i % 17] = i;
    }
    for(auto row: my_unordered_map) {
        cout << row.first << " " << row.second << endl;
    }
}