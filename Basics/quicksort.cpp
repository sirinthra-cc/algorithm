/* C implementation QuickSort */
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
 
// A utility function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (std::vector<int> &arr, int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = low;  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            swap(&arr[i], &arr[j]);
            i++;    // increment index of smaller element
        }
    }
    swap(&arr[i], &arr[high]);
    return (i);
}
 
/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(std::vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
        std::vector<int> correctAnswer(v);
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