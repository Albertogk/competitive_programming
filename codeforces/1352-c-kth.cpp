#include <iostream>

using namespace std;

int main() {
    int t, n, k;

    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n >> k;

        int numbers = n-1;
        long long suma = k;
        while (k >= n) {
            suma += k/n;
            k = k/n;
        }

        cout << suma << endl;
    }
}