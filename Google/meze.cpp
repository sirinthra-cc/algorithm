vector<vector<int>> map;


vector<vector<vector<pair<int,int>>>> get_precomputed_map(vector<vector<int>> &map){
    vector<vector<vector<pair<int,int>>>> precomputed_map(map.size());
    for(int i=0; i<map.size(); i++) precomputed_map[i].resize(map.size());
    // left to right -> find right wall
    for(int i=0; i<map.size(); i++){
        int last_wall = 0;
        for(int j=0; j<map.size(); j++){
            if(map[i][j] == '#' || j == map.size()-1) {
                for(int jj=last_wall+1; jj<j; jj++){
                    precomputed_map[i][jj].push_back(make_pair(i,j-1));
                }
                last_wall = j;
            }
        }
    }
    ...
    return precomputed_map;
}

int get_num_turns(int start_i, int start_j, vector<vector<vector<pair<int,int>>>> &precomputed_map){
    int n = precomputed_map.size()
    queue<pair<pair<int,int>,int>> q;  // pair of i,j and num_turn
    vector<vector<bool>> visited_positions(n);
    for(int d=0; d<n; d++) visited_positions[d].resize(n);
    q.push(make_pair(make_pair(start_i, start_j), 0));
    while(!q.empty()){
        int i = q.front().first.first;
        int j = q.front().first.second;
        int num_turn = q.front().second;
        q.pop();
        if(i==0 || i==n-1 || j==0 || j==n-1) return num_turn;
        for(auto next_position: precomputed_map[i][j]){
            int next_i = next_position.first;
            int next_j = next_position.second;
            if(!visited_positions[next_i][next_j]) q.push(make_pair(make_pair(next_i, next_j), num_turn+1));
        }
    }
    return -1;
}
