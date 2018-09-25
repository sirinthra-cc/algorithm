#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> numbers(n);
    for(int i=0; i<n; i++) {
        cin >> numbers[i];
        while(numbers[i] % 3 == 0) numbers[i] /= 3;
        while(numbers[i] % 2 == 0) numbers[i] /= 2;
    }
    bool found = true;
    for(int i=1; i<n; i++) {
        if(numbers[i] != numbers[0]) {
            found = false;
            break;
        }
    }
    if(found) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}