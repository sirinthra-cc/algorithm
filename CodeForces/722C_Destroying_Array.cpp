#include<vector>
#include<iostream>

using namespace std;


int find_root(int current_index, vector<int> &parents){
    int root = current_index;
    while(root != parents[root]) root = parents[root];
    return root;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n+1);
    vector<int> destroy_indices(n+1);
    for(int i=1; i<=n; i++) cin >> arr[i];
    for(int i=1; i<=n; i++) cin >> destroy_indices[i];
    vector<long long> result;
    result.push_back(0);
    vector<int> parents(n+1);
    vector<long long> sum(n+1);
    vector<int> temp_arr(n+1);
    fill(temp_arr.begin(), temp_arr.end(), -1);
    for(int i=1; i<=n; i++) parents[i] = i;
    fill(sum.begin(), sum.end(), -1);
    long long max = 0;
    for(int i=n; i>1; i--){
        long long new_index = destroy_indices[i];
        long long new_number = (long long) arr[new_index];
        temp_arr[new_index] = new_number;
        long long new_sum;
        if(new_index-1 > 0 && temp_arr[new_index-1] != -1 && new_index+1 <= n && temp_arr[new_index+1] != -1){
            int root1 = find_root(new_index-1, parents);
            int root2 = find_root(new_index+1, parents);
            long long sum1 = sum[root1];
            long long sum2 = sum[root2];
            new_sum = sum1 + new_number + sum2;
            sum[root1] = new_sum;
            parents[new_index] = root1;
            parents[root2] = root1;
        } else if (new_index-1 > 0 && temp_arr[new_index-1] != -1){
            int root1 = find_root(new_index-1, parents);
            long long sum1 = sum[root1];
            new_sum = sum1 + new_number;
            sum[root1] = new_sum;
            parents[new_index] = root1;
        } else if (new_index+1 <= n && temp_arr[new_index+1] != -1){
            int root2 = find_root(new_index+1, parents);
            long long sum2 = sum[root2];
            new_sum = sum2 + new_number;
            sum[root2] = new_sum;
            parents[new_index] = root2;
        } else {
            new_sum = new_number;
            sum[new_index] = new_sum;
        }
        if(new_sum > max) max = new_sum;
        result.push_back(max);
    }
    for(int i=n-1; i>=0; i--){
        cout << result[i] << endl;
    }
    return 0;
}