#include<iostream>

using namespace std;


int main(){
    int len, n;
    cin >> len >> n;
    string previous_string;
    cin >> previous_string;
    string current_string;
    for(int i=1; i<n; i++){
        cin >> current_string;
        int count = 0;
        for(int j=0; j<len; j++){
            if(previous_string[j] != current_string[j]){
                count++;
            }
        }
        if(count > 2) {
            cout << previous_string << endl;
            return 0;
        }
        previous_string = current_string;
    }
    cout << previous_string << endl;
    return 0;
}