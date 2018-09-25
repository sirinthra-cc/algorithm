#include<iostream>
#include<vector>

using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> coolness(n+1);
    fill(coolness.begin(), coolness.end(), 0);
    for(int i=0; i<n; i++){
        int c;
        cin >> c;
        coolness[c]++;
    }
    vector<int> same_factor;
    vector<int> missing;
    for(int i=1; i<=n; i++){
        if(coolness[i] == 0) missing.push_back(i);
        else if(coolness[i] > 1) {
            // cout << "same factor" << endl;
            for(int j=2; j<=coolness[i]; j++) {
                same_factor.push_back(i);
                // cout << i << endl;
            }   
        }
    }
    int cost = 0;
    int nn = n+1;
    int j = 0;
    for(int i=0; i<same_factor.size(); i++){
        while(j < missing.size() && missing[j] < same_factor[i]) j++;
        if(j == missing.size()){
            cost += nn - same_factor[i];
            // cout << nn << " " << same_factor[i] << " " << cost << endl;
            nn++;
        } else {
            cost += missing[j] - same_factor[i];
            j++;
            // cout << missing[j] << " " << same_factor[i] << " " << cost << endl;
        }
        
    }
    cout << cost << endl;
    return 0;
}