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


int main(){
    int p;
    cin >> p;
    vector<int> inputs(p);
    unordered_map<long, int> numbers;
    int max_num = 0;
    for(int i=0; i<p; i++){
        cin >> inputs[i];
        if(inputs[i]==2 || (inputs[i]>2 && inputs[i]%2!=0)) numbers[inputs[i]] = 1;
        if(inputs[i] > max_num) max_num = inputs[i];
    }
    for(int i=3; i<=ceil(sqrt(max_num)); i+=2){
        for(int j=0; j<p; j++){
            if(inputs[j] != i && inputs[j]%i == 0)
                numbers.erase(inputs[j]);
        }
    }
    for(int i=0; i<p; i++){
        if(numbers.find(inputs[i]) != numbers.end()) cout << "Prime" << endl;
        else cout << "Not prime" << endl;
    }
    return 0;
}
