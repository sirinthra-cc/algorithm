#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;


int main(){
    int nodes, edges;
    cin >> nodes >> edges;
    vector<vector<pair<int, int>>> graph(nodes+1);
    for(int i=0; i<edges; i++){
        int from, to, distance;
        cin >> from >> to >> distance;
        graph[from].push_back(make_pair(to, distance));
        graph[to].push_back(make_pair(from, distance));
    }
    int current_node = 1;
    vector<int> shortest_distances(nodes+1);
    fill(shortest_distances.begin(), shortest_distances.end(), 99999);
    shortest_distances[current_node] = 0;
    priority_queue<pair<int, pair<int, int>>> pq;
    vector<int> mothers(nodes+1);
    fill(mothers.begin(), mothers.end(), -1);
    mothers[1] = 1;
    for(int i=0; i<nodes-1; i++){
        for(auto to_distance: graph[current_node]){
            int distance = shortest_distances[current_node] + to_distance.second;
            pq.push(make_pair(-distance, make_pair(to_distance.first, current_node)));
        }
        while(!pq.empty() && shortest_distances[pq.top().second.first] != 99999){
            pq.pop();
        }
        if(!pq.empty()){
            // cout << current_node << " " << pq.top().second.first << endl;
            mothers[pq.top().second.first] = pq.top().second.second;
            current_node = pq.top().second.first;
            shortest_distances[current_node] = -pq.top().first;
            pq.pop();
            if(current_node == nodes) break;
        }
    }
    int i=nodes;
    vector<int> reversed_result;
    while(i!=1){
        reversed_result.push_back(i);
        if(mothers[i] != -1) i = mothers[i];
        else{
            cout << -1 << endl;
            return 0;
        }
    }
    reversed_result.push_back(i);
    for(int j=reversed_result.size()-1; j>=0; j--)
        cout << reversed_result[j] << " ";
    return 0;
}