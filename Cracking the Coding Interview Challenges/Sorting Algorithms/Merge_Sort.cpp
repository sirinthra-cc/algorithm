#include <iostream>
#include <vector>

using namespace std;

vector<int> merge_sorted_lists(vector<int> vec1, vector<int> vec2){
    int ptr1 = 0;
    int ptr2 = 0;
    vector<int> results;
    while(ptr1 < vec1.size() && ptr2 < vec2.size()){
        if(vec1[ptr1] > vec2[ptr2]) {
            results.push_back(vec2[ptr2]);
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
    return results;
}

vector<int> merge_sort(vector<int> &inputs, int start, int end){
    int size = end-start;
    if(size == 1) {
        vector<int> result;
        result.push_back(inputs[start]);
        return result;
    } else if(size <= 0) {
        vector<int> result;
        return result;
    }  
    int mid = start + (size+1)/2;
    
    return merge_sorted_lists(merge_sort(inputs, start, mid), merge_sort(inputs, mid, end));
}

int main(){
    int n;
    cin >> n;
    vector<int> inputs(n);
    for(int i=0; i<n; i++){
        cin >> inputs[i];
    }
    vector<int> answer = merge_sort(inputs, 0, inputs.size());
    for(auto x: answer){
        cout << x << " ";
    }
    return 0;
}