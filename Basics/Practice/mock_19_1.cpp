A = [3,3,5,6,8, , , ]
B = [1,2,7]
result = [1,2,3,4,5,6,7,8]


vector<int> merge(vector<int> A, vector<int> B){
    int a_i = A.size() - B.size() - 1;
    int b_i = B.size() - 1;
    int back = A.size() - 1;
    while(back>=0 && a_i>=0 && b_i>=0){
        if(A[a_i]>B[b_i]) {
            A[back] = A[a_i];
            back--;
            a_i--;
        } else {
            A[back] = B[b_i];
            back--;
            b_i--;
        }
    }
    while(back>0){
        A[back] = B[b_i];
        b_i--;
        back--;
    }
    return A;
}
