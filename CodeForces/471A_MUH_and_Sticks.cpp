#include<iostream>
#include<vector>

using namespace std;


int main()
{
    vector<int> len(10);
    fill(len.begin(), len.end(), 0);
    int l;
    for(int i=0; i<6; i++){
        cin >> l;
        len[l]++;
    }
    bool is_alien = true;
    bool is_elephant = false;
    for(int i=1; i<10; i++){
        if(len[i] >= 4) is_alien = false;
        if(len[i] == 2 || len[i] == 6) is_elephant = true;
    }
    if(is_alien) cout << "Alien" << endl;
    else if(is_elephant) cout << "Elephant" << endl;
    else cout << "Bear" << endl;
    return 0;
}
