#include<vector>
#include<unordered_map>
#include<iostream>

using namespace std;


int main(){
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    unordered_map<int, bool> distinct_elements;
    vector<int> distinct_count(n+1);
    int count = 0;
    for(int i=n-1; i>=0; i--){
        if(distinct_elements.find(arr[i]) == distinct_elements.end()) {
            distinct_elements[arr[i]] = true;
            count++;
        }
        distinct_count[i+1] = count;
    }
    for(int i=0; i<m; i++) {
        int query;
        cin >> query;
        cout << distinct_count[query] << endl;
    }
    return 0;
}