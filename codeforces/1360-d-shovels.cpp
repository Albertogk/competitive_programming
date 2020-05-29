#include <iostream>
#include <cmath>

using namespace std;

long long solve (long long n, long long k) {
    const double raiz = sqrt(n);
    for (long long i = 1; i < raiz; i++) {
        if(n%i == 0 && n/i <= k) {
            return i;
        }
    }

    for (long long i = raiz; i > 0; i--) {
        if(n%i == 0 && i <= k) {
            return n/i;
        }
    }

    return -1;
}

int main() {
    int t;
    cin >> t;

    for (int i=0; i<t; i++) {
        long long k, n;
        cin >> n >> k;

        if (k >= n) {
            cout << 1 << endl;
        }
        else {
            cout << solve(n, k) << endl;
        }
    }
    return 0;
}