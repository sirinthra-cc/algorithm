#include<iostream>
#include<unordered_map>

using namespace std;


int main(){
    int len;
    cin >> len;
    string s;
    cin >> s;
    unordered_map<string, int> two_grams;
    int max_f = 0;
    string result;
    for(int i=0; i<len-1; i++){
        string gram = s.substr(i, 2);
        if(two_grams.find(gram) == two_grams.end()) {
            two_grams[gram] = 1;
        } else {
            two_grams[gram]++;
        }
        if(two_grams[gram] > max_f){
            max_f = two_grams[gram];
            result = gram;
        }
    }
    cout << result << endl;
    return 0;
}