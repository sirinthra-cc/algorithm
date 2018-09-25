#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


bool is_overlap(int bl_x, int bl_y, int ur_x, int ur_y, 
                int bound_bl_x, int bound_bl_y, int bound_ur_x, int bound_ur_y){
    if(ur_x < bound_bl_x || bound_ur_x < bl_x ||
       ur_y < bound_bl_y || bound_ur_y < bl_y) 
       return false;
    else return true;
}

int main(){
    int n;
    cin >> n;
    int bound_bl_x = -1000000001;
    int bound_bl_y = -1000000001;
    int bound_ur_x = 1000000001;
    int bound_ur_y = 1000000001;
    vector<int> bl_x(n);
    vector<int> bl_y(n);
    vector<int> ur_x(n);
    vector<int> ur_y(n);
    vector<pair<long,int>> area_index;  // area and index
    for(int i=0; i<n; i++){
        cin >> bl_x[i] >> bl_y[i] >> ur_x[i] >> ur_y[i];
        long area = (long)(ur_x[i] - bl_x[i]) * (ur_y[i] - bl_y[i]);
        area_index.push_back(make_pair(-area, i));
    }
    sort(area_index.begin(), area_index.end());
    // for(auto index: area_index) cout << index.first << " " << index.second << endl;

    // delete first rectangle
    int not_overlap_count = 0;
    for(auto index: area_index){
        int i = index.second;
        if(!is_overlap(bl_x[i], bl_y[i], ur_x[i], ur_y[i], bound_bl_x, bound_bl_y, bound_ur_x, bound_ur_y)){
            not_overlap_count++;
            break;
        }
        if(bl_x[i] > bound_bl_x) bound_bl_x = bl_x[i];
        if(ur_x[i] < bound_ur_x) bound_ur_x = ur_x[i];
        if(bl_y[i] > bound_bl_y) bound_bl_y = bl_y[i];
        if(ur_y[i] < bound_ur_y) bound_ur_y = ur_y[i];
    }
    if(not_overlap_count == 0) {
        cout << bound_bl_x << " " << bound_bl_y << endl;
        return 0;
    }
    // delete second rectangle
    not_overlap_count = 0;
    for(auto index: area_index){
        int i = index.second;
        if(i==1) continue;
        if(!is_overlap(bl_x[i], bl_y[i], ur_x[i], ur_y[i], bound_bl_x, bound_bl_y, bound_ur_x, bound_ur_y)){
            not_overlap_count++;
            break;
        }
        if(bl_x[i] > bound_bl_x) bound_bl_x = bl_x[i];
        if(ur_x[i] < bound_ur_x) bound_ur_x = ur_x[i];
        if(bl_y[i] > bound_bl_y) bound_bl_y = bl_y[i];
        if(ur_y[i] < bound_ur_y) bound_ur_y = ur_y[i];
    }
    if(not_overlap_count == 0) {
        cout << bound_bl_x << " " << bound_bl_y << endl;
        return 0;
    }
    // not delete first rectangle
    not_overlap_count = 0;
    int not_overlap_index = -1;
    for(auto index: area_index){
        int i = index.second;
        if(!is_overlap(bl_x[i], bl_y[i], ur_x[i], ur_y[i], bound_bl_x, bound_bl_y, bound_ur_x, bound_ur_y)){
            not_overlap_count++;
            continue;
        }
        if(bl_x[i] > bound_bl_x) bound_bl_x = bl_x[i];
        if(ur_x[i] < bound_ur_x) bound_ur_x = ur_x[i];
        if(bl_y[i] > bound_bl_y) bound_bl_y = bl_y[i];
        if(ur_y[i] < bound_ur_y) bound_ur_y = ur_y[i];
    }
    if(not_overlap_count <= 1) {
        cout << bound_bl_x << " " << bound_bl_y << endl;
        return 0;
    }
    cout << -1 << " " << -1 << endl;
    return 0;
}