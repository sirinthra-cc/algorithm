#include<iostream>
#include<vector>

using namespace std;


int main(){
    int n_row, n_col;
    cin >> n_row >> n_col;
    vector<vector<char>> map(n_row);
    vector<int> highest_obstacle(n_col);
    fill(highest_obstacle.begin(), highest_obstacle.end(), n_row);
    for(int i=0; i<n_row; i++){
        map[i].resize(n_col);
        for(int j=0; j<n_col; j++){
            cin >> map[i][j];
            if(map[i][j] == 'O' && highest_obstacle[j] == n_row) highest_obstacle[j] = i;
        }
    }
    int n_brick;
    for(int j=0; j<n_col; j++){
        cin >> n_brick;
        int i = highest_obstacle[j] - 1;
        while(n_brick > 0 && i >= 0) {
            map[i][j] = '#';
            i--;
            n_brick--;
        }
    }
    for(int i=0; i<n_row; i++){
        for(int j=0; j<n_col; j++){
            cout << map[i][j];
        }
        cout << endl;
    }
    return 0;
}