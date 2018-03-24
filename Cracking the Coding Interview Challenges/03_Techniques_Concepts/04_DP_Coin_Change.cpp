#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

long long make_change(vector<int> coins, int money) {
    long long change_table[money+1];
    // Init change_table with 0
    for(int i=0; i<=money; i++){
        change_table[i] = 0;
    }
    vector<vector<long long>> solutions;
    solutions.resize(money+1); 
    for(int i=0; i<=money; i++){
        solutions[i].resize(coins.size());
    }

    for(int i=1; i<=money; i++){
        for(int j=0; j<coins.size(); j++){
            int remaining = i - coins[j];
            if(remaining == 0) {
                change_table[i] += 1;
                solutions[i][j] += 1;
            } else if (remaining > 0){
                for(int k=0; k<coins.size(); k++){
                    if(coins[k]<=coins[j]) {
                        // change_table[i] += solutions[remaining][k];
                        solutions[i][j] += solutions[remaining][k];
                    }
                }
                change_table[i] += solutions[i][j];
            }
            // cout << solutions[i][j] << '\t';
        }
        // cout << ": " << change_table[i] << endl;
    }
    return change_table[money];
}

int main(){
    int n;
    int m;
    cin >> n >> m;
    vector<int> coins(m);
    for(int coins_i = 0;coins_i < m;coins_i++){
       cin >> coins[coins_i];
    }
    cout << make_change(coins, n) << endl;
    return 0;
}
