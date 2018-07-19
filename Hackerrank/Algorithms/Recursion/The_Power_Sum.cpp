#include <bits/stdc++.h>

using namespace std;


void dfs(int X, int N, int max, int &count){
    if(X == 0){
        count++;
        return;
    }
    for(int i=1; i<=max; i++){
        int remaining = X-(int)pow(i, N);
        if(remaining >= 0){
            // cout << remaining << " " << i-1 << endl;
            dfs(remaining, N, i-1, count);
        }   
    }
}

// Complete the powerSum function below.
int powerSum(int X, int N) {
    int max = (int) pow(X, 1.0/N);
    int count = 0;
    dfs(X, N, max, count);
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int X;
    cin >> X;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int N;
    cin >> N;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = powerSum(X, N);

    fout << result << "\n";

    fout.close();

    return 0;
}
