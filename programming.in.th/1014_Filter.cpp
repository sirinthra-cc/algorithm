#include<iostream>
#include<vector>

using namespace std;


int main(){
    int w, h, n;
    cin >> w >> h >> n; 
    vector<int> window(w);
    fill(window.begin(), window.end(), 0);
    for(int i=0; i<n; i++){
        int start, width;
        cin >> start >> width;
        int end = start + width;
        window[start]++;
        if(end < w) window[end]--;
    }
    int count = 0;
    int count_100 = 0;
    int count_50 = 0;
    for(int i=0; i<w; i++) {
        count += window[i];
        if(count <= 0) count_100++;
        else if(count == 1) count_50++;
    }
    cout << count_100*h << " " << count_50 << endl;
    return 0;
}