#include<iostream>
#include<queue>
#include<vector>

using namespace std;

vector<queue<int>> bin(10);

vector<int> radix_sort(vector<int> &a){
    vector<int> result = a;
    // for(int i=0; i<bin.size(); i++) bin[i] = 0;
    // int max_digit = 0;
    // for(int i=0; i<a.size(); i++) 
        // if(a[i] > max_digit)
    bool has_next_digit = true;
    int digit = 1;
    int j = 0;
    while(j<10){
        has_next_digit = false;
        for(int i=0; i<result.size(); i++) {
            int digit_value = (result[i] % (digit*10)) / digit;
            // if(digit_value != 0) has_next_digit = true;
            bin[digit_value].push(result[i]);
        }
        // if(!has_next_digit) break;
        result.clear();
        // cout << "round: " << j << endl;
        for(int i=0; i<bin.size(); i++) {
            while(!bin[i].empty()){
                result.push_back(bin[i].front());
                // cout << bin[i].front() << " ";
                bin[i].pop();
            }
        }
        // cout << endl;
        digit *= 10;
        j++;
    }
    // for(int i=0; i<a.size(); i++)
    return result;
}

int main(){
    // int arr[10] = {2,6,5,3,6,8,5,3,5,6};
    // int arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int arr[1000];
    for(int i=0;i<1000;i++){
        arr[i] = rand() % 1000;
    }
    vector<int> array;
    for(int i=0; i<1000; i++) array.push_back(arr[i]);
    vector<int> result = radix_sort(array);
    for(int i=0; i<result.size()-1; i++){
        if(result[i] > result[i+1])
            cout << "Wrong";
        // cout << result[i] << " ";
    }
    return 0;
}