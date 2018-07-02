#include <bits/stdc++.h>

using namespace std;

// Complete the quickestWayUp function below.
int quickestWayUp(vector<vector<int>> &ladders, vector<vector<int>> &snakes) {
    vector<int> skips(101);
    fill(skips.begin(), skips.end(), -1);
    for(auto ladder: ladders){
        skips[ladder[0]] = ladder[1];
        // cout << "ladder: " << ladder[0] << " " << ladder[1] << endl;
    }
    for(auto snake: snakes){
        skips[snake[0]] = snake[1];
        // cout << "snake: " << snake[0] << " " << snake[1] << endl;
    }
    vector<bool> visited_nodes(101);
    queue<pair<int, int>> to_visit_nodes; // pair of to_visit_node and round
    visited_nodes[1] = true;
    to_visit_nodes.push(make_pair(1, 0));
    while(!to_visit_nodes.empty()){
        int current_position = to_visit_nodes.front().first;
        cout << current_position << endl;
        int round = to_visit_nodes.front().second;
        to_visit_nodes.pop();
        if(current_position == 100) return round;
        if(current_position > 100) continue;
        for(int i=1; i<=6; i++){
            int next_position = current_position + i;
            if(next_position > 100) continue;
            int final_position;
            if(skips[next_position] != -1) 
                final_position = skips[next_position];
            else
                final_position = next_position;
            
            if(!visited_nodes[final_position]){
                visited_nodes[final_position] = true;
                to_visit_nodes.push(make_pair(final_position, round+1));
            }
        }
    }
    return -1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> ladders(n);
        for (int i = 0; i < n; i++) {
            ladders[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> ladders[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int m;
        cin >> m;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> snakes(m);
        for (int i = 0; i < m; i++) {
            snakes[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> snakes[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int result = quickestWayUp(ladders, snakes);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
