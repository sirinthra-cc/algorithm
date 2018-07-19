#include<unordered_map>
#include<vector>
#include<iostream>

using namespace std;


int main(){
    int n;
    cin >> n;
    long long sum = 0;
    long long sum1 = 0;
    long long sum2 = 0;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        sum += a;
    }
    for(int i=0; i<n-1; i++){
        int a;
        cin >> a;
        sum1 += a;
    }
    for(int i=0; i<n-2; i++){
        int a;
        cin >> a;
        sum2 += a;
    }
    cout << sum - sum1 << endl;
    cout << sum1 - sum2 << endl;
}
