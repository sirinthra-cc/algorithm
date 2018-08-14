#include<iostream>
#include<string>

using namespace std;

int mem[105][105][15][15];
int generate_base_2(int &digit0, int &digit1, int count0, int count1, string base2, int count_0, int count_1, 
        int &k0, int &k1){
    if(count0 == digit0 && count1 == digit1) {
        //cout << base2 << " ";
        return 1;
    }
    else {
        int c0 = 0;
        int c1 = 0;
        if(count0 < digit0 && count_0 < k0) 
            c0 = generate_base_2(digit0, digit1, count0 + 1, count1, base2 + '0', count_0 + 1, 0, k0, k1);
        if(count1 < digit1 && count_1 < k1) 
            c1 = generate_base_2(digit0, digit1, count0, count1 + 1, base2 + '1', 0, count_1 + 1, k0, k1);
        return c0 + c1;
    }
}

int main(){
    for(int i=0;i<105;i++){
        for(int j=0;j<105;j++){
            for(int k=0;k<15;k++){
                for(int l=0;l<15;l++){
                    mem[i][j][k][l] = -1;
                }
            }
        }
    }
    int digit0 = 3;
    int digit1 = 2;
    int k0 = 2;
    int k1 = 1;
    int count = generate_base_2(digit0, digit1, 0, 0, "", 0, 0, k0, k1);
    cout << endl << count << endl;
    return 0;
}