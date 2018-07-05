#include <bits/stdc++.h>

using namespace std;


void dfs(int i, int j, vector<vector<int>> &matrix, vector<vector<bool>> &visited, int &count){
    // 0 1 2
    // 3   4
    // 5 6 7
    int direction_i[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int direction_j[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    visited[i][j] = true;
    count++;
    cout << i << "," << j << ": " << count << endl;
    for(int k=0; k<8; k++){
        int next_i = i + direction_i[k];
        int next_j = j + direction_j[k];
        if(next_i<0 || next_i>=matrix.size() || next_j<0 || next_j>=matrix[0].size())
            continue;
        if(!visited[next_i][next_j] && matrix[next_i][next_j] == 1) 
            dfs(next_i, next_j, matrix, visited, count);
    }
}

// Complete the connectedCell function below.
int connectedCell(vector<vector<int>> matrix) {
    int max_count = 0;
    int count;
    vector<vector<bool>> visited(matrix.size());
    for(int i=0; i<matrix.size(); i++) visited[i].resize(matrix[i].size());
    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[i].size(); j++){
            count = 0;
            if(!visited[i][j] && matrix[i][j] == 1){
                dfs(i, j, matrix, visited, count);
                if(count > max_count) max_count = count;
            }
        }
    }
    return max_count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> matrix(n);
    for (int i = 0; i < n; i++) {
        matrix[i].resize(m);

        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = connectedCell(matrix);

    fout << result << "\n";

    fout.close();

    return 0;
}
