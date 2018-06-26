#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include<unordered_map>

using namespace std;


bool check_include(vector<int> &to_travel_nodes, vector<vector<int>> &a, 
                    unordered_map<int, bool> &travelled_nodes){
    if(to_travel_nodes.size() == 0) return false;
    bool result = false;
    for(int j=0; j<to_travel_nodes.size(); j++){
        if(travelled_nodes.find(to_travel_nodes[j]) == travelled_nodes.end()) {
            travelled_nodes[to_travel_nodes[j]] = true;
            result = check_include(a[to_travel_nodes[j]], a, travelled_nodes);
            if(result) return true;
        } else {
            return true;
        }
    }  
    return false;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> a;
    a.resize(n);
    for(int i=0; i<n; i++){
        int k;
        cin >> k;
        for(int j=0; j<k; j++){
            int aj;
            cin >> aj;
            a[i].push_back(aj-1);
        }
    }
    // Check include
    for(int i=0; i<n; i++){
        unordered_map<int, bool> travelled_nodes; 
        bool result = check_include(a[i], a, travelled_nodes);
        if(result) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}

