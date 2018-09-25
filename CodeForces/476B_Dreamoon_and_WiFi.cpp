#include<iostream>
#include<vector>
#include<math.h>

using namespace std;


long long nCr(int n, int r){
    long long result = 1;
    if(n-r > r){
        for(int i=n; i>n-r; i--){
            result *= i;
        }
        for(int i=r; i>1; i--){
            result /= i;
        }
    } else {
        for(int i=n; i>r; i--){
            result *= i;
        }
        for(int i=n-r; i>1; i--){
            result /= i;
        }
    }
    return result;
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    int plus_count = 0;
    int minus_count = 0;
    int blank_count = 0;
    for(int i=0; i<s1.size(); i++){
        if(s1[i]=='+') plus_count++;
        else if(s1[i]=='-') minus_count++;

        if(s2[i]=='+') plus_count--;
        else if(s2[i]=='-') minus_count--;
        else if(s2[i]=='?') blank_count++;
    }
    double result;
    if (blank_count == 0) {
        if(plus_count == 0 && minus_count == 0) result = 1;
        else result = 0;
    } else if (plus_count < 0 || minus_count < 0) {
        result = 0;
    } else {
        result = nCr(blank_count, plus_count)/pow(2, blank_count);
    }
    printf("%.16lf", result);
    return 0;
}