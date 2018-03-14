#include <iostream>

using namespace std;

int fibonacci(int n) {
    // Complete the function.
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(n == 2) return 1;
    if(n == 3) return 2;
    return 2*fibonacci(n-2) + fibonacci(n-3);
}
int main() {
    int n;
    cin >> n;
    cout << fibonacci(n);
    return 0;
}
