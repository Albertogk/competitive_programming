#include <iostream>
#include <bitset>

using namespace std;

int main() {
    int t, n, k;

    cin >> t;

    for (int i=0; i < t; i++) {
        cin >> n >> k;
        

        bitset<10> input;
        cin >> input;
        if (n == 1) {
            cout << 0 << endl;
            continue;
        }
        int sol = 1000000+1;
        for (int j=0; j<k; j++) {
            bitset<10> aux;
            for (int x=j; x < n; x=x+k) {
                aux[x] = 1;
            }
            cout << "Aaa " << aux << endl;
            aux ^= input;
            aux &= input;
            
            cout << "Bbb " << aux << endl;

            int aux2 = aux.count();
            if (aux2 < sol) {
                sol = aux2;
            }
        }

        cout << sol << endl;
    }
}