#include<iostream>
#include<vector>

using namespace std;

vector<int> bin(1000000);

vector<int> counting_sort(vector<int> &a){
    vector<int> result;
    // for(int i=0; i<bin.size(); i++) bin[i] = 0;
    fill(bin.begin(), bin.end(), 0);
    for(int i=0; i<a.size(); i++){
        bin[a[i]]++;
    }
    // for(int i=0; i<bin.size(); i++) cout << bin[i] << " ";
    for(int i=0; i<bin.size(); i++){
        while(bin[i] > 0){
            result.push_back(i);
            bin[i]--;
        }
    }
    return result;
}

int main(){
    // int arr[10] = {2,6,5,3,6,8,5,3,5,6};
    // int arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int arr[1000];
    for(int i=0;i<1000;i++){
        arr[i] = rand() % 1000000;
    }
    vector<int> array;
    for(int i=0; i<1000; i++) array.push_back(arr[i]);
    vector<int> result = counting_sort(array);
    for(int i=0; i<result.size()-1; i++){
        if(result[i] > result[i+1])
            cout << "Wrong";
        // cout << result[i] << " ";
    }
    return 0;
}