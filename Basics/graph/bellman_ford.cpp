vector<vector<int>> bellman_ford(vector<pair<int,pair<int,int>>> distance_from_to_vector) {
    // distance ติดลบได้ (Dijkstra ทำได้แค่ +)
    // check negetive cycle ได้
    // O(VE)
    vector<int> shortest_paths;
    shortest_paths.resize(graph.size());
    fill(shortest_paths.begin(), shortest_paths.end(), 100000000);
    shortest_paths[0] = 0;

    int num_node = graph.size();
    for(int i=0;i<num_node;i++){
        for(int j=0;j<distance_from_to_vector.size();j++) {
            int weight = distance_from_to_vector[j].first;
            int from = distance_from_to_vector[j].second.first;
            int to = distance_from_to_vector[j].second.second;
            if(shortest_paths[to] > shortest_paths[from] + weight)
                shortest_paths[to] = shortest_paths[from] + weight;
        }
    }
}