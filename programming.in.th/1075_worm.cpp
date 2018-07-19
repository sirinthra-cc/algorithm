#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main(){
    int n;
    cin >> n;
    vector<vector<int>> shoots(n);
    vector<pair<double, int>> ratios(n);
    for(int i=0; i<n; i++){
        shoots[i].resize(2);
        cin >> shoots[i][0] >> shoots[i][1];
        ratios[i] = make_pair((double)shoots[i][0]/shoots[i][1], i);
    }
    sort(ratios.begin(), ratios.end());
    long long count = shoots[ratios[n-1].second][0];
    int cost = shoots[ratios[n-1].second][1];
    double opt_ratio = (double)count/cost;
    long long opt_count = count;
    int opt_cost = cost;
    for(int i=n-2; i>=0; i--){
        if(cost < shoots[ratios[i].second][1]) cost = shoots[ratios[i].second][1];
        count += shoots[ratios[i].second][0];
        double ratio = (double)count/cost;
        // cout << "ratio: " << ratio << endl;
        if(ratio > opt_ratio) {
            opt_ratio = ratio;
            opt_count = count;
            opt_cost = cost;
        } else {
            break;
        }
    }
    cout << opt_count << " " << opt_cost << endl;
    return 0;
}