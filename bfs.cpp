// Shortest path from A to B


void get_path(vector<vector<int>> &graph, int start_node, int &target_node){
    vector<bool> visited_nodes(graph.size());
    vector<int> parent_nodes(graph.size());
    fill(parent_nodes.begin(), parent_nodes.end(), -1);
    queue<int> to_visit_nodes;
    to_visit_nodes.push(start_node);
    visited_nodes[start_node] = True;
    bool found = false;
    while(!to_visit_nodes.empty()){
        int current_node = to_visit_nodes.front();
        to_visit_nodes.pop();
        if(current_node == target_node) {
            found = true;
            break;
        }
        for(auto node: graph[current_node]){
            if(!visited_nodes[node]){
                visited_nodes[node] = true;
                parent_nodes[node] = current_node;
            }
        }
    }
    if(found){
        vector<int> result;
        int i = target_node;
        while(i != start_node){
            result.append(i);
        }
        for(int j=result.size()-1; j>=0; j--){
            cout << result[j] << " ";
        }
    } else cout >> "No path to target node";
}