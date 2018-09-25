#include<iostream>
#include<unordered_map>

using namespace std;


int main(){
    int n;
    cin >> n;
    int min = 1000000001;
    int max = 0;
    int max_count = 0;
    int min_count = 0;
    for(int i=0; i<n; i++){
        int b;
        cin >> b;
        if(b == min) min_count++;
        if(b == max) max_count++;
        if(b < min){
            min = b;
            min_count = 1;
        }
        if(b > max){
            max = b;
            max_count = 1;
        }
    }
    if(min == max) cout << max - min << " " << (long long)min_count*(min_count - 1)/2 << endl;
    else cout << max - min << " " << (long long)min_count * (long long)max_count << endl;
    return 0;
}