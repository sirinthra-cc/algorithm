#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int get_minimum_sum(vector<int> &arr){
    priority_queue<int> pq;
    for(int i=0; i<arr.size(); i++){
        pq.push(-arr[i]);
    }
    while(pq.size() > 1){
        int sum = 0;
        sum -= pq.top();
        pq.pop();
        sum -= pq.top();
        pq.pop();
        pq.push(-sum);
    }
    return -pq.top();
}