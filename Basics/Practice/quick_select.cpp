/* C implementation quickSelect */
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
 
int quickSelect(std::vector<int> &arr, int low, int high, int K)
{
    if(low < high){
        int mid = partition(arr, low, high);
        if(mid == K) return arr[K];
        else if(K < mid) return quickSelect(arr, low, mid - 1, K);
        else return quickSelect(arr, mid + 1, high, K);
    } 
    return arr[low];
}
 
// Driver program to test above functions
int main()
{
    for(int testcase = 1; testcase <= 10; testcase++) {
        int n = rand() % 100000;
        int wanted_index = rand() % n;
        std::vector<int> v;
        for(int i=0;i<n;i++) {
            v.push_back(rand());
        }
        std::vector<int> v2;
        for(int i=0;i<v.size();i++){
            v2.push_back(v[i]);
        }
        int answer = quickSelect(v, 0, n-1, wanted_index);
        sort(v2.begin(), v2.end());
        if(v2[wanted_index] != answer) printf("Wrong");
        else printf("Correct");
        //printArray(arr, n);
    }
    return 0;
}