#include<iostream>
#include<vector>

using namespace std;


int main(){
    int n;
    cin >> n;
    vector<vector<int>> square(n);
    for(int i=0; i<n; i++) square[i].resize(n);
    int sum = n*(n*n+1)/2;
    for(int i=0; i<n; i++){
        int count_i = 0;
        for(int j=0; j<n; j++){
            cin >> square[i][j];
            count_i += square[i][j];
        }
        if(count_i != sum) {
            cout << "No" << endl;
            return 0;
        }
    }
    for(int j=0; j<n; j++){
        int count_j = 0;
        for(int i=0; i<n; i++){
            count_j += square[i][j];
        }
        if(count_j != sum) {
            cout << "No" << endl;
            return 0;
        }
    }
    int count = 0;
    for(int i=0; i<n; i++){
        count += square[i][i];
    }
    if(count != sum) {
        cout << "No" << endl;
        return 0;
    }
    count = 0;
    for(int i=0; i<n; i++){
        count += square[i][n-1-i];
    }
    if(count != sum) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}
