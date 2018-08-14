#include<vector>
#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;


bool is_glyph(vector<int> &real_w, vector<int> &current_w){
    for(int i=0; i<58; i++){
        if(real_w[i] != current_w[i]) return false;
    }
    return true;
}

int main(){
    int g, s_size;
    cin >> g >> s_size;
    string s = "";
    vector<int> real_w(58);
    fill(real_w.begin(), real_w.end(), 0);
    char wi;
    for(int i=0; i<g; i++){
        cin >> wi;
        real_w[wi - 'A']++;
    }
    char si;
    for(int i=0; i<s_size; i++){
        cin >> si;
        s += si; 
    }
    // cout << s << endl;
    vector<int> current_w(58);
    fill(current_w.begin(), current_w.end(), 0);
    for(int i=0; i<g; i++){
        current_w[s[i] - 'A']++;
    }
    int count = 0;
    if(is_glyph(real_w, current_w)) count++;
    for(int i=1; i<=s_size-g; i++){
        current_w[s[i-1] - 'A']--;
        current_w[s[i+g-1] - 'A']++;
        if(is_glyph(real_w, current_w)) count++;
    }
    cout << count << endl;
    return 0;
}