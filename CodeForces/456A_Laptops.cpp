#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main(){
    int n;
    cin >> n;
    vector<vector<int>> laptops(n);

    for(int i=0; i<n; i++){
        laptops[i].resize(2);
        cin >> laptops[i][0] >> laptops[i][1];
    }
    sort(laptops.begin(), laptops.end());

    for(int i=1; i<n; i++){
        if(laptops[i-1][0] < laptops[i][0] && laptops[i-1][1] > laptops[i][1]){
            cout << "Happy Alex" << endl;
            return 0;
        }
    }
    cout << "Poor Alex" << endl;
    return 0;
}