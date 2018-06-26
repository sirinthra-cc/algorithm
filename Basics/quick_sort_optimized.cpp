#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void swap(vector<int> &a, int i, int j){
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}

void quick_sort(vector<int> &array, int first, int last){
    int size = last - first + 1;
    if(size <= 1) return;
    vector<int> randoms;
    for(int i=0; i<3; i++) randoms.push_back(rand() % size + first);
    for(int i=0; i<2; i++)
        for(int j=i+1; j<3; j++)
            if(array[randoms[i]] > array[randoms[j]]) swap(randoms, i, j);

    int pivot = randoms[1];
    int pivot_value = array[pivot];
    // cout << pivot_value << endl;
    int i = first + 1;
    int j = last;
    // Move pivot to array[first]
    // cout << "first " << first << " " << pivot_value << endl;
    swap(array, pivot, first);
    // cout << "before while" << " ";
    // for(auto a: array) cout << a << " ";
    // cout << endl;
    while(i < j){
        // cout << "X " << i << " " << j << endl;
        // cout << "Value " << array[i] << " " << array[j] << endl;
        if(array[i] > pivot_value && array[j] <= pivot_value){
            // cout << "Swapping" << endl;
            swap(array, i, j);
        }
        if(array[i] <= pivot_value) i++;
        else if(array[j] > pivot_value) j--;
    }
    // Move pivot back
    // pivot = i;
    if(array[i] <= pivot_value) pivot = i;
    else pivot = i - 1;
    swap(array, first, pivot);
    
    // cout << "after while" << " ";
    // for(auto a: array) cout << a << " ";
    // cout << endl;
    quick_sort(array, first, pivot-1);
    quick_sort(array, pivot+1, last);
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
    quick_sort(array, 0, array.size()-1);
    for(int i=0; i<array.size()-1; i++){
        if(array[i] > array[i+1])
            cout << "Wrong";
        // cout << array[i] << " ";
    }
    return 0;
}