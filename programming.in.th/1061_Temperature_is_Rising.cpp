#include<iostream>
#include<vector>

using namespace std;


int dfs(int i, int j, vector<vector<int>> &map, vector<vector<bool>> &visited){
    visited[i][j] = true;
    // left right up down
    int direction_i[4] = {0, 0, -1, 1}; 
    int direction_j[4] = {-1, 1, 0, 0}; 
    int max = map[i][j];
    for(int d=0; d<4; d++){
        int next_i = i + direction_i[d];
        int next_j = j + direction_j[d];
        if(!visited[next_i][next_j] && map[next_i][next_j] != 100 && 
                map[next_i][next_j] > map[i][j]) {
            int local_max = dfs(next_i, next_j, map, visited);
            if(local_max > max) max = local_max;
        }
    }
    return max;
}
int main(){
    int n, i, j;
    cin >> n;
    cin >> j >> i;
    vector<vector<int>> map(n+2);
    for(int k=0; k<n+2; k++) {
        map[k].resize(n+2);
        fill(map[k].begin(), map[k].end(), 100);
    }
    for(int k=1; k<=n; k++){
        for(int l=1; l<=n; l++){
            cin >> map[k][l];
        }
    }
    vector<vector<bool>> visited(n+2);
    for(int k=0; k<n+2; k++) visited[k].resize(n+2);
    cout << dfs(i, j, map, visited) << endl;
    return 0;
}