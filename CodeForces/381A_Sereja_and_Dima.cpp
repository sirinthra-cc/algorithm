#include<iostream>
#include<vector>

using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> scores(n);
    for(int i=0; i<n; i++) cin >> scores[i];
    int i = 0;
    int j = n-1;
    int sereja_points = 0;
    int dima_points = 0;
    bool is_sereja_turn = true;
    while(i<=j){
        int score;
        if(scores[i] > scores[j]) score = scores[i++];
        else score = scores[j--];

        if(is_sereja_turn) sereja_points += score;
        else dima_points += score;
        is_sereja_turn = !is_sereja_turn;
    }
    cout << sereja_points << " " << dima_points << endl;
    return 0;
}