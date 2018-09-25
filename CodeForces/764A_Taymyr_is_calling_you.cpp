#include<iostream>
#include<math.h>

using namespace std;


int get_lcm(int a, int b){
    int lcm = max(a, b);
    while(true){
        if(lcm % a == 0 && lcm % b == 0) break;
        else lcm++;
    }
    return lcm;
}

int main(){
    int n, m, z;
    cin >> n >> m >> z;
    int lcm = get_lcm(n, m);
    cout << z/lcm << endl;
    return 0;
}