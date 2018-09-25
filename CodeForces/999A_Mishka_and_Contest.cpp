#include<iostream>
#include<vector>

using namespace std;


int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int count = 0;
    int i = 0;
    while(i < n && a[i] <= k) {
        count++;
        i++;
    }
    int j = n - 1;
    while(j > i && a[j] <= k) {
        count++;
        j--;
    }
    cout << count << endl;
    return 0;
}