#include<iostream>

using namespace std;


int main(){
    int n;
    long long x;
    cin >> n >> x;
    int distress_count = 0;
    for(int i=0; i<n; i++){
        char c;
        int d;
        cin >> c >> d;
        if(c == '+') x += d;
        else {
            if(x - d >= 0) x -= d;
            else distress_count++;
        }
    }
    cout << x << " " << distress_count << endl;
    return 0;
}