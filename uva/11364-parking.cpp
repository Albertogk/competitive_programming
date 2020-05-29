#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t, n;
    int stores[20];

    cin >> t;

    for(int i=0; i<t; i++) {
        cin >> n;
        for(int j=0; j<n; j++) {
            cin >> stores[j];
        }

        sort(stores, stores+n);
        int output = 0;

        for(int j=1; j<n; j++) {
            output += (stores[j] - stores[j-1]);
        }

        cout << output*2 << endl;
    }

    return 0;
}