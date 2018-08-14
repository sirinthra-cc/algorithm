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
 
// Return the K-th smallest number from arr.
// Handle boundary case as you see fit.
int quickSelect(std::vector<int> &arr, int K)
{
    int low = 0;
    int high = arr.size() - 1;
    int i;
    while(low < high){
        int pivot = arr[high];
        i = low;
        for(int j=i; j<high; j++){
            if(arr[j] < pivot){
                swap(arr[i], arr[j]);
                i++;
            }
        }
        swap(arr[i], arr[high]);
        if(K == i) return arr[i];
        else if (K < i) high = i-1;
        else low = i+1;
    }
    return arr[low];
}

int main()
{
    for(int testcase = 1; testcase <= 100; testcase++) {
        int n = rand() % 100000;
        int k = rand() % n;
        std::vector<int> v;
        for(int i=0;i<n;i++) {
            v.push_back(rand());
        }
        std::vector<int> sortedArray(v);

        sort(sortedArray.begin(), sortedArray.end());
        int correctAnswer = sortedArray[k];
        int answer = quickSelect(v, k);

        if(correctAnswer != answer)
            printf("Wrong\n");
        else 
            printf("Correct\n");
    }
    return 0;
}