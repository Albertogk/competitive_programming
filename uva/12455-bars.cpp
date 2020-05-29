#include <iostream>

using namespace std;


bool solve(int n, int p, int bars[20], int value) {

    int aux, aux2;
    bool ret;
    if (value == n) {
        return true;
    }

    for (int i=0; i<p; i++) {
        if(bars[i] == -1) {
            continue;
        }

        aux = value + bars[i];
        aux2 = bars[i];
        bars[i] = -1;
        if (aux <= n) {
            ret = solve(n, p, bars, aux);
            if (ret) {
                return true;
            }
        }
        bars[i] = aux2;
    }
    return false;
}

int main() {
    int t, n, p;
    int bars[20];
    bool ret;

    cin >> t;

    for (int i=0; i<t; i++) {
        cin >> n >> p;
        for(int j=0; j<p; j++) {
            cin >> bars[j];
        }

        ret = solve(n, p, bars, 0);
        if (ret) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}

