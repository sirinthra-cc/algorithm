#include <queue>
#include <vector>
using namespace std;
vector<int> dijkstra_shortest_path(vector<vector<pair<int,int>>> &graph) {
    // O(E + VlogE)
    priority_queue<vector<int>> pq;
    vector<int> shortest_paths;
    shortest_paths.resize(graph.size());
    fill(shortest_paths.begin(), shortest_paths.end(), 100000000);
    shortest_paths[0] = 0;
    int current_node = 0;
    for(int i = 0; i < graph.size() - 1; i++) {
        for(int j = 0; j < graph[current_node].size(); j++) {
            vector<int> row;
            int path_length = shortest_paths[current_node] + graph[current_node][j].second;
            row.push_back(-path_length);
            row.push_back(current_node);
            row.push_back(graph[current_node][j].first);
            pq.push(row);
        }
        while(pq.size() && shortest_paths[pq.top()[2]] != 100000000) {
            pq.pop();
        }
        vector<int> row = pq.top();
        current_node = row[2];
        shortest_paths[current_node] = -row[0];
        pq.pop();
    }
    return shortest_paths;
}