#include<unordered_map>
#include<iostream>
#include<vector>

using namespace std;


int main(){
    int n;
    cin >> n;
    vector<vector<int>> graph(n+1);
    for(int i=2; i<=n; i++){
        int node;
        cin >> node;
        graph[node].push_back(i);
    }
    for(int node=1; node<=n; node++){
        if(graph[node].size() != 0){
            int leaf_count = 0;
            for(auto child: graph[node]){
                if(graph[child].size() == 0) leaf_count++;
            }
            if(leaf_count < 3) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}