#include<vector>
#include<iostream>
#include<queue>
#include<map>

using namespace std;


bool is_board_equal(vector<vector<int>> target_board, vector<vector<int>> current_board){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(target_board[i][j] != current_board[i][j]) return false;
        }
    }
    return true;
}
int main(){
    vector<vector<int>> initial_board{{1,2,3}, {4,5,6}, {7,8,0}};
    vector<vector<int>> target_board{{7,5,0}, {4,2,3}, {1,8,6}};
    map<vector<vector<int>>, bool> snapshots;
    queue<pair<vector<vector<int>>, pair<pair<int, int>, int>>> q;
    snapshots[initial_board] = true;
    q.push(make_pair(initial_board, make_pair(make_pair(2,2), 0)));
    int direction_i[4] = {0,0,-1,1};
    int direction_j[4] = {-1,1,0,0};
    while(!q.empty()){
        vector<vector<int>> current_board = q.front().first;
        int i = q.front().second.first.first;
        int j = q.front().second.first.second;
        // cout << i << " " << j << endl;
        int move = q.front().second.second;
        q.pop();
        if(is_board_equal(target_board, current_board)){
            cout << move << endl;
            return 0;
        }
        // move blank space
        for(int d=0; d<4; d++){
            int next_i = i + direction_i[d];
            int next_j = j + direction_j[d];
            if(next_i >= 0 && next_i < 3 && next_j >= 0 && next_j < 3){
                vector<vector<int>> board = current_board;
                board[i][j] = board[next_i][next_j];
                board[next_i][next_j] = 0;
                if(snapshots.find(board) == snapshots.end()){
                    snapshots[board] = true;
                    q.push(make_pair(board, make_pair(make_pair(next_i,next_j), move+1)));
                }
            }
        }
    }
    cout << "Impossible" << endl;
    return 0;
}