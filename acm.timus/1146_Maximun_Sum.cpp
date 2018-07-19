#include<iostream>
#include<vector>

using namespace std;


int main(){
    int n;
    cin >> n;
    vector<vector<int>> arr(n+1);
    arr[0].resize(n);
    vector<vector<int>> sum(n+1);
    sum[0].resize(n);
    for(int i=1; i<=n; i++){
        arr[i].resize(n+1);
        sum[i].resize(n+1);
        sum[i][0] = 0;
        for(int j=1; j<=n; j++){
            cin >> arr[i][j];
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + arr[i][j];
        }
    }
    int local_sum = 0;
    int max_sum = -10000000;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            for(int ii=0; ii<i; ii++){
                for(int jj=0; jj<j; jj++){
                    local_sum = sum[i][j] - sum[i][jj] - sum[ii][j] + sum[ii][jj];
                    if(local_sum > max_sum) max_sum = local_sum;
                }
            }
        }
    }
    cout << max_sum << endl;
    return 0;
}