#include<iostream>

using namespace std;


int main(){
    string s;
    cin >> s;
    string result = "";
    bool removed = false;
    for(int i=0; i<s.size(); i++){
        if(!removed && s[i] == '0'){
            removed = true;
        } else if (i == s.size()-1 && !removed){
            removed = true;
        } else {
            result += s[i];
        }
    }
    cout << result << endl;
    return 0;
}