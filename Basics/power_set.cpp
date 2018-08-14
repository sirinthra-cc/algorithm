#include<iostream>
#include<string>

using namespace std;


void generate_base_2(int digits, int count, string base2){
    if(count == digits) {
        cout << "{ ";
        for(int i=0; i<base2.size(); i++){
            if(base2[i] == '1') cout << (i+1) << " ";
        }
        cout << "}" << endl;
    }
    else {
        generate_base_2(digits, count + 1, base2 + '0');
        generate_base_2(digits, count + 1, base2 + '1');
    }
}


int main(){
    int digits = 3;
    generate_base_2(digits, 0, "");
    return 0;
}