#include<vector>
#include<unordered_map>
#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;


int main(){
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    unordered_map<int, int> queries;  // query index and value
    int l, r;
    for(int i=0; i<q; i++){
        cin >> l >> r;
        l--;
        if(queries.find(l) == queries.end()) queries[l] = 1;
        else queries[l]++;
        if(queries.find(r) == queries.end()) queries[r] = -1;
        else if (r < arr.size()) queries[r]--;
    }
    int freq = 0;
    priority_queue<int> max_freq;
    for(int i=0; i<n; i++){
        if(queries.find(i) != queries.end()) freq += queries[i];
        if(freq > 0) max_freq.push(freq);
    }
    sort(arr.begin(), arr.end());
    long long result = 0;
    int i = arr.size() - 1;
    while(!max_freq.empty()) {
        result += (long long)max_freq.top() * (long long)arr[i];
        max_freq.pop();
        i--;
    }
    cout << result << endl;
    return 0;
}