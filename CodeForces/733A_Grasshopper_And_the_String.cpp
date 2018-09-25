#include<iostream>

using namespace std;


int main(){
    string s;
    cin >> s;
    // ABABBBACFEYUKOTT
    int previous_i = -1;
    int max_distance = 0;
    int distance = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'Y'){
            distance = i - previous_i;
            previous_i = i;
        }
        if(distance > max_distance) max_distance = distance;
    }
    distance = s.size() - previous_i;
    if(distance > max_distance) max_distance = distance;
    cout << max_distance << endl;
    return 0;
}