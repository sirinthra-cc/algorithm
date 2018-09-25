#include<iostream>
#include<vector>
#include<math.h>

using namespace std;


vector<int> get_binary(int x, int n){
    vector<int> result(n);
    for(int i=0; i<n; i++){
        result[i] = x/((int)pow(2, n-i-1));
        x %= (int) pow(2, n-i-1);
        // cout << result[i];
    }
    // cout << endl;
    return result;
}

bool is_friend(vector<int> &army, vector<int> &fedor_army, int k){
    int diff_count = 0;
    for(int i=0; i<army.size(); i++){
        if(army[i] != fedor_army[i]) diff_count++;
        if(diff_count > k) return false;
    }
    return true;
}

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> armies(m);
    int x;
    for(int i=0; i<m; i++) {
        cin >> x;
        armies[i] = get_binary(x, n);
    }
    cin >> x;
    vector<int> fedor_army;
    fedor_army = get_binary(x, n);

    int friend_count = 0;
    for(int i=0; i<m; i++){
        if(is_friend(armies[i], fedor_army, k)) friend_count++;
    }
    cout << friend_count << endl;
    return 0;
}