void fill(int i, int j, int &old_color, int &new_color, vector<vector<int>> &map){
    int direction_i[4] = {0,0,-1,1};
    int direction_j[4] = {-1,1,0,0};
    for(int d=0; d<4; d++){
        int next_i = i + direction_i[d];
        int next_j = j + direction_i[d];
        if(next_i >= 0 && next_i < map.size() && next_j >= 0 && next_j < map[0].size() && 
                map[next_i][next_j] == old_color){
            map[next_i][next_j] = new_color;
            fill(next_i, next_j, old_color, new_color, map);
        }
    }
}