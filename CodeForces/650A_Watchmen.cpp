#include<map>
#include<set>
#include<iostream>

using namespace std;


int main(){
    int n;
    cin >> n;
    map<int, int> xs;
    map<int, int> ys;
    set<int> xset;
    set<int> yset;
    set<pair<int, int>> xyset;
    map<pair<int, int>, int> xys;
    
    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        pair<int, int> xy;
        xy = make_pair(x, y);
        xset.insert(x);
        yset.insert(y);
        xyset.insert(xy);

        if(xys.find(xy) == xys.end()){
            xys[xy] = 1;
        } else {
            xys[xy]++;
        }
        if(xs.find(x) == xs.end()){
            xs[x] = 1;
        } else {
            xs[x]++;
        }
        if(ys.find(y) == ys.end()){
            ys[y] = 1;
        } else {
            ys[y]++;
        }
    }

    long long count = 0;
    for(auto x: xset){
        count += (long long)xs[x] * (xs[x]-1) / 2;
    }
    // cout << count << endl;
    for(auto y: yset){
        count += (long long)ys[y] * (ys[y]-1) / 2;
    }
    // cout << count << endl;
    for(auto xy: xyset){
        count -= (long long)xys[xy] * (xys[xy]-1) / 2;
    }
    cout << count << endl;
}