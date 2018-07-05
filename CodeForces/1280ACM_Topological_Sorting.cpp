#include<iostream>
#include<vector>

using namespace std;


// void dfs(int current_node, vector<vector<int>> &graph, vector<bool> &visited){

// }

int main(){
    int nodes, edges;
    cin >> nodes >> edges;
    vector<vector<int>> graph(nodes+1);
    for(int i=1; i<=edges; i++){
        int before, after;
        cin >> before >> after;
        graph[after].push_back(before);
    }
    vector<int> answer(nodes+1);
    for(int i=1; i<=nodes; i++){
        cin >> answer[i];
    }
    vector<bool> visited(nodes+1);
    bool is_correct = true;
    for(int i=1; i<=nodes; i++){
        int current_node = answer[i];
        for(auto node: graph[current_node]){
            if(!visited[node]) is_correct = false;
        }
        visited[current_node] = true;
    }
    if(is_correct) cout << "YES" << endl;
    else cout << "NO" << endl;
    
    return 0;
}