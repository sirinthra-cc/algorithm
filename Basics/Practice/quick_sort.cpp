/* C implementation QuickSort */
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
 
// A utility function to swap two elements
void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}
 
int partition (std::vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low;
    for(int j=low; j<high; j++){
        if(arr[j] < pivot){
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[high]);
    return i;
}
 
void quickSort(std::vector<int> &arr, int low, int high)
{
    if(low < high){
        int mid = partition(arr, low, high);
        quickSort(arr, low, mid - 1);
        quickSort(arr, mid + 1, high);
    }
}
 
// Driver program to test above functions
int main()
{
    for(int testcase = 1; testcase <= 10; testcase++) {
        int n = rand() % 100000;
        std::vector<int> v;
        for(int i=0;i<n;i++) {
            v.push_back(rand());
        }
        std::vector<int> correctAnswer;
        for(int i=0;i<v.size();i++){
            correctAnswer.push_back(v[i]);
        }
        quickSort(v, 0, n-1);
        sort(correctAnswer.begin(), correctAnswer.end());
        for(int i=0;i<n;i++){
            if(correctAnswer[i] != v[i])
                printf("Wrong");
        }
        printf("Correct");
        //printArray(arr, n);
    }
    return 0;
}