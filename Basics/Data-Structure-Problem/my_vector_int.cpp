#include <stdio.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

class my_vector_int {
private:
    int capacity = 20;
    int _size = 0;
    int* arr = new int[20];
public:
    void push_back(int value) {
        arr[_size] = value;
        _size++;
        if(_size > capacity/2){
            capacity *= 2;
            int* new_arr = new int[capacity];
            for(int i=0; i<_size; i++){
                new_arr[i] = arr[i];
            }
            arr = new_arr;
        }
    }
    void pop_back() {
        _size--;
        if(_size < capacity/4){
            capacity /= 2;
            int* new_arr = new int[capacity];
            for(int i=0; i<_size; i++){
                new_arr[i] = arr[i];
            }
            arr = new_arr;
        }
    }
    int size() {
        return _size;
    }

    int operator[](int index) {
        return arr[index];
    }
};

int main() {
    srand(0);
    for(int i=0;i<100;i++) {
        my_vector_int my_vector;
        vector<int> real_vector;
        int num_operation = rand() % 10000;
        bool is_wrong = false;
        for(int j=0;j<num_operation;j++) {
            if(my_vector.size() != real_vector.size()) {
                is_wrong = true;
                break;
            }
            if(my_vector.size() > 0) {
                if(rand() % 4 < 3) {
                    int num = rand();
                    my_vector.push_back(num);
                    real_vector.push_back(num);
                } else {
                    my_vector.pop_back();
                    real_vector.pop_back();
                }
            } else {
                int num = rand();
                my_vector.push_back(num);
                real_vector.push_back(num);
            }
            for(int k=0;k<my_vector.size();k++) {
                if(my_vector[k] != real_vector[k]) {
                    is_wrong = true;
                }
            }
            if(is_wrong)
                break;
        }
        cout << (is_wrong ? "Wrong" : "Correct") << endl;
    }
}