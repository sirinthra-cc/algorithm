#include<iostream>
#include<unordered_map>

using namespace std;


int main(){
    int n, k;
    cin >> n >> k;
    unordered_map<int, int> ratings;
    for(int i=1; i<=n; i++){
        int rating;
        cin >> rating;
        ratings[rating] = i;
    }
    if(ratings.size() >= k) {
        cout << "YES" << endl;
        int i=0;
        for(auto rating: ratings){
            cout << rating.second << " ";
            i++;
            if(i == k) break;
        }
        cout << endl;
    } else cout << "NO" << endl;
    return 0;
}