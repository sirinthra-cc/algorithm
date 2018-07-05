#include<iostream>
#include<vector>

using namespace std;


void dfs(int current_i, int current_j, vector<vector<char>> &board){
    int direction_i[4] = {-1, 1, 0, 0};
    int direction_j[4] = {0, 0, -1, 1};
    int current_color = board[current_i][current_j];
    int next_color;
    if(current_color == 'B') next_color = 'W';
    else next_color = 'B';
    for(int k=0; k<4; k++){
        int next_i = current_i + direction_i[k];
        int next_j = current_j + direction_j[k];
        if(board[next_i][next_j] == '.') {
            board[next_i][next_j] = next_color;
            dfs(next_i, next_j, board);
        }
    }
}

int main(){
    int rows, columns;
    cin >> rows >> columns;
    vector<vector<char>> board(rows+2);
    for(int i=0; i<board.size(); i++){
        board[i].resize(columns+2);
        fill(board[i].begin(), board[i].end(), '0');
    }
    for(int i=1; i<=rows; i++){
        for(int j=1; j<=columns; j++){
            cin >> board[i][j];
        }
    }
    // Search
    for(int i=1; i<=rows; i++){
        for(int j=1; j<=columns; j++){
            if(board[i][j] == '.'){
                board[i][j] = 'B';
                dfs(i, j, board);
            } 
        }
    }
    // Print
    for(int i=1; i<=rows; i++){
        for(int j=1; j<=columns; j++){
            cout << board[i][j]; 
        }
        cout << endl;
    }
}
