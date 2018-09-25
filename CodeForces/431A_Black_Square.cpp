#include<iostream>
#include<vector>

using namespace std;


int main(){
    vector<int> cal(4);
    for(int i=0; i<4; i++){
        cin >> cal[i];
    }
    string s;
    cin >> s;
    int total_cal = 0;
    for(auto ss: s){
        total_cal += cal[ss-'1'];
    }
    cout << total_cal << endl;
    return 0;
}