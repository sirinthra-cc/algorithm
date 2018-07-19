#include <stdio.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

class my_stack_int {
private:
    // Declare something here
    int capacity = 20;
    int _size = 0;
    int *arr = new int[20];
public:
    void push_back(int value) {
        arr[_size] = value;
        _size++;
        if(_size > capacity/2){
            capacity *= 2;
            int *new_arr = new int[capacity];
            for(int i=0; i<_size; i++){
                new_arr[i] = arr[i];
            }
            arr = new_arr;
        }
    }
    void pop_back() {
        if(_size == 0) cout << "error jaa" << endl;
        _size--;
        if(_size < capacity/4){
            capacity /= 2;
            int *new_arr = new int[capacity];
            for(int i=0; i<_size; i++){
                new_arr[i] = arr[i];
            }
            arr = new_arr;
        }
    }
    int back() {
        return arr[_size-1];
    }
    int size() {
        return _size;
    }
};

int main() {
    srand(0);
    for(int i=0;i<100;i++) {
        my_stack_int my_stack;
        vector<int> real_stack;
        int num_operation = rand() % 10000;
        bool is_wrong = false;
        for(int j=0;j<num_operation;j++) {
            if(my_stack.size() != real_stack.size()) {
                is_wrong = true;
                break;
            }
            if(my_stack.size() > 0) {
                if(rand() % 4 < 3) {
                    int num = rand();
                    my_stack.push_back(num);
                    real_stack.push_back(num);
                } else {
                    my_stack.pop_back();
                    real_stack.pop_back();
                }
            } else {
                int num = rand();
                my_stack.push_back(num);
                real_stack.push_back(num);
            }
            if(my_stack.size() > 0) {
                if(my_stack.back() != real_stack[real_stack.size() - 1]){
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