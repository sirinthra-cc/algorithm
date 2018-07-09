#include <bits/stdc++.h>

using namespace std;


int main()
{
    int g_nodes;
    int g_edges;

    cin >> g_nodes >> g_edges;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> g(g_nodes+1);
    for(int i=1; i<=g_nodes; i++) g[i] = i;
    vector<vector<int>> g_weight(g_edges);  // weight from to
    for (int i=0; i<g_edges; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        g_weight[i].resize(3);
        g_weight[i][0] = weight;
        g_weight[i][1] = from;
        g_weight[i][2] = to;
    }
    sort(g_weight.begin(), g_weight.end());
    int total_weight = 0;
    for (int i=0; i<g_edges; i++) {
        int vertex1 = g_weight[i][1];
        int vertex2 = g_weight[i][2];
        int weight = g_weight[i][0];
        int root1 = vertex1;
        int root2 = vertex2;
        while(g[root1] != root1) root1 = g[root1];
        while(g[root2] != root2) root2 = g[root2];
        if(root1 != root2) {
            g[root1] = root2;
            total_weight += weight;
        } else {
            continue;
        }
    }
    cout << total_weight << endl;

    return 0;
}
