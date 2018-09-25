#include<iostream>
#include<vector>

using namespace std;


int main(){
    string s;
    cin >> s;
    int i = 0;
    int j = 1;
    bool found = false;
    for(int i=0; i<s.size(); i++){
        if(s[i] == '0' || s[i] == '8'){
            cout << "YES" << endl;
            cout << s[i] << endl;
            return 0;
        } else {
            for(int j=i+1; j<s.size(); j++){
                if(
                    (s[i] == '1' && s[j] == '6') ||
                    (s[i] == '2' && s[j] == '4') ||
                    (s[i] == '3' && s[j] == '2') ||
                    (s[i] == '4' && s[j] == '0') ||
                    (s[i] == '4' && s[j] == '8') ||
                    (s[i] == '5' && s[j] == '6') ||
                    (s[i] == '6' && s[j] == '4') ||
                    (s[i] == '7' && s[j] == '2') ||
                    (s[i] == '8' && s[j] == '0') ||
                    (s[i] == '8' && s[j] == '8') ||
                    (s[i] == '9' && s[j] == '6')
                ){
                    cout << "YES" << endl;
                    cout << s[i] << s[j] << endl;
                    return 0;
                }
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}