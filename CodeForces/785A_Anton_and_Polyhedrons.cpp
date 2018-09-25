#include<iostream>

using namespace std;


int main(){
    int face_count = 0;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        if(s[0] == 'T') face_count += 4;
        else if(s[0] == 'C') face_count += 6;
        else if(s[0] == 'O') face_count += 8;
        else if(s[0] == 'D') face_count += 12;
        else if(s[0] == 'I') face_count += 20;
    }
    cout << face_count << endl;
    return 0;
}