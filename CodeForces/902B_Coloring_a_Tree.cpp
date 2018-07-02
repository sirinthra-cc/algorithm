#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


void color(int current_node, vector<vector<int>> &graph, vector<int> &colors, 
        vector<int> &current_colors, int &step){
    if(colors[current_node] != current_colors[current_node]) step++;
    for(auto node: graph[current_node]){
        current_colors[node] = colors[current_node];
        color(node, graph, colors, current_colors, step);
    }
}
    
int main(){
    int n_vertices;
    cin >> n_vertices;
    vector<vector<int>> graph(n_vertices+1);
    for(int i=2; i<=n_vertices; i++){
        int parent;
        cin >> parent;
        graph[parent].push_back(i);
    }
    vector<int> colors(n_vertices+1);
    for(int i=1; i<=n_vertices; i++){
        cin >> colors[i];
    }
    vector<int> current_colors(n_vertices+1);
    fill(current_colors.begin(), current_colors.end(), colors[1]);
    int step = 1;
    color(1, graph, colors, current_colors, step);
    cout << step << endl;

    return 0;
}