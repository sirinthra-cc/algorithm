#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>

using namespace std;

struct node{
    int i, j, round_no;
};

void flood(vector<vector<char>> &map){
    int r = map.size() - 2;
    int c = map[0].size() - 2;
    int i_directions[4] = {-1, 1, 0, 0};
    int j_directions[4] = {0, 0, -1, 1};
    vector<pair<int, int>> to_flood;
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            if(map[i][j] == 'S' || map[i][j] == '.') {
                for(int k=0; k<4; k++){
                    int neighbour_i = i + i_directions[k];
                    int neighbour_j = j + j_directions[k];
                    if(map[neighbour_i][neighbour_j] == '*') 
                        to_flood.push_back(make_pair(i, j));
                }
            }
        }
    }
    for(auto a: to_flood) map[a.first][a.second] = '*';
    // cout << "flood jaaa" << endl;
    // for(int i=0; i<map.size(); i++){
    //     for(int j=0; j<map[0].size(); j++){
    //         cout << map[i][j];
    //     }
    //     cout << endl;
    // }
}

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
            flood(map);
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
    int r, c;
    cin >> r >> c;
    vector<vector<char>> map;
    // resize map
    map.resize(r+2);
    for(int s=0; s<map.size(); s++) {
        map[s].resize(c+2);
        fill (map[s].begin(), map[s].end(), '0');
    }

    int start_i, start_j;
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            char a;
            cin >> a;
            map[i][j] = a;
            if(a=='S'){
                start_i = i;
                start_j = j;
            }
        }
    }
    
    queue<node> to_travel;
    node temp{start_i, start_j, 1};
    to_travel.push(temp);
    ::map<pair<int, int>, bool> travelled;
    // flood(map);
    int result = travel(map, to_travel, travelled);
    if(result == -1) cout << "KAKTUS" << endl;
    else cout << result << endl;
    return 0;
}