#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;


int main(){
    int n_class, n_student;
    cin >> n_class >> n_student;
    vector<int> classes(1001);
    vector<bool> is_queued;
    vector<int> class_queue;
    for(int i=0; i<n_student; i++) {
        int sclass, sid;
        cin >> sclass >> sid;
        classes[sid] = sclass;
    }
    vector<queue<int>> q(n_class+1);
    int i=0;
    while(true){
        char operation;
        cin >> operation;
        if(operation == 'E'){
            int sid;
            cin >> sid;
            q[classes[sid]].push(sid);
            if(find(class_queue.begin()+i, class_queue.end(), classes[sid]) == class_queue.end())
                class_queue.push_back(classes[sid]);
        } else if (operation == 'D'){
            if(i >= class_queue.size()) {
                cout << "empty" << endl;
                continue;
            }
            int sclass = class_queue[i];
            cout << q[sclass].front() << endl;
            q[sclass].pop();
            if(q[sclass].empty()) i++;
        } else break;
    }
    cout << 0 << endl;
    return 0;
}