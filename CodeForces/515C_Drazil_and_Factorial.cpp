#include<iostream>
#include<vector>

using namespace std;


int main(){
    int n;
    cin >> n;
    vector<char> digits(n);
    vector<int> result(10);
    for(int i=0; i<n; i++) cin >> digits[i];
    for(int i=0; i<n; i++) {
        int digit = digits[i] - '0';
        while(digit > 1){
            if(digit == 4){
                result[2] += 2;
                digit--;
            } else if (digit == 6) {
                result[3] += 1;
                digit--;
            } else if (digit == 8) {
                result[2] += 3;
                digit--;
            } else if (digit == 9) {
                result[3] += 2;
                result[2] += 1;
                digit -= 2;
            } else {
                result[digit]++;
                digit = 0;
            }
        }
    }
    for(int i=9; i>1; i--){
        while(result[i] > 0){
            cout << i;
            result[i]--;
        }
    }
    cout << endl;
    return 0;
}