#include<iostream>

using namespace std;


int main(){
    int n;
    cin >> n;
    int result;
    if(n < 10) result = n;
    else if(n < 190) {
        n -= 10;
        if(n%2 == 0) result = n/20 + 1;
        else { 
            n -= (n/20)*20; 
            result = n/2;
        }
    } else {
        n -= 190;
        if(n%3 == 0) result = n/300 + 1;
        else if(n%3 == 1) {
            n -= (n/300)*300;
            result = n/30;
        } else {
            n -= (n/300)*300;
            n -= (n/30)*30; 
            result = n/3;
        }
    }
    cout << result << endl;
    return 0;
}