#include <bits/stdc++.h>

using namespace std;

pair<vector<int>, long long> merge_sorted_lists(vector<int> vec1, vector<int> vec2, long long &count){
    int ptr1 = 0;
    int ptr2 = 0;
    vector<int> results;
    while(ptr1 < vec1.size() && ptr2 < vec2.size()){
        if(vec1[ptr1] > vec2[ptr2]) {
            results.push_back(vec2[ptr2]);
            count += vec1.size() - ptr1;
            ptr2++;
        } else {
            results.push_back(vec1[ptr1]);
            ptr1++;
        }
    }
    while(ptr1 < vec1.size()){
        results.push_back(vec1[ptr1]);
        ptr1++;
    }
    while(ptr2 < vec2.size()){
        results.push_back(vec2[ptr2]);
        ptr2++;
    }
    pair<vector<int>, long long> answer = make_pair(results, count); // results and count
    return answer;
}

pair<vector<int>, long long> merge_sort(vector<int> &inputs, int start, int end, long long &count){
    int size = end-start;
    if(size == 1) {
        vector<int> result;
        result.push_back(inputs[start]);
        return make_pair(result, count);
    } else if(size <= 0) {
        vector<int> result;
        return make_pair(result, count);
    }  
    int mid = start + (size+1)/2;
    return merge_sorted_lists(merge_sort(inputs, start, mid, count).first, merge_sort(inputs, mid, end, count).first, count);
}

long long countInversions(vector<int> &arr) {
    // Complete this function
    long long count = 0;
    return merge_sort(arr, 0, arr.size(), count).second;
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int arr_i = 0; arr_i < n; arr_i++){
           scanf("%d", &arr[arr_i]);
        }
        long long result = countInversions(arr);
        cout << result << endl;
    }
    return 0;
}
