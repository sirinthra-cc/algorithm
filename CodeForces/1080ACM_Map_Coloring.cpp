#include<iostream>
#include<vector>

using namespace std;


bool is_valid(int node, int color, vector<vector<int>> &graph, vector<int> &colors){
    for(auto c: graph[node]){
        if(colors[c] == color) return false;
    }
    return true;
}


bool dfs(int current_node, vector<vector<int>> &graph, vector<int> &colors, vector<bool> &visited){
    visited[current_node] = true;
    int neighbour_color;
    if(colors[current_node] == 0) neighbour_color = 1;
    else neighbour_color = 0;
    for(auto node: graph[current_node]){
        if(!visited[node]){
            // cout << "!visited[node] " << node << endl;
            if(is_valid(node, neighbour_color, graph, colors)){
                colors[node] = neighbour_color;
                if(!dfs(node, graph, colors, visited)) return false;
            } else {
                return false;
            }
        }
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> graph(n+1);
    for(int i=1; i<=n; i++){
        int c;
        cin >> c;
        while(c != 0){
            graph[i].push_back(c);
            graph[c].push_back(i);
            cin >> c;
        }
    }
    vector<int> colors(n+1);
    fill(colors.begin(), colors.end(), -1);
    colors[1] = 0;
    vector<bool> visited(n+1);
    if(dfs(1, graph, colors, visited)){
        for(int i=1; i<=n; i++){
            cout << colors[i];
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}