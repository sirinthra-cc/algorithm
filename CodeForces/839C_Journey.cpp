#include<iostream>
#include<vector>
#include<stdio.h>

using namespace std;


void dfs(int current_node, vector<vector<int>> &graph, vector<bool> &visited, 
        double prop, int distance, double &accumulated){
    // return accumulated prop * distance
    visited[current_node] = true;
    if(current_node != 1 && graph[current_node].size() == 1) {
        // cout << "node " << current_node << ": " << prop << " " << distance << endl;
        accumulated += distance * prop;
        return;
    }
    int child_size = 0;
    for(auto node: graph[current_node]){
        if(!visited[node]) child_size++;
    }
    prop /= child_size;
    double expected_distance = 0;
    for(auto node: graph[current_node]){
        if(!visited[node]){
            dfs(node, graph, visited, prop, distance + 1, accumulated);
        } 
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> graph(n+1);
    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<bool> visited(n+1);
    double expected_distance = 0;
    dfs(1, graph, visited, 1.0, 0, expected_distance);
    //cout << expected_distance << endl;
    printf("%.16lf\n", expected_distance);
    return 0;
}
