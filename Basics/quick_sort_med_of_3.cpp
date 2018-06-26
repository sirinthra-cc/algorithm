#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> merge(vector<int> &v1, int pivot, vector<int> &v2){
    vector<int> result;
    for(auto v: v1) result.push_back(v);
    result.push_back(pivot);
    for(auto v: v2) result.push_back(v);
    return result;
}

vector<int> quick_sort(vector<int> array){
    if(array.size() <= 1) return array;
    vector<int> randoms;
    for(int i=0; i<3; i++) randoms.push_back(rand() % array.size());
    for(int i=0; i<2; i++)
        for(int j=i+1; j<3; j++)
            if(array[randoms[i]] > array[randoms[j]]){
                int t = randoms[i];
                randoms[i] = randoms[j];
                randoms[j] = t;
            }

    int pivot = randoms[1];
    // cout << pivot << endl;
    vector<int> v1;
    vector<int> v2;
    for(int i=0; i<array.size(); i++){
        if(i == pivot) continue;
        if(array[i] > array[pivot]) v2.push_back(array[i]);
        else v1.push_back(array[i]);
    }
    vector<int> temp1 = quick_sort(v1);
    vector<int> temp2 = quick_sort(v2);
    return merge(temp1, array[pivot], temp2);
}


int main(){
    int arr[1000];
    for(int i=0;i<1000;i++){
        arr[i] = rand() % 1000;
    }
    vector<int> array;
    for(int i=0; i<1000; i++) array.push_back(arr[i]);
    vector<int> result = quick_sort(array);
    for(int i=0; i<result.size()-1; i++){
        if(result[i] > result[i+1])
            cout << "Wrong";
        // cout << result[i] << "\t";
    }
    return 0;
}