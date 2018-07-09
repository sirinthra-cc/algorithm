#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;


int main(){
    int nodes, edges;
    cin >> nodes >> edges;
    vector<pair<int,pair<int,int>>> distance_from_to_vector;
    for(int i=0; i<edges; i++){
        int from, to, distance;
        //cin >> from >> to >> distance;
        scanf("%d %d %d", &from, &to, &distance);
        vector<int> distance_from_to(3);
        distance_from_to[0] = distance;
        distance_from_to[1] = from;
        distance_from_to[2] = to;
        //distance_from_to_vector.push_back(distance_from_to);
        distance_from_to_vector.push_back(make_pair(distance, make_pair(from, to)));
    }
    sort(distance_from_to_vector.begin(), distance_from_to_vector.end());
    vector<int> set(nodes+1);
    vector<int> height(nodes+1);
    for(int i=1; i<=nodes; i++) set[i] = i;
    fill(height.begin(), height.end(), 1);
    int num_component = nodes;
    for(auto node: distance_from_to_vector){
        int distance = node.first;
        int from = node.second.first;
        int to = node.second.second;
        int root1 = from;
        int root2 = to;
        while(set[root1] != root1) root1 = set[root1];
        while(set[root2] != root2) root2 = set[root2];
        if(root1 != root2){
            //cout << from << " " << to << endl;
            printf("%d %d\n", from ,to);
            if(height[root1] == height[root2]) {
                height[root2]++;
                set[root1] = root2;
            } else if (height[root1] > height[root2]){
                set[root2] = root1;
            } else { // height[root2] > height[root1]
                set[root1] = root2;
            }
            num_component--;
        }
        if(num_component == 1)
            break;
    }

    return 0;
}