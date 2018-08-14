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
 
// Return the index of the wanted number.
// Input is guaranteed to be sorted and the wanted number is guaranteed to be in the list.
// If multiple answers are found, return any.
int binarySearch(std::vector<int> &arr, int wantedNumber)
{
    int first = 0;
    int last = arr.size() - 1;
    int mid;
    while(first < last){
        mid = (first + last) / 2;
        if(wantedNumber <= arr[mid]) last = mid;
        else first = mid + 1;
    }
    if(arr[first] != wantedNumber) return -1;
    return first;
}

int main()
{
    for(int testcase = 1; testcase <= 100; testcase++) {
        int n = rand() % 100000;
        std::vector<int> v;
        for(int i=0;i<n;i++) {
            v.push_back(rand()%50000);
        }
        sort(v.begin(), v.end());
        int k = rand() % n;
        int wantedNumber = v[k];

        int answer = binarySearch(v, wantedNumber);

        if(wantedNumber != v[answer])
            printf("Wrong\n");
        else 
            printf("Correct\n");
    }
    return 0;
}