#include <iostream>
#include <cmath>


using namespace std;

int getNines(long long number) {
    int aux;
    int i=0;
    if (number %9 == 0) {
        return 1;
    }

    while (number != 0) { 
        aux = number / 10;
        if(number-(aux*10) == 9) {
            return 1;
        }
        number = aux;
    }

    return 0; 
}

int main() {
    int t;
    long long f, l, result, aux;

    cin >> t;

    for(int i=0; i < t; i++) {
        cin >> f >> l;
        result = l - f + 1;
        for(int j=f; j<=l; j++) {
            result -= getNines(j);
        }

        cout << "Case #" << i+1 << ": " << result << endl;
    }

    return 0;
}