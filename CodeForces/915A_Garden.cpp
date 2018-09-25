#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    for(int i=n-1; i>=0; i--){
        if(k % a[i] == 0){
            cout << k / a[i] << endl;
            return 0;
        }
    }
    return 0;
}