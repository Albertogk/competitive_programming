#include <iostream>

using namespace std;

int main() {
    int t, aux, min, max, mid;

    cin >> t;
    for(int i=0; i < t; i++) {

        cin >> aux;
        min = aux;
        max = aux;

        cin >> aux;

        if (aux < min) {
            min = aux;
        }

        else if (aux > max) {
            max = aux;
        }

        cin >> aux;

        if (aux < min) {
            mid = min;
        }
        else if (aux > max) {
            mid = max;
        }

        else {
            mid = aux;
        }

        cout << "Case " << i+1 << ": " << mid << endl;
    }
}