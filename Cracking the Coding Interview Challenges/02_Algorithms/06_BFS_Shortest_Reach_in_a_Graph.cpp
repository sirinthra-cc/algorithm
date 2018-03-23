#include <cmath>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Graph {
    vector<vector<int>> g;
    
    public:
        Graph(int n) {
            g.resize(n);
        }
    
        void add_edge(int u, int v) {
            if(find(g[u].begin(), g[u].end(), v) == g[u].end()) {
                g[u].push_back(v);
                g[v].push_back(u);
            }
        }
    
        vector<int> shortest_reach(int start) {
            unordered_map<int, int> travelled_nodes;
            vector<int> results(g.size());
            for(int i=0; i<results.size(); i++){
                results[i] = -1;
            }
            queue<pair<int,int>> q;
            int round = 6;
            for(auto x: g[start]){
                q.push(make_pair(x, round));
            }
            
            while(!q.empty()){
                pair<int, int> pair_x = q.front();
                q.pop();
                int x = pair_x.first;
                int r = pair_x.second;
                if(travelled_nodes.find(x) == travelled_nodes.end()) {
                    results[x] = r; 
                    travelled_nodes[x] = 1;
                    for(auto y: g[x]){
                        if(travelled_nodes.find(y) == travelled_nodes.end()) q.push(make_pair(y, r+6));
                    }
                }
            }
            
            return results;
        }
};

int main() {
    int queries;
    cin >> queries;
        
    for (int t = 0; t < queries; t++) {
      
      int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6: 
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
      int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}
