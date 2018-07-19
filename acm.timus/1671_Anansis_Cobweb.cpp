#include<vector>
#include<iostream>

using namespace std;


int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> threads(m+1);
    vector<int> set(n+1);
    for(int i=0; i<n+1; i++) set[i] = i;
    for(int i=1; i<=m ; i++){
        int v1, v2;
        cin >> v1 >> v2;
        threads[i] = make_pair(v1, v2);
    }
    int q;
    cin >> q;
    vector<int> threads_to_tear(q);
    vector<bool> to_tear(m+1);
    for(int i=0; i<q; i++){
        cin >> threads_to_tear[i];
        to_tear[threads_to_tear[i]] = true;
    } 
    int count = n;
    for(int i=1; i<=m; i++){
        if(!to_tear[i]){
            int v1 = threads[i].first;
            int v2 = threads[i].second;
            int root1 = v1;
            int root2 = v2;
            while(set[root1] != root1) root1 = set[root1];
            while(set[root2] != root2) root2 = set[root2];
            if(root1 != root2){
                count--;
                set[root1] = root2;
            }
        }
    }
    vector<int> result(q);
    for(int i=q-1; i>=0; i--){
        result[i] = count;
        int v1 = threads[threads_to_tear[i]].first;
        int v2 = threads[threads_to_tear[i]].second;
        int root1 = v1;
        int root2 = v2;
        while(set[root1] != root1) root1 = set[root1];
        while(set[root2] != root2) root2 = set[root2];
        if(root1 != root2){
            count--;
            set[root1] = root2;
        }
    }
    for(int i=0; i<q; i++){
        cout << result[i] << " ";
    }
}