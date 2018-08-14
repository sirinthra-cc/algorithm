#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<queue>

using namespace std;


void transform(string initial_s, string target, unordered_map<string, bool> &dict){
    unordered_map<string, bool> visited;
    unordered_map<string, string> to_from;
    if(initial_s == target){
        cout << initial_s << endl;
        return;
    } else if (initial_s.size() != target.size()){
        cout << "Cannot transform initial_s to target" << endl;
        return;
    }
    queue<string> q;
    q.push(initial_s);
    visited[initial_s] = true;
    bool found = false;
    while(!q.empty()){
        string s = q.front();
        q.pop();
        if(s == target) {
            found = true;
            break;
        }
        for(int i=0; i<initial_s.size(); i++){
            for(char c='A'; c<='Z'; c++){
                string new_s = s;
                new_s[i] = c;
                if(visited.find(new_s) == visited.end() && dict.find(new_s) != dict.end()){
                    q.push(new_s);
                    visited[new_s] = true;
                    to_from[new_s] = s;
                }
            }
        }
    }
    if(found){
        vector<string> result;
        string current_s = target;
        while(to_from[current_s] != initial_s){
            result.push_back(current_s);
            current_s = to_from[current_s];
        }
        cout << initial_s;
        for(int i=result.size()-1; i>=0; i--){
            cout << " -> " << result[i];
        }
    } else {
        cout << "Cannot transform initial_s to target" << endl;
        return;
    }
}