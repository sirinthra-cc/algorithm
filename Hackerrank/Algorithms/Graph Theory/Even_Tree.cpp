#include <bits/stdc++.h>

using namespace std;

int remove_edge(int current_node, vector<vector<int>> &tree, int &cut){
    int count = 1;
    for(auto node: tree[current_node]){
        // cout << node << " ";
        count += remove_edge(node, tree, cut);
    }
    if(count%2==0 && count!=0) {
        cut++;
        count = 0;
        // cout << "count: " << count << endl;
    }
    return count;
}

int main()
{
    int tree_nodes;
    int tree_edges;

    cin >> tree_nodes >> tree_edges;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    vector<vector<int>> tree(tree_nodes+1);

    for (int i = 0; i < tree_edges; i++) {
        int child, mother;
        cin >> child >> mother;
        tree[mother].push_back(child);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int cut = 0;
    remove_edge(1, tree, cut);
    cout << cut-1;
    return 0;
}
