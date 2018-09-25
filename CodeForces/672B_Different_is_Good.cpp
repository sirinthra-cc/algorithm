#include<iostream>
#include<vector>

using namespace std;


int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> dict(26);
    int count = 0;
    if(n > 26) {
        cout << -1 << endl;
        return 0;
    }
    for(int i=0; i<n; i++){
        int ss = s[i] - 'a';
        dict[ss]++;
    }
    int j = 0;
    for(int i=0; i<26; i++){
        while(dict[i] > 1){
            count++;
            dict[i]--;
            while(dict[j] > 0) j++;
            dict[j++]++;
        }
    }
    cout << count << endl;
    return 0;
}