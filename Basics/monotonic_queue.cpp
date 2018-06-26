#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

vector<int> min_in_window(vector<int> a, int window_size){
    vector<int> result;
    vector<pair<int,int>> monotonic_queue;
    monotonic_queue.push_back(make_pair(a[0], 0));
    int f_monotonic_queue = 0;
    int l_monotonic_queue = 0;
    int f = f_monotonic_queue;
    int l = l_monotonic_queue;
    int m;
    // push first window
    for(int i=1; i<window_size; i++){
        pair<int,int> new_pair = make_pair(a[i], i);
        int wanted_number = a[i];
        f = f_monotonic_queue;
        l = l_monotonic_queue;
        while(f<l){
            m = (f + l) / 2;
            if(monotonic_queue[m].first < wanted_number) f = m + 1;
            else l = m;
        }
        if (monotonic_queue[f].first < wanted_number) {
            monotonic_queue.push_back(new_pair);
            l_monotonic_queue++;
        }
        else monotonic_queue[f] = new_pair;
    }

    result.push_back(monotonic_queue[f_monotonic_queue].first);
    // move window
    for(int window=1; window <= a.size()-window_size; window++){
        for(int j=f_monotonic_queue; j<=l_monotonic_queue; j++) cout << monotonic_queue[j].first << " ";
        cout << endl;
        if(monotonic_queue[f_monotonic_queue].second < window) f_monotonic_queue++;
        
        int i = window + window_size - 1;
        pair<int,int> new_pair = make_pair(a[i], i);
        int wanted_number = a[i];
        f = f_monotonic_queue;
        l = l_monotonic_queue;
        while(f<l){
            m = (f + l) / 2;
            if(monotonic_queue[m].first < wanted_number) f = m + 1;
            else l = m;
        }
        if (monotonic_queue[f].first < wanted_number) {
            monotonic_queue.push_back(new_pair);
            l_monotonic_queue++;
        }
        else monotonic_queue[f] = new_pair;
        result.push_back(monotonic_queue[f_monotonic_queue].first);
    }
    return result;
}

int main(){
    int input[10] = {1, 3, 2, 5, 4, 7, 1, 2, 9, 6};
    vector<int> a;
    for(int i=0; i<10; i++) a.push_back(input[i]);
    int window_size = 4;
    vector<int> result = min_in_window(a, window_size);
    for(int i=0; i<result.size(); i++){
        cout << result[i] << "\t";
    }
}