#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>

using namespace std;

struct node{
    int i, j, round_no;
};

int travel(vector<vector<char>> &map, queue<node> &to_travel, 
            ::map<pair<int, int>, bool> &travelled){
    // up down left right
    int i_directions[4] = {-1, 1, 0, 0};
    int j_directions[4] = {0, 0, -1, 1};
    int previous_round_no = 0;
    while(!to_travel.empty()){
        int current_i = to_travel.front().i;
        int current_j = to_travel.front().j;
        int round_no = to_travel.front().round_no;
        if(round_no != previous_round_no) {
            cout << "round: " << round_no;
            previous_round_no = round_no;
        }
        to_travel.pop();
        for(int i=0; i<4; i++){
            int next_i = current_i + i_directions[i];
            int next_j = current_j + j_directions[i];
            if(map[next_i][next_j] == 'D') return round_no;
            if(map[next_i][next_j] == '.' && 
                    travelled.find(make_pair(next_i, next_j)) == travelled.end()){
                node temp{next_i, next_j, round_no+1};
                to_travel.push(temp);
                travelled[make_pair(next_i, next_j)] = true;
            } 
        }
    }
    return -1;
}

int main(){
    int r, c, si, sj, ei, ej;
    cin >> r >> c >> si >> sj >> ei >> ej;
    vector<vector<char>> map;
    // resize map
    map.resize(r+2);
    for(int s=0; s<map.size(); s++) {
        map[s].resize(c+2);
        fill (map[s].begin(), map[s].end(), '0');
    }

    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            char a;
            cin >> a;
            map[i][j] = a;
        }
    }
    
    queue<node> to_travel;
    node temp{si, sj, 1};
    to_travel.push(temp);
    ::map<pair<int, int>, bool> travelled;
    int result = travel(map, to_travel, travelled);
    if(result == -1) cout << "KAKTUS" << endl;
    else cout << result << endl;
    return 0;
}