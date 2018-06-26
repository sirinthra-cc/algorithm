#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int quick_select(vector<int> array, int nth){
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
    vector<int> v1;
    vector<int> v2;
    for(int i=0; i<array.size(); i++){
        if(i == pivot) continue;
        if(array[i] > array[pivot]) v2.push_back(array[i]);
        else v1.push_back(array[i]);
    }
    int size = (int)v2.size();
    if(size == nth-1) return array[pivot];
    else if (size < nth-1) return quick_select(v1, nth-size-1);
    else return quick_select(v2, nth);
}


int main(){
    int arr[10] = {2,7,8,4,2,1,3,5,2,4};
    // for(int i=0;i<1000;i++){
    //     arr[i] = rand() % 1000;
    // }
    vector<int> array;
    for(int i=0; i<10; i++) array.push_back(arr[i]);
    cout << quick_select(array, 2) << endl;
    return 0;
}