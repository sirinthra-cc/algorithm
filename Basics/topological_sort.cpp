#include<vector>

using namespace std;


void dfs(int current_node, vector<vector<int>> &graph, vector<int> &order, 
        int &count, vector<bool> &visited, vector<int> node_order){
    visited[current_node] = true;
    for(auto node: graph[current_node]){
        if(!visited[node]){
            dfs(node, graph, order, count, visited);
        }
    }
    node_order.push_back(current_node);
    //order[current_node] = count;
    // count++;
    return;
}

vector<vector<int>> graph;
vector<int> node_order;
fill(order.begin(), order.end(), -1);
int count = 1;
for(int i=0; i<n_nodes; i++){
    if(!visited[i]){
        dfs(i, graph, order, count, node_order)
    }
}
node_order