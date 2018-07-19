#include<vector>
#include<iostream>

using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> seq(n);
    for(int i=0; i<n; i++){
        cin >> seq[i];
    }

    vector<int> local_sum(n);
    local_sum[0] = seq[0];
    for(int i=1; i<n; i++){
        local_sum[i] = local_sum[i-1] + seq[i];
    }

    int max_sum = 0;
    int starti = -1;
    int endi = -1;
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(local_sum[i] - local_sum[j] > max_sum){
                max_sum = local_sum[i] - local_sum[j];
                starti = j+1;
                endi = i;
            }
        }
    }
    if(max_sum > 0){
        for(int i=starti; i<=endi; i++){
            cout << seq[i] << " ";
        }
        cout << endl << max_sum;
    } else {
        cout << "Empty sequence" << endl;
    }

    return 0;
}