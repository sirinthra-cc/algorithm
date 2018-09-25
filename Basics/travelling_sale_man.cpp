int get_min_distance(int start_node, int current_node, vector<pair<int,int>> &nodes, vector<bool> visited_nodes, 
                int visited_count, int distance){
    if(visited_count == nodes.size()) return get_eucidean_distance(current_node, start_node);
    int min_distance = INT_MAX;
    for(int i=0; i<nodes.size(); i++){
        if(!visited_nodes[i]){
            visited_nodes[i] = true;
            distance += get_eucidean_distance(current_node, node[i]);
            int distance = get_eucidean_distance(current_node, node[i]) + 
                            get_min_distance(start_node, node[i], nodes, visited_nodes, visited_count+1, distance);
            if(distance < min_distance) min_distance = distance;
        }
    }
    return min_distance;
}

int get_min_distance(int start_node, int current_node, vector<pair<int,int>> &nodes, vector<bool> &visited_nodes, int visited_count){
    if(visited_count == nodes.size()) return get_eucidean_distance(current_node, start_node);
    int min_distance = INT_MAX;
    for(int i=0; i<nodes.size(); i++){
        if(!visited_nodes[i]){
            visited_nodes[i] = true;
            int distance = get_eucidean_distance(current_node, node[i]) + 
                            get_min_distance(start_node, node[i], nodes, visited_nodes, visited_count+1, distance);
            visited_nodes[i] = false;
            if(distance < min_distance) min_distance = distance;
        }
    }
    return min_distance;
}