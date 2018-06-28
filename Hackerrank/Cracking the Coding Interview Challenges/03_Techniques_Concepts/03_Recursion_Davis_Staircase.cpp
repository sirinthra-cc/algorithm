#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main(){
    int s;
    cin >> s;
    int stair_height[s];
    int max_staircase = 0;
    for(int a0 = 0; a0 < s; a0++){
        cin >> stair_height[a0];
        if(stair_height[a0] > max_staircase) max_staircase = stair_height[a0];
    }
    int ways[max_staircase+1][3] = {0};
    // Compute ways
    ways[0][2] = 1;
    for(int height=1; height<=max_staircase; height++){
        for(int step=0; step<3; step++){
            int remaining = height-step-1;
            if(step == 0) ways[height][step] = ways[height-1][2];
            else if(remaining == 0) ways[height][step] = 1 + ways[height][step-1];
            else if(remaining < 0) ways[height][step] = ways[height][step-1];
            else ways[height][step] = ways[remaining][2] + ways[height][step-1];
        }
    }
    for(int i=0; i<s; i++){
        cout << ways[stair_height[i]][2] << endl;
    }
    return 0;
}
