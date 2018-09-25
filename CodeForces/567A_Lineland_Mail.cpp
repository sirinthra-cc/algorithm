#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main(){
    int n;
    cin >> n;
    vector<vector<int>> x(n);
    int max_x = -1000000001;
    int min_x = 1000000001;
    for(int i=0; i<n; i++){
        x[i].resize(2);
        cin >> x[i][0];
        x[i][1] = i;
        if(x[i][0] > max_x) max_x = x[i][0];
        if(x[i][0] < min_x) min_x = x[i][0];
    }
    sort(x.begin(), x.end());

    vector<int> sorted_indices(n);
    for(int i=0; i<n; i++){
        sorted_indices[x[i][1]] = i;
    }

    for(int i=0; i<n; i++){
        int min_distance, max_distance;
        int sorted_index = sorted_indices[i];
        if(sorted_index == 0) min_distance = x[1][0] - x[0][0];
        else if(sorted_index == n-1) min_distance = x[n-1][0] - x[n-2][0];
        else min_distance = min(x[sorted_index][0] - x[sorted_index-1][0], x[sorted_index+1][0] - x[sorted_index][0]);
        max_distance = max(x[sorted_index][0] - min_x, max_x - x[sorted_index][0]);
        cout << min_distance << " " << max_distance << endl;
    }

    return 0;
}