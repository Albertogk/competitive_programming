#include <iostream>

using namespace std;

int main() {
    int t, n;
    long long d;
    long long routes[1000];

    cin >> t;

    for(int i=1; i<=t; i++) {
        cin >> n >> d;
        for(int j=0; j<n; j++) {
            cin >> routes[j];
        }
        long long limit = d;
        for(int j=n-1; j>=0; j--) {
            limit = (limit/routes[j]) * routes[j];
        }

        cout << "Case #" << i << ": " << limit << endl;
    }
}