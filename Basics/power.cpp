#include<iostream>
#include<math.h>
using namespace std;


double power(double a, int b){
    if(b == 1) return a;
    else if(b % 2 == 0){
        double result = power(a, b/2);
        return result * result;
    } else {
        double result = power(a, b/2);
        return result * result * a;
    }
}

int main(){
    //int a, b;
    //cin >> a >> b;
    for(int i=0;i<100;i++) {
        int a = rand() % 9 + 1;
        int b = rand() % 9 + 1;
        double result = power(a, b);
        double correct_answer = pow(a, b);
        if(abs(result - correct_answer) > 0.000001) {
            cout << "Wrong " << result << " " << correct_answer << endl;
        } else {
            cout << "Correct ^.^" << endl;
        }
    }
    return 0;
}