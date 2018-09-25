#include<iostream>

using namespace std;


int main(){
    int i;
    string of, period;
    cin >> i >> of >> period;
    int result;
    if(period == "month"){
        if(i == 31) result = 7;
        else if(i > 29) result = 11;
        else result = 12;
    } else if(period == "week"){
        if(i == 5 || i == 6) result = 53;
        else result = 52;
    }
    cout << result << endl;
    return 0;
}