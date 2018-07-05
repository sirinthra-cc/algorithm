#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;


int main(){
    int initial_number, target_number;
    cin >> initial_number >> target_number;
    queue<pair<int, int>> q;
    q.push(make_pair(initial_number, 0));
    int current_number, count;
    unordered_map<int, bool> visited;
    
    while(!q.empty()){
        current_number = q.front().first;
        count = q.front().second;
        q.pop();
        visited[current_number] = true;
        if(current_number == target_number) break;
        if(current_number < target_number && visited.find(current_number*2) ==  visited.end())
            q.push(make_pair(current_number*2, count+1));
        if(current_number > 0 && visited.find(current_number-1) ==  visited.end()) 
            q.push(make_pair(current_number-1, count+1));
    }
    cout << count << endl;
}