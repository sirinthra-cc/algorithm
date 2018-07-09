#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>

using namespace std;


int main(){
    int n, w;
    //cin >> n >> w;
    scanf("%d %d",&n ,&w);
    vector<vector<int>> weeks(w);
    for(int i=0; i<w; i++){
        int v1, v2, distance;
        //cin >> v1 >> v2 >> distance;
        scanf("%d %d %d", &v1, &v2, &distance);
        weeks[i].resize(3);
        weeks[i][0] = distance;
        weeks[i][1] = v1;
        weeks[i][2] = v2;
    }
    vector<vector<int>> passed_path;
    vector<int> set(n+1);
    for(int i=0; i<w; i++){
        int total_distance = 0;
        int edge_count = 0;
        passed_path.push_back(weeks[i]);
        sort(passed_path.begin(), passed_path.end());
        // cout << "sort jaa" << endl;
        for(int j=1; j<=n; j++) set[j] = j;
        for(int j=0; j<passed_path.size(); j++){
            int v1 = passed_path[j][1];
            int v2 = passed_path[j][2];
            int distance = passed_path[j][0];
            int root1 = v1;
            int root2 = v2;
            while(set[root1] != root1) root1 = set[root1];
            while(set[root2] != root2) root2 = set[root2];
            if(root1 != root2){
                set[root1] = root2;
                total_distance += distance;
                edge_count++;
                // cout << "edge_count " << edge_count << endl;
            }
        }
        if(edge_count == n-1) printf("%d\n", total_distance);
        else printf("-1\n");
    }
    return 0;
}