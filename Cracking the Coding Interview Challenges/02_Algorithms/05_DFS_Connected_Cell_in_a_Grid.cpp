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

int dfs(vector<vector<int>> &grid, int i, int j, unordered_map<pair<int, int>, int> &region_elements, int sum){
    for(int grid_i=i-1; grid_i<=i+1; grid_i++){
       for(int grid_j=j-1; grid_j<=j+1; grid_j++){
          if(grid_i != i && grid_j != j && grid[grid_i][grid_j] == 1){
              pair<int, int> new_pair = make_pair(grid_i, grid_j);
              if(region_elements.find(new_pair) == region_elements.end()){
                  region_elements[new_pair] = 1;
                  sum += dfs(grid, grid_i, grid_j, region_elements, sum);
              } 
          }
       }
    }
    return sum;
}

int get_biggest_region(vector<vector<int>> &grid) {
    int biggest_region = 0;
    for(int grid_i=1; grid_i<grid.size(); grid_i++){
       for(int grid_j=1; grid_j<grid[0].size(); grid_j++){
          if(grid[grid_i][grid_j] == 1){
              unordered_map<pair<int, int>, int> region_elements;
              int region = dfs(grid, grid_i, grid_j, region_elements, 1);
              if(region > biggest_region) biggest_region = region;
          }
       }
    }
    return biggest_region;
}

int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector< vector<int>> grid(n+2,vector<int>(m+2));
    for(int grid_i=1; grid_i<=n; grid_i++){
       for(int grid_j=1; grid_j<=m; grid_j++){
          cin >> grid[grid_i][grid_j];
       }
    }
    cout << get_biggest_region(grid) << endl;
    return 0;
}
