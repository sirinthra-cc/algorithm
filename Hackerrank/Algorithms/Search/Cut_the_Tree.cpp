#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int dfs(int current_node, vector<vector<int>> &graph, vector<int> &data,
         vector<bool> &visited, int &total, int &min_diff){
    // return sum of subgraph
    visited[current_node] = true;
    int current_value = data[current_node];
    int sum = current_value;
    int diff;
    vector<int> subtree_sum;
    for(auto node: graph[current_node]) {
        if(!visited[node]){
            int local_sum = dfs(node, graph, data, visited, total, min_diff);
            diff = abs(total - local_sum - local_sum);
            if(diff < min_diff) min_diff = diff;
            sum += local_sum;
        }
    }
    return sum;
}
// Complete the solve function below.
int solve(vector<int> data, vector<vector<int>> edges) {
    vector<int> new_data(data.size()+1);
    for(int i=1; i<=data.size(); i++) new_data[i] = data[i-1];
    vector<vector<int>> graph(data.size()+1);
    for(auto edge: edges){
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    int total = 0;
    for(auto d: new_data) total += d;
    int min_diff = INT_MAX;
    vector<bool> visited(data.size()+1);
    dfs(1, graph, new_data, visited, total, min_diff);
    return min_diff;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string data_temp_temp;
    getline(cin, data_temp_temp);

    vector<string> data_temp = split_string(data_temp_temp);

    vector<int> data(n);

    for (int i = 0; i < n; i++) {
        int data_item = stoi(data_temp[i]);

        data[i] = data_item;
    }

    vector<vector<int>> edges(n-1);
    for (int i = 0; i < n-1; i++) {
        edges[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> edges[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = solve(data, edges);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
