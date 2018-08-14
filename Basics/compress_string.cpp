#include<iostream>
#include<string>

using namespace std;


int main(int argc, char const *argv[])
{
    string a = "abc ";
    char previous = a[0];
    int count = 1;
    string result = "";
    for(int i=1; i<a.size(); i++){
        if(previous != a[i]){
            result += previous;
            result += (char)count + '0';
            previous = a[i];
            count = 1;
        } else {
            count++;
        }
    }
    if(result.size() >= a.size()) cout << a.substr(0, a.size()-1) << endl;
    else cout << result << endl;
    return 0;
}
