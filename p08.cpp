// Copyright 2015 Joshua Rodriguez
#include <iostream>

using namespace std;

// Use recursion to return the number of loops it takes
// and only use a max of 9 loops
int caculate(int n, int loop=0) {
    if (n < 10 || loop == 9) {
        return loop;
    }
    int total = 1;
    while (n > 0) {
        int a = n % 10;
        n /= 10;
        total *= a;
    }
    cerr << "Total: " << total << " \tLoop:" << loop << endl;
    return caculate(total, loop + 1);
}

int main() {
    int n;
    while (cin >> n) {
        cout << n << " " << caculate(n) << endl;
    }
    return 0;
}
