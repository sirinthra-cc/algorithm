#include<iostream>
#include<vector>
#include<stdio.h>

using namespace std;


int go_to_resturant(int current_node, vector<vector<int>> &tree, int cat_count, 
                vector<int> &cats, int max_cat, vector<bool> &visited_nodes){
    visited_nodes[current_node] = true;
    if(cats[current_node] == 1) cat_count++;
    else cat_count = 0;
    if(cat_count > max_cat) {
        // cout << "cat_count > max_cat " << cat_count << endl;
        return 0;
    }
    if(tree[current_node].size() == 1 && current_node != 1) return 1;
    int count = 0;
    for(auto node: tree[current_node]){
        if(!visited_nodes[node]){
            // cout << node << " ";
            count += go_to_resturant(node, tree, cat_count, cats, max_cat, visited_nodes);
            // cout << " count jaa " << count << endl;
        }
    }
    return count;
}


int main(){
    int n_nodes, max_cat;
    cin >> n_nodes >> max_cat;
    vector<int> cats(n_nodes+1);
    vector<vector<int>> tree(n_nodes+1);
    for(int i=1; i<=n_nodes; i++){
        //cin >> cats[i]; 
        scanf("%d", &cats[i]);
    }
    for(int i=0; i<n_nodes-1; i++){
        int n1, n2;
        // cin >> n1 >> n2;
        scanf("%d %d", &n1, &n2);
        tree[n1].push_back(n2);
        tree[n2].push_back(n1);
    }
    vector<bool> visited_nodes(n_nodes+1);
    int count = go_to_resturant(1, tree, 0, cats, max_cat, visited_nodes);
    cout << count << endl;
    return 0;
}