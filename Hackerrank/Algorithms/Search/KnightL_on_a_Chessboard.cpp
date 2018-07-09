#include <bits/stdc++.h>

using namespace std;


int search(int a, int b, int n){
    vector<vector<bool>> visited(n);
    for(int i=0; i<n; i++) visited[i].resize(n);
    int direction_i[8] = {a, a, -a, -a, b, b, -b, -b};
    int direction_j[8] = {b, -b, b, -b, a, -a, a, -a};
    // i, j, move
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(0,0), 0));
    visited[0][0] = true;
    while(!q.empty()){
        int i = q.front().first.first;
        int j = q.front().first.second;
        int move = q.front().second;
        cout << i << " " << j << " move " << move << endl;
        q.pop();
        if((i==n-1) && (j==n-1)) return move;
        for(int c=0; c<8; c++){
            int next_i = i + direction_i[c];
            int next_j = j + direction_j[c];
            if(next_i < 0 || next_i >=n || next_j < 0 || next_j >=n) continue;
            if(!visited[next_i][next_j]) {
                visited[next_i][next_j] = true;
                q.push(make_pair(make_pair(next_i,next_j), move+1));
            }
        }
    }
    return -1;
}

// Complete the knightlOnAChessboard function below.
vector<vector<int>> knightlOnAChessboard(int n) {
    vector<vector<int>> result(n-1);
    for(int i=0; i<n-1; i++) {
        result[i].resize(n-1);
        fill(result[i].begin(), result[i].end(), -1);
    }
    for(int a=1; a<n; a++){
        for(int b=1; b<n; b++){
            result[a-1][b-1] = search(a, b, n);
        }
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> result = knightlOnAChessboard(n);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            fout << result[i][j];

            if (j != result[i].size() - 1) {
                fout << " ";
            }
        }

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
