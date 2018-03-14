#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    priority_queue<int> max_heap;
    priority_queue<int> min_heap;
    double med = -1;
    for(int i=0; i<n; i++){
        cin >> a[i];
        if(med == -1) med = a[i];
        
        if(a[i] <= med) max_heap.push(a[i]);
        else min_heap.push(-a[i]);
        if(int(max_heap.size()) - int(min_heap.size()) > 1) {
            min_heap.push(-max_heap.top());
            max_heap.pop();
            med = (-min_heap.top() + max_heap.top())*1.0 / 2;
        } else if(int(min_heap.size()) - int(max_heap.size()) > 1) {
            max_heap.push(-min_heap.top());
            min_heap.pop();
            med = (-min_heap.top() + max_heap.top())*1.0 / 2;
        } else if(int(max_heap.size()) - int(min_heap.size()) == 1) {
            med = max_heap.top();
        } else if(int(min_heap.size()) - int(max_heap.size()) == 1) {
            med = -min_heap.top();
        } else {
            med = (-min_heap.top() + max_heap.top())*1.0 / 2;
        }
        printf("%.1lf\n", med);
    }
    return 0;
}
