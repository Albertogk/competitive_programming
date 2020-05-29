#include <iostream>

using namespace std;

int main() {
    int n, cnt = 0;
    int aux;
    int given = 0, treat = 0;

    while (true) {
        cin >> n;
        cnt++;
        if (n == 0) {
            break;
        }
        given = 0;
        treat = 0;
        for (int i=0; i < n; i++) {
            cin >> aux;
            if (aux == 0) {
                given++;
            }
            else {
                treat++;
            }
        }

        cout << "Case " << cnt << ": " << treat-given << endl;

    }
}