#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<pair<int, pair<int,int>>> edge_list; // <weight, <vertex1, vertex2>>

vector<pair<int, pair<int,int>>> kruskal_MST(int num_vertex) {
    vector<int> set;
    for(int i=0;i<num_vertex;i++) {
        set.push_back(i);
    }
    vector<pair<int, pair<int,int>>> edge_in_MST;
    sort(edge_list.begin(), edge_list.end());
    for(int i=0;i<edge_list.size();i++){
        int vertex1 = edge_list[i].second.first;
        int vertex2 = edge_list[i].second.second;
        int weight = edge_list[i].first;
        int root1 = vertex1;
        int root2 = vertex2;
        while(set[root1] != root1) root1 = set[root1];
        while(set[root2] != root2) root2 = set[root2];
        if(root1 != root2) {
            set[root1] = root2;
            edge_in_MST.push_back(edge_list[i]);
        } else {
            continue;
        }
    }
    return edge_in_MST;
}