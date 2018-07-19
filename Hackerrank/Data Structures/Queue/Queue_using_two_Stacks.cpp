#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    cin >> n;
    stack<int> s1;
    stack<int> s2;
    for(int i=0; i<n; i++){
        int operation, x;
        cin >> operation;
        if(operation == 1){
            cin >> x;
            s1.push(x);
        } else if(operation == 2){
            // dequeue
            if(!s2.empty()) s2.pop();
            else {
                while(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }
                s2.pop();
            }
        } else if(operation == 3){
            // front
            if(!s2.empty()) {
            } else {
                while(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            cout << s2.top() << endl;
        }
    }
    return 0;
}
