// DFS from A to B


bool dfs(vector<vector<int>> &graph, vector<bool> &visited_nodes, int current_node, int &target_node, 
        vector<int> &parent_nodes){
    visited_nodes[current_node] = true;
    if(current_node == target_node) return true;
    bool found = false;
    for(auto node: graph[current_node]){
        if(!visited_nodes[node]){
            parent_nodes[node] = current_node;
            found = dfs(graph, visited_nodes, node, target_node, parent_nodes);
            if(found) break;
        }
    }
    return found;
}

void get_path(vector<vector<int>> &graph, vector<bool> &visited_nodes, int start_node, int &target_node){
    vector<int> parent_nodes(visited_nodes.size());
    fill(parent_nodes.begin(), parent_nodes.end(), -1);
    bool found = dfs(graph, visited_nodes, start_node, target_node, parent_nodes);
    if(found){
        vector<int> result;
        int i = target_node;
        while(i != start_node){
            result.append(i);
            i = parent_nodes[i];
        }
        for(int j=result.size()-1; j>=0; j--){
            cout << result[j] << " ";
        }
    } else cout >> "No path to target node";
}