#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> result;
    vector<bool> added_numbers(101);
    vector<int> nugget_numbers{6,9,20};
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int current_nugget_number = q.front();
        q.pop();
        for(int i=0; i<3; i++){
            int next_nugget_number = current_nugget_number + nugget_numbers[i];
            if(next_nugget_number <= n && !added_numbers[next_nugget_number]){
                added_numbers[next_nugget_number] = true;
                result.push_back(next_nugget_number);
                q.push(next_nugget_number);
            }
        }
    }
    if(result.size() == 0){
        cout << "no" << endl;
        return 0;
    }
    sort(result.begin(), result.end());
    for(auto r: result){
        cout << r << endl;
    }
    return 0;
}