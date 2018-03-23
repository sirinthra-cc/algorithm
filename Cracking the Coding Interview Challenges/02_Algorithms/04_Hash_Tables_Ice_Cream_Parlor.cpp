#include <bits/stdc++.h>

using namespace std;

void print(int i, int j){
    if(i < j) cout << i << " " << j << endl;
    else cout << j << " " << i << endl;
}

void solve(vector <int> arr, int money) {
    // Complete this function
    unordered_map<int, int> bin; // value -> index
    for(int i=0; i<arr.size(); i++){
        if(arr[i] >= money) continue;
        if(money%2==0 && arr[i]==money/2 && bin.find(arr[i]) != bin.end()) bin[0] = i+1;
        else bin[arr[i]] = i+1;
    }
    
    for(auto x: bin){
        if(!(money%2==0 && x.first==money/2) && bin.find(money - x.first) != bin.end()){
            print(x.second, bin[money-x.first]);
            return;
        }
    }
    print(bin[money/2], bin[0]);
    return;
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int money;
        cin >> money;
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int arr_i = 0; arr_i < n; arr_i++){
           cin >> arr[arr_i];
        }
        solve(arr, money);
    }
    return 0;
}
