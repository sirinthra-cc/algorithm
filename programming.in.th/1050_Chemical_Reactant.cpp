#include<map>
#include<vector>
#include<iostream>

using namespace std;


int main(){
    int n, p;
    cin >> n >> p;
    map<vector<int>, int> substances;
    for(int i=1; i<=n; i++){
        vector<int> reactant(p);
        for(int j=0; j<p; j++){
            cin >> reactant[j];
        }
        substances[reactant] = i;
    }
    vector<int> target(p);
    for(int j=0; j<p; j++){
        cin >> target[j];
    }
    if(substances.find(target) != substances.end()) {
        cout << substances[target] << endl;
        return 0;
    }
    // search
    int result1 = -1, result2 = -1;
    for(auto s: substances){
        vector<int> s1 = s.first;
        vector<int> s2(p);
        for(int j=0; j<p; j++) s2[j] = target[j] - s1[j];
        if(substances.find(s2) != substances.end()){
            if(s.second != substances[s2]){
                result1 = s.second;
                result2 = substances[s2];
                break;
            }
        }
    }
    if(result1 == -1) cout << "NO" << endl;
    else if(result2 < result1) cout << result2 << " " << result1 << endl;
    else cout << result1 << " " << result2 << endl;
}
