#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;


int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> tasks(n);
    for(int i=0; i<n; i++){
        cin >> tasks[i];
    }
    sort(tasks.begin(), tasks.end());
    int time = 0;
    for(int i=n-1; i>=0; i-=k){
        time += tasks[i];
    }
    cout << time << endl;
    return 0;
}
