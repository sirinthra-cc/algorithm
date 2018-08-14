/* C implementation mergeSort */
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
 
// A utility function to swap two elements
 
void merge(vector<int> &arr, int first, int last){
    int mid = (first + last) / 2;
    int i1 = first;
    int i2 = mid + 1;
    int ai = 0;
    vector<int> temp(last-first+1);
    while(i1 <= mid && i2 <= last){
        if(arr[i1] < arr[i2]){
            temp[ai] = arr[i1];
            i1++;
        } else {
            temp[ai] = arr[i2];
            i2++;
        }
        ai++;
    }
    while(i1<=mid){
        temp[ai] = arr[i1];
        i1++;
        ai++;
    }
    while(i2<=last){
        temp[ai] = arr[i2];
        i2++;
        ai++;
    }
    for(int i=0; i<temp.size(); i++){
        arr[first+i] = temp[i];
    }
}
 
void mergeSort(vector<int> &arr, int first, int last){
    if(last-first <= 0) return;
    int mid = (first+last)/2;
    mergeSort(arr, first, mid);
    mergeSort(arr, mid+1, last);
    merge(arr, first, last);
}
 
// Driver program to test above functions
int main(){
    for(int testcase = 1; testcase <= 100; testcase++) {
        int n = rand() % 100000;
        std::vector<int> v;
        for(int i=0;i<n;i++) {
            v.push_back(rand());
        }
        std::vector<int> correctAnswer;
        for(int i=0;i<v.size();i++){
            correctAnswer.push_back(v[i]);
        }
        mergeSort(v, 0, v.size()-1);
        sort(correctAnswer.begin(), correctAnswer.end());
        for(int i=0;i<n;i++){
            if(correctAnswer[i] != v[i]) {
                printf("Wrong\n");
                break;
            }
            //printf("%d\n", v[i]);
        }
        printf("Correct\n");
        //printArray(arr, n);
    }
    return 0;
}