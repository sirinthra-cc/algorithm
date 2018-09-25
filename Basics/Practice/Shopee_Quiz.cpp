#include<iostream>
#include<vector>
#include<queue>

using namespace std;


bool is_out_of_bound(int i, int j){
    return i<0 || i>9 || j<0 || j>9;
}

int main(){
    // obstacle = 2
    // petrol = 1
    // road = 0
    int map[10][10] = {
        {0,0,2,1,0,0,0,0,0,0},
        {2,0,0,0,0,0,0,0,1,0},
        {0,2,0,2,0,0,1,0,0,0},
        {1,0,0,0,0,2,0,0,1,2},
        {1,0,0,0,0,1,2,0,2,0},
        {1,0,1,0,2,0,0,0,0,1},
        {2,2,0,0,2,0,0,0,0,2},
        {0,0,0,0,0,0,0,0,0,0},
        {2,0,0,1,0,2,0,1,0,2},
        {2,0,0,0,1,0,2,0,0,0}
    };
    vector<vector<bool>> is_visited(10);
    for(int i=0; i<10; i++){
        is_visited.resize(10);
    }
    queue<vector<int>> q;  // i,j,step,energy
    vector<int> next_position{0,0,0,7};
    q.push(next_position);
    int i_directions[4] = {0,0,-1,1};
    int j_directions[4] = {-1,1,0,0}; 
    int min_step = 100;
    int path_count = 0;
    while(!q.empty()){
        int i = q.front()[0];
        int j = q.front()[1];
        int step = q.front()[2];
        int energy = q.front()[3];
        q.pop();
        if(step > min_step) continue;
        if(energy == 0) continue;
        for(int d=0; d<4; d++){
            int next_i = i + i_directions[d];
            int next_j = j + j_directions[d];
            if(!is_out_of_bound(next_i, next_j)){
                if(next_i == 9 && next_j == 9){
                    if(step + 1 < min_step) {
                        min_step = step + 1;
                        path_count = 1;
                    } else if (step + 1 == min_step){
                        path_count++;
                    }
                } else if (!is_visited[next_i][next_j]) {
                    next_position[0] = next_i;
                    next_position[1] = next_j;
                    next_position[2] = step + 1;
                    next_position[3] = energy - 1;
                    if(map[next_i][next_j] == 1) energy = 7;
                }
            }
        }
    }
    cout << min_step << path_count << endl;
    return 0;
}