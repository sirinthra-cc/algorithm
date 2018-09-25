#include<iostream>
#include<vector>

using namespace std;


int main(){
    int n, c;
    cin >> n >> c;
    vector<int> x(n);
    for(int i=0; i<n; i++) cin >> x[i];
    int max_diff = 0;
    for(int i=1; i<n; i++){
        if(x[i-1] - x[i] > max_diff) max_diff = x[i-1] - x[i];
    }
    max_diff -= c;
    if(max_diff >= 0) cout << max_diff << endl;
    else cout << 0 << endl;
    return 0;
}