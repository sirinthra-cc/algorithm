#include<iostream>

using namespace std;


int main(){
    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    int drink = k*l/nl;
    int lime = c*d;
    int salt = p/np;
    cout << min(drink, min(lime, salt))/n << endl;
    return 0;
}