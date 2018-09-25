#include<iostream>
#include<vector>

using namespace std;


int main(){
    int n_cup = 0;
    int n_medal = 0;
    for(int i=0; i<3; i++){
        int a;
        cin >> a;
        n_cup += a;
    }
    for(int i=0; i<3; i++){
        int a;
        cin >> a;
        n_medal += a;
    }
    int n;
    cin >> n;
    int n_cubboard = 0;
    while(n_cup > 0) {
        n_cubboard++;
        n_cup -= 5;
    }
    while(n_medal > 0) {
        n_cubboard++;
        n_medal -= 10;
    }
    if(n_cubboard <= n) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}