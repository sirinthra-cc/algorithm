#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

void merge(std::vector<int> &arr, int low, int high){
    int mid = (low + high) / 2;
    int i = low;
    int j = mid + 1;
    vector<int> new_arr;
    while(i <= mid && j <= high){
        if(arr[i] <= arr[j]) new_arr.push_back(arr[i++]);
        else new_arr.push_back(arr[j++]);
    }
    while(i <= mid) new_arr.push_back(arr[i++]);
    while(j <= high) new_arr.push_back(arr[j++]);
    for(int i=low; i<=high; i++){
        arr[i] = new_arr[i-low];
    }
}

void mergeSort(std::vector<int> &arr, int low, int high)
{
    if(low < high){
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, high);
    }
}

int main()
{
    for(int testcase = 1; testcase <= 100; testcase++) {
        int n = rand() % 100000;
        std::vector<int> v;
        for(int i=0;i<n;i++) {
            v.push_back(rand());
        }
        std::vector<int> correctAnswer(v);
        mergeSort(v, 0, n-1);
        sort(correctAnswer.begin(), correctAnswer.end());
        int isCorrect = true;
        for(int i=0;i<n;i++) {
            if(correctAnswer[i] != v[i])
                isCorrect = false;
                
        }
        if(isCorrect) 
            printf("Correct\n");
        else
            printf("Wrong\n");
    }
    return 0;
}