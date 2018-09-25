#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;


int main(){
    int n;
    cin >> n;
    unordered_map<int,int> heights;
    int max_height = 0;
    int tower_count = 0;
    for(int i=0; i<n; i++){
        int h;
        cin >> h;
        if(heights.find(h) == heights.end()) {
            heights[h] = 1;
            tower_count++;
        } else {
            heights[h]++;
        }
        if(heights[h] > max_height) max_height = heights[h];
    }
    cout << max_height << " " << tower_count << endl;
    return 0;
}