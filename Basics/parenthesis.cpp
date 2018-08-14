#include<iostream>

using namespace std;


void count_parenthesis(int open_count, int close_count, int n, int &count){
    if(close_count == n && open_count == n){
        count++;
    } else {
        if(open_count - close_count >= 1) count_parenthesis(open_count, close_count + 1, n, count);
        if(open_count < n) count_parenthesis(open_count + 1, close_count, n, count);
    }
}

int main(){
    int n = 4;
    int count = 0;
    count_parenthesis(0, 0, n, count);
    cout << count << endl;
    return 0;
}