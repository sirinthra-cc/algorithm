#include<iostream>
#include<string>

using namespace std;


void generate_base_2(int digits, int count, string base2){
    if(count == digits) {
        cout << base2 << " ";
    }
    else {
        if(base2[base2.size()-1] != '0') generate_base_2(digits, count + 1, base2 + '0');
        generate_base_2(digits, count + 1, base2 + '1');
    }
}


int main(){
    int digits = 4;
    generate_base_2(digits, 0, "");
    return 0;
}