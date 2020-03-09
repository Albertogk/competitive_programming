#include <iostream>

using namespace std;

int main() {
    int t, n, m;
    long long result, factorial;

    cin >> t;

    for(int i=0; i < t; i++) {
        cin >> n >> m;
        factorial = 1;
        for(int j=1; j<=2*n; j++) {
            factorial *= j;
            factorial %= 1000000007;
        }
        result = factorial;
        factorial /= 2*n;
        factorial /= 2*n-1;
        result -= (2*n-1)*2*factorial;
        for(int k=1; k<m; k++) {
            factorial /= 2*n-k-1;
            factorial /= 2*n-k-2;
            result -= k*(2*n-k*2-1)*4*factorial;
            result %= 1000000007;
        }

        cout << "Case #" << i+1 << ": " << result << endl;
    }
    return 0;
}