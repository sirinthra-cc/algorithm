#include<iostream>
#include<string>

using namespace std;


void permutation(int digits, int count, string permuted){
    if(count == digits) {
        cout << permuted << " ";
    }
    else {
        for(int i=1; i<=digits; i++){
            if(permuted.find(to_string(i)) == -1) 
                permutation(digits, count + 1, permuted + to_string(i));
        }
    }
}


int main(){
    int digits = 5;
    permutation(digits, 0, "");
    cout << endl;
    return 0;
}