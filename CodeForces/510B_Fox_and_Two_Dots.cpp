#include<iostream>
#include<vector>
#include<queue>

using namespace std;


bool check_circle(int current_i, int current_j, vector<vector<char>> &map, 
        vector<vector<bool>> &visited){
    int direction_i[4] = {-1, 1, 0, 0};
    int direction_j[4] = {0, 0, -1, 1};
    int visited_count = 0;
    for(int k=0; k<4; k++){
        int next_i = current_i + direction_i[k];
        int next_j = current_j + direction_j[k];
        if(visited[next_i][next_j] && map[current_i][current_j] == map[next_i][next_j]){
            visited_count++;       
        }
    }
    if(visited_count>=2) return true;
    return false;
}
bool dfs(int current_i, int current_j, vector<vector<char>> &map, 
        vector<vector<bool>> &visited){
    if(check_circle(current_i, current_j, map, visited)) return true;
    visited[current_i][current_j] = true;
    int direction_i[4] = {-1, 1, 0, 0};
    int direction_j[4] = {0, 0, -1, 1};
    bool found = false;
    for(int k=0; k<4; k++){
        int next_i = current_i + direction_i[k];
        int next_j = current_j + direction_j[k];
        if(!visited[next_i][next_j] && map[current_i][current_j] == map[next_i][next_j]){
            found = dfs(next_i, next_j, map, visited);
            if(found) return true;          
        }
    }
    return false;
}
int main(){
    int rows, columns;
    cin >> rows >> columns;
    vector<vector<char>> map(rows+2);
    for(int i=0; i<rows+2; i++) {
        map[i].resize(columns+2);
        fill(map[i].begin(), map[i].end(), '0');
    }
    for(int i=1; i<=rows; i++){
        for(int j=1; j<=columns; j++){
            cin >> map[i][j];
        }
    }

    vector<vector<bool>> visited(rows+2);
    for(int i=0; i<rows+2; i++) visited[i].resize(columns+2);
    bool found = false;
    for(int i=1; i<=rows; i++){
        for(int j=1; j<=columns; j++){
            if(!visited[i][j]){
                found = dfs(i, j, map, visited);
                if(found) {
                    cout << "Yes" << endl;
                    return 0;
                }  
            }       
        }
    }
    cout << "No" << endl;
    return 0;
}
