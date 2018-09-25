#include<iostream>
#include<unordered_map>

using namespace std;


int main(){
    int n;
    cin >> n;
    unordered_map<int, int> coin_count;
    int max_f = 0;
    for(int i=0; i<n; i++){
        int coin;
        cin >> coin;
        if(coin_count.find(coin) == coin_count.end()) coin_count[coin] = 1;
        else coin_count[coin]++;
        if(coin_count[coin] > max_f){
            max_f = coin_count[coin];
        }
    }
    cout << max_f << endl;
    return 0;
}