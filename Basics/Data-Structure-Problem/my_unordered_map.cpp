#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <stdlib.h>
#include <stdexcept>
using namespace std;

class my_unordered_map_int_int {
private:
    // Declare something here
    vector<vector<pair<int, int>>> my_map;  // pair of key and value
    int capacity = 20;
    int _size = 0;

    int hash_function(int key) {
        int transformed_key = (key ^ 123456789);
        if(transformed_key < 0)
            transformed_key = -transformed_key;
        return transformed_key;
    }
public:
    my_unordered_map_int_int() {
        my_map.resize(20);
    }
    void hash(int key, int value) {
        //cout << "hashing" << endl;
        _size++;
        if(_size > capacity/2){
            capacity *= 2;
            vector<vector<pair<int, int>>> new_my_map;
            new_my_map.resize(capacity);
            for(auto v: my_map){
                for(auto p: v){
                    int hashed_key = hash_function(p.first) % capacity;
                    new_my_map[hashed_key].push_back(make_pair(p.first, p.second));
                }
            }
            my_map = new_my_map;
        }
        int hashed_key = hash_function(key) % capacity;
        if(getValue(key) == -1){
            my_map[hashed_key].push_back(make_pair(key, value));
        } else {
            for(int i=0;i<my_map[hashed_key].size();i++) {
                if(my_map[hashed_key][i].first == key) my_map[hashed_key][i].second = value;
            }
            // cout << "Overwriting" << endl;
            // for(auto p: my_map[hashed_key]){
            //     if(p.first == key) p.second = value;
            // }
        }
    }
    int getValue(int key) {
        //cout << "getting" << endl;
        int hashed_key = hash_function(key) % capacity;
        for(auto p: my_map[hashed_key]){
            if(p.first == key) return p.second;
        }
        return -1;
        //throw std::invalid_argument( "received unhashed key" );
    }
};

int main() {
    srand(0);
    for(int i=0;i<100;i++) {
        my_unordered_map_int_int my_test_unordered_map;
        map<int,int> test_map;
        int num_operation = rand() % 1000;
        bool is_wrong = false;
        for(int j=0;j<num_operation;j++) {
            int key = rand() % 10;
            int value = rand();
            test_map[key] = value;
            my_test_unordered_map.hash(key, value);

            for(auto row: test_map) {
                if(my_test_unordered_map.getValue(row.first) != row.second) {
                    is_wrong = true;
                    break;
                }
            }
            if(is_wrong)
                break;
        }
        cout << (is_wrong ? "Wrong" : "Correct") << endl;
    }
}