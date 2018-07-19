vector<int> mul(vector<int> A, vector<int> B){
    vector<int> result(A.size()+B.size());
    fill(result.begin(), result.end(), 0)
    for(int a=A.size()-1; a>=0; a--){
        for(int b=B.size()-1; b>=0; b--){
            int product = A[a] * B[b];
            result[B.size() + a] += product % 10;
            result[B.size() + a - 1] += product / 10;
        }
    }
    return result;
}
