#include<iostream>
#include<vector>

using namespace std;


int main(){
    int n, d;
    cin >> n >> d;
    int max_con = 0;
    int con = 0;
    for(int i=0; i<d; i++){
        string s;
        cin >> s;
        bool found_0 = false;
        for(int j=0; j<n; j++){
            if(s[j] == '0') {
                con++;
                found_0 = true;
                break;
            }
        }
        if(!found_0) con = 0;
        if(con > max_con) max_con = con;
    }
    cout << max_con << endl;
    return 0;
}