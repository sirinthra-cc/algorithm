#include<unordered_map>
#include<iostream>

using namespace std;


int main(){
    int n;
    cin >> n;
    unordered_map<string, int> database;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        if(database.find(s) == database.end()) {
            database[s] = 0;
            cout << "OK" << endl;
        }
        else {
            database[s]++;
            cout << s << database[s] << endl;
        }
    }
}