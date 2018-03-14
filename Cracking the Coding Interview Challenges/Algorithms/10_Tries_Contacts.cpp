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

void add_word(string contact, unordered_map<string, int> &word_count){
    for(int i=1; i<=contact.size(); i++){
        string sub_contact = contact.substr(0, i);
        if(word_count.find(sub_contact) == word_count.end()) word_count[sub_contact] = 1;
        else word_count[sub_contact] += 1;
    }
}

int main(){
    int n;
    cin >> n;
    unordered_map<string, int> word_count;
        
    for(int a0 = 0; a0 < n; a0++){
        string op;
        string contact;
        cin >> op >> contact;
        if(op == "add") add_word(contact, word_count);
        else if(word_count.find(contact) == word_count.end()) cout << 0 << endl;
        else cout << word_count[contact] << endl;
    }
    return 0;
}
