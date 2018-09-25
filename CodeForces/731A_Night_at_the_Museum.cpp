#include<iostream>
#include<algorithm>

using namespace std;


int main(){
    string s;
    cin >> s;
    int previous_i = 0;
    int sum = 0;
    for(int i=0; i<s.size(); i++){
        int next_i = s[i] - 'a';
        int left = previous_i - next_i;
        if(left < 0) left = previous_i - next_i + 26;
        int right = next_i - previous_i;
        if(right < 0) right = next_i - previous_i + 26;
        sum += min(left, right);
        previous_i = next_i;
    }
    cout << sum << endl;
    return 0;
}