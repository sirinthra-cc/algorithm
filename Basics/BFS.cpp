#include<vector>
#include<queue>
#include<iostream>

using namespace std;


bool can_reach(vector<vector<int>> &g, int start_node, int end_node){
    queue<int> q;
    vector<bool> traveled_nodes(g.size());
    fill(traveled_nodes.begin(), traveled_nodes.end(), false);
    // push child of start node
    traveled_nodes[start_node] = true;    
    q.push(start_node);
    while(!q.empty()){
        int q_node = q.front();
        q.pop();
        if(q_node == end_node) return true;
        for(auto node: g[q_node]){
            if(!traveled_nodes[node]){
                traveled_nodes[q_node] = true;  // travel trong nee na jub jub 
                q.push(node);
            }
        }
    }
    return false;
}

void add_edge(vector<vector<int>> &g, int u, int v) {
    if(find(g[u].begin(), g[u].end(), v) == g[u].end()) {
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

int main(){
    vector<vector<int>> g;
    g.resize(6);
    add_edge(g, 1, 2);
    add_edge(g, 2, 3);
    add_edge(g, 3, 4);
    add_edge(g, 2, 4);
    bool result = can_reach(g, 1, 5);
    cout << result << endl;
    return 0;
}