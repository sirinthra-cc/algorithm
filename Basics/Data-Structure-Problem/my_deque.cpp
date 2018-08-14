#include <deque>
#include <vector>
#include <iostream>
using namespace std;

class my_deque_int {
private:
    // Declare something here
    int first_index = 0;
    int last_index = 0;
    int _size = 0;
    int capacity = 20;
    int *arr = new int[20];

    void resize(){
        int *new_arr = new int[capacity];
        int j = 0;
        if(last_index < first_index){
            for(int i=first_index; i<capacity; i++){
                new_arr[j] = arr[i];
                j++;
            }
            for(int i=0; i<=last_index; i++){
                new_arr[j] = arr[i];
                j++;
            }
        } else {
            for(int i=first_index; i<=last_index; i++){
                new_arr[j] = arr[i];
                j++;
            }
        }
        arr = new_arr;
    }

    int get_index(int index){
        index %= capacity;
        if(index < 0) index += capacity;
        return index;
    }

public:
    void push_back(int value) {
        // Implement here
        if(_size != 0) last_index++;
        last_index = get_index(last_index);
        arr[last_index] = value;
        _size++;
        if(_size > capacity/2){
            capacity*=2;
            resize();
        }
    }
    void pop_back() {
        // Implement here
        last_index--;
        last_index = get_index(last_index);
        _size--;
        if(_size < capacity/4){
            capacity/=2;
            resize();
        }
    }
    void push_front(int value) {
        // Implement here
        if(_size != 0) first_index--;
        first_index = get_index(first_index);
        arr[first_index] = value;
        _size++;
        if(_size > capacity/2){
            capacity*=2;
            resize();
        }
    }
    void pop_front() {
        // Implement here
        first_index++;
        first_index = get_index(first_index);
        _size--;
        if(_size < capacity/4){
            capacity/=2;
            resize();
        }
    }
    int front() {
        // Implement here
        return arr[first_index];
    }
    int back() {
        // Implement here
        return arr[last_index];
    }
    int size() {
        return _size;
    }
};

int main() {
    srand(0);
    // for(int i=0;i<100;i++) {
        my_deque_int my_deque;
        //deque<int> my_deque;
        deque<int> real_deque;
        int num_operation = rand() % 50;
        bool is_wrong = false;
        for(int j=0;j<num_operation;j++) {
            if(my_deque.size() != real_deque.size()) {
                is_wrong = true;
                break;
            }
            if(my_deque.size() > 0) {
                if(rand() % 4 < 3) {
                    int num = rand();
                    if(rand() % 2) {
                        my_deque.push_back(num);
                        real_deque.push_back(num);
                    } else {
                        my_deque.push_front(num);
                        real_deque.push_front(num);
                    }
                } else {
                    if(rand() % 2) {
                        my_deque.pop_back();
                        real_deque.pop_back();
                    } else {
                        my_deque.pop_front();
                        real_deque.pop_front();
                    }
                }
            } else {
                int num = rand();
                if(rand() % 2) {
                    my_deque.push_back(num);
                    real_deque.push_back(num);
                } else {
                    my_deque.push_front(num);
                    real_deque.push_front(num);
                }
            }
            if(my_deque.size() > 0) {
                if(my_deque.back() != real_deque.back()){
                    is_wrong = true;
                    cout << my_deque.back() << " " << real_deque.back() << endl;
                    break;
                }
                if(my_deque.front() != real_deque.front()){
                    is_wrong = true;
                    break;
                }
            }
            if(is_wrong) break;
        }
        cout << (is_wrong ? "Wrong" : "Correct") << endl;
        cout << (-1 % 3) << endl;
    // }
}