#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
 
void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}
 
void quickSort(std::vector<int> &arr, int low, int high)
{
    if(low < high){
        int pivot = arr[high];
        int i = low;
        for(int j=i; j<high; j++){
            if(arr[j] < pivot) {
                swap(arr[i], arr[j]);
                i++;
            }
        }
        swap(arr[i], arr[high]);
        quickSort(arr, low, i-1);
        quickSort(arr, i+1, high);
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
        quickSort(v, 0, n-1);
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
        //printArray(arr, n);
    }
    return 0;
}